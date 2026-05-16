#include "ball.h"
using namespace std;

bool Ball::include_arene(){
    bool testx (Tools::test_range(ball.centre.x,ball.rayon,
                                  arena_size-ball.rayon,false));
    bool testy (Tools::test_range(ball.centre.y,ball.rayon,
                                  arena_size-ball.rayon,false));

    if((testx and testy)==false){

        return true;

    }else{

        return false;
    }
}


bool Ball::test_norme(){
    
    if (Tools::norme(dx,dy) > delta_norm_max){
        return true;
    }else{
        return false;
    }
}

void Ball::draw_ball(){

    Tools::draw_disk(ball,true);
}

void Ball::future_pos(){

    ball.centre.x += dx;
    ball.centre.y += dy;
}

void Ball::last_pos(){

    ball.centre.x -= dx;
    ball.centre.y -= dy;
}

void Ball::coll_ball_arene(){

    if(include_arene()==true){

        last_pos();
        //cout<<Tools::norme(dx,dy)<<endl;

        double paroi_proche_x = std::min(ball.centre.x,100-ball.centre.x);

        

        if((100-ball.centre.y)==paroi_proche_x){
            dx *= -1;
            dy *= -1;
        }else{
            ((100-ball.centre.y)>paroi_proche_x)?(dx *= -1):(dy *= -1);
        }
        
        future_pos();
        rebond++;
        //cout<<Tools::norme(dx,dy)<<endl;
    }
}

 void Ball::coll_ball(Ball& other){
    other.future_pos();
    if(Tools::intersects(ball, other.get_ball())){
        //last_pos();
        other.last_pos();
        std::cout<<Tools::norme(dx,dy)<<std::endl;
        double diff_x = ball.centre.x - other.get_ball().centre.x;
        double diff_y = ball.centre.y - other.get_ball().centre.y;
        Point diff(diff_x, diff_y);
        normalize(diff);

        double other_dx = other.get_dx();
        double other_dy = other.get_dy();
        double vnA = dx*diff.x + dy*diff.y;
        double vnB = other_dx * diff.x + other_dy * diff.y;
        double other_r_sq = other.get_ball().rayon * other.get_ball().rayon;
        double r_sq = ball.rayon * ball.rayon;
        double impulseA = (-vnA + vnB) * (2*other_r_sq)/(other_r_sq + r_sq);
        double impulseB = (-vnB + vnA) * (2*r_sq)/(other_r_sq + r_sq);

        dx += diff.x * impulseA;
        dy += diff.y * impulseA;
        other.set_dx(other_dx - diff.x*impulseB); 
        other.set_dy(other_dy - diff.y*impulseB); 
        Point deltaA(dx, dy);
        Point deltaB(other_dx, other_dy);
        
        clamp_deltas(deltaA, deltaB, other);
        std::cout<<Tools::norme(dx,dy)<<std::endl;
        future_pos();
        other.future_pos();
        rebond++;
    }else{
        other.last_pos();
    }
 }

void Ball::coll_brick(const Square& sq){

    last_pos();
    Point pt_proche(std::clamp(ball.centre.x,sq.centre.x-sq.size/2,sq.centre.x+sq.size/2),
                std::clamp(ball.centre.y,sq.centre.y-sq.size/2,sq.centre.y+sq.size/2));

    Point diff(ball.centre-sq.centre);
    Point diff_borne(pt_proche-sq.centre);

    Point dir_nom(diff-diff_borne);

    double delta_nom(Tools::norme(dir_nom.x,dir_nom.y));

    if(delta_nom>EPSIL_ZERO){
        dir_nom.x /= delta_nom;
        dir_nom.y /= delta_nom;

        double prod_scal(dx*dir_nom.x + dy*dir_nom.y);
        
        dx -= 2*prod_scal*dir_nom.x;
        dy -= 2*prod_scal*dir_nom.y;
        rebond++;
    }

    future_pos();
    

}

void Ball::normalize(Point& pt){
    double norm = sqrt(pt.x*pt.x + pt.y*pt.y);
    if (norm != 0){
        pt.x /= norm;
        pt.y /= norm;
    }
}

void Ball::clamp_deltas(Point& ptA, Point& ptB, Ball& other){

    double deltaA_norm = sqrt(ptA.x*ptA.x + ptA.y*ptA.y);
    double deltaB_norm = sqrt(ptB.x*ptB.x + ptB.y*ptB.y);

    if (deltaA_norm > delta_norm_max){
        normalize(ptA);
        dx = ptA.x*delta_norm_max;
        dy = ptA.y * delta_norm_max;
    }
    if (deltaB_norm > delta_norm_max){
        normalize(ptB);
        other.set_dx(ptB.x * delta_norm_max);  
        other.set_dy(ptB.y * delta_norm_max);
    }

}

void Ball::set_initial_pos(){

    initial_pos[0]=ball.centre.x;
    initial_pos[1]=ball.centre.y;
    initial_pos[2]=dx;
    initial_pos[3]=dy;
}

void Ball::back_initial_pos(){
    ball.centre.x=initial_pos[0];
    ball.centre.y=initial_pos[1];
    dx=initial_pos[2];
    dy=initial_pos[3];
}
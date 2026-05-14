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
        double paroi_proche_x = std::min(ball.centre.x,100-ball.centre.x);

        ((100-ball.centre.y)>paroi_proche_x)?(dx *= -1):(dy *= -1);

        if((100-ball.centre.y)==paroi_proche_x){
            dx *= -1;
            dy *= -1;
        }
        future_pos();
    }
}


#include "paddle.h"
using namespace std;

const Circle& Paddle::get_paddle() const{
    return paddle;
}

bool Paddle::inclusion_arene(){

    bool testx (Tools::test_range(paddle.centre.x,paddle.rayon,
                                  arena_size-paddle.rayon,false));
    
    bool testy (Tools::test_range(paddle.centre.y,-paddle.rayon,0,false));

      if((testx and testy)==false){

        return true;

    }else{

        return false;
    }
}

void Paddle::set_paddle_x()
{   
    double centre_y = paddle.centre.y;
    double offset = sqrt(paddle.rayon * paddle.rayon - centre_y*centre_y);

    double min_x = offset;
    double max_x = 100 - offset;

    if(follow_mouse <= min_x){
        paddle.centre.x = min_x;
    } 
    else if(follow_mouse >= max_x){
        paddle.centre.x = max_x;
    } 
    else{

        double delta = follow_mouse - paddle.centre.x;
        double max_step = delta_norm_max * dt;
        if (delta > max_step){
            delta = max_step;
        }    
        else if (delta < -max_step){
            delta = -max_step;

        }
        paddle.centre.x += delta;
        }
}
   
void Paddle::set_follow_mouse(double x){

    follow_mouse = x;
}

void Paddle::draw_paddle(){

    Tools::draw_disk(paddle,false);
}



#include "ball.h"
using namespace std;

void Ball::include_arene(){
   
    if (!Tools::test_range(ball.centre.x,ball.rayon, 100.0-ball.rayon,false)){

        Tools::error_message(message::ball_outside(ball.centre.x,ball.centre.y));
    }

    if ((ball.centre.y + ball.rayon > 100.0) or (ball.centre.y < 0.0)){

        Tools::error_message(message::ball_outside(ball.centre.x,ball.centre.y));
    }    
}



void Ball::test_norme(){
    
    if (Tools::norme(dx,dy) > delta_norm_max){
        Tools::error_message(message::invalid_delta(dx, dy));
    }
}


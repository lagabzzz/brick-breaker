#include "paddle.h"
using namespace std;

const Circle& Paddle::get_paddle() const{
    return paddle;
}

bool Paddle::inclusion_arene(){
    double centre_y = paddle.centre.y;
    double offset = paddle.rayon * paddle.rayon - centre_y * centre_y;
    if (offset < 0) return true;
    offset = sqrt(offset);
    double min_x = offset;
    double max_x = arena_size - offset;
    bool testx (Tools::test_range(paddle.centre.x,min_x, max_x,false));
    
    bool testy ((centre_y + paddle.rayon) > 0.0);

      if((testx and testy)==false){

        return true;

    }else{

        return false;
    }
}

void Paddle::set_paddle_x()
{      
    double centre_y = paddle.centre.y;
    double offset = sqrt(paddle.rayon * paddle.rayon - centre_y * centre_y);

    double min_x = offset;
    double max_x = 100 - offset;
    double target = std::clamp(follow_mouse, min_x, max_x);

    double delta = target - paddle.centre.x;

    delta = std::clamp(delta, -delta_norm_max, delta_norm_max);
    paddle.centre.x += delta;
    
}

   
void Paddle::set_follow_mouse(double x){

    follow_mouse = x;
}

void Paddle::draw_paddle(){

    Tools::draw_disk(paddle,false);
}


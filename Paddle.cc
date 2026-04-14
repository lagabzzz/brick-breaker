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

void Paddle::set_paddle_x(double x)
{   
    double centre_y = paddle.centre.y;
    double offset = sqrt(paddle.rayon * paddle.rayon - centre_y*centre_y);

    double min_x = offset;
    double max_x = 100 - offset;

    if(x <= min_x){
        paddle.centre.x = min_x;
    } 
    else if(x >= max_x){
        paddle.centre.x = max_x;
    } 
    else{
        paddle.centre.x = x;
    }
}
   

void Paddle::draw_paddle(){

    Tools::draw_disk(paddle,false);
}



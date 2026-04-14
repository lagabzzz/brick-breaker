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
    if(x <= paddle.rayon){
        paddle.centre.x = paddle.rayon;
    }
    else if(x >= 100 - paddle.rayon){
        paddle.centre.x = 100.0-paddle.rayon;
    }
    else{
        paddle.centre.x = x;
    }
   
}

void Paddle::draw_paddle(){

    Tools::draw_disk(paddle,false);
}



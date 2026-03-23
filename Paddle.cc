#include "paddle.h"
using namespace std;

void inclusion_arene(){

    if (!Tools::test_range(paddle.centre.x,paddle.rayon, 100.0-paddle.rayon,false)){

        Tools::error_message(message::paddle_outside(paddle.centre.x, paddle.centre.y))   
    }

    if ((paddle.centre.y > 0.0) or (paddle.centre.y + paddle.rayon < 0.0)){

       Tools::error_message(message::paddle_outside(paddle.centre.x, paddle.centre.y))     
    }
}

Const Circle& get_paddle() const{
    return paddle;
}

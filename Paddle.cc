#include "paddle.h"
using namespace std;

void inclusion_arene(Const Circle& paddle){

    if (!test_range(paddle.centre.x + paddle.rayon, 0.0, 100.0, false) 
        and !test_range(paddle.centre.x - paddle.rayon, 0.0, 100.0, false)){

        cout <<  paddle_outside(paddle.centre.x, paddle.centre.y) << endl;
        exit(0);
    }

    if (paddle.centre.y > 0.0){

        cout <<  paddle_outside(paddle.centre.x, paddle.centre.y) << endl;
        exit(0);
    }

    if (paddle.centre.y + paddle.rayon < 0.0){
        cout <<  paddle_outside(paddle.centre.x, paddle.centre.y) << endl;
        exit(0);
    }
}

Const Circle& paddle_getter() const{
    return paddle;
}
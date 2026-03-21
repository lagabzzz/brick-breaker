#include "ball.h"
using namespace std;

void include_arene(Const Circle& ball){
   
    if (!test_range(ball.centre.x + ball.rayon, 0.0, 100.0, false) 
        and !test_range(ball.centre.x - ball.rayon, 0.0, 100.0, false)){

        cout <<  ball_outside(ball.centre.x, ball.centre.y) << endl;
        exit(0);
    }

    if (ball.centre.y + ball.rayon > 100.0){

        cout << ball_outside(ball.centre.x, ball.centre.y) << endl;
        exit(0);

    }
    if ( ball.centre.y < 0.0){

        cout << ball_outside(ball.centre.x, ball.centre.y) << endl;
        exit(0);
    }  
    
}

Const Circle& get_ball() const{

    return ball;
}

void normes_delta(double dx,double dy){
    if (sqrt(dx*dx + dy*dy) > delta_norm_max){
        cout << invalid_delta(dx, dy) << endl;
        exit(0);
    }
}


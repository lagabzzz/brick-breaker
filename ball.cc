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


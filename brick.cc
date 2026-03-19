#include "brick.h"


void Brick :: test_val(){
    if((Tools::test_range(brick.size,brick_size_min,arena_size,false))==false){

        Tools::error_message(message::invalid_brick_size(brick.size));
    }

}

void Brick :: test_arene(){

    bool testx (Tools::test_range(brick.centre.x,0,arena_size,false);
    bool testy (Tools::test_range(brick.centre.y,0,arena_size,false);

    if((testx and testy)==false){

        Tools::error_message(message::invalid_brick_size(brick.size));
    }
}

void Rainbowbrick::test_hit_pt(){

    if(!(Tools::test_range(hit_points,1,7))){

        Tools::error_message(message::brick_outside(brick.centre.x, brick.centre.y));
    }
}

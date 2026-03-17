#include "brick.h"


void Brick :: test_val(){
    if((Tools::test_range(brick.size,brick_size_min,arena_size,false))==false){

        Tools::error_message(message::invalid_brick_size(brick.size));
    }

}

void Brick :: test_arene(){

    if((Tools::test_range(brick.x,0,arena_size,false) and Tools::test_range(brick.y,0,arena_size,false))==false){

        Tools::error_message(message::invalid_brick_size(brick.size));
    }
}

void Rainbowbrick::test_hit_pt(){

    if(!(Tools::test_range(hit_points,1,7))){

        Tools::error_message(message::brick_outside(brick.x, brick.y));
    }
}

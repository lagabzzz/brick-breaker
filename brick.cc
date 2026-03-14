#include "brick.h"


void Brick :: test(){
    if (!(Tools::test_range(brick.size,brick_size_min,arena_size,false))){

        Tools::error_message(message::invalid_brick_size(brick.size));
    }

}

void Rainbowbrick::test_hit_pt(){

    if(!(Tools::test_range(hit_points,0,7))){

        Tools::error_message(message::invalid_hit_points(hit_points));
    }
}

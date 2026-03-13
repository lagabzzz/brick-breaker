#include "brick.h"


void Brick :: test(){
    if (!(Tools::test_range(brick.size,brick_size_min,arena_size,false))){

        Tools::error_message(message::invalid_brick_size(brick.size));
    }

}
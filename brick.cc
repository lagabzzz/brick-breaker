#include "brick.h"


bool Brick :: test_val(){
    if((Tools::test_range(brick.size,brick_size_min,arena_size,false))==false){

        return true;
    }else{
        return false;
    }

}

bool Brick :: test_arene(){

    bool testx (Tools::test_range(brick.centre.x,brick.size/2,
                                  arena_size-brick.size/2,false));
    bool testy (Tools::test_range(brick.centre.y,brick.size/2,
                                  arena_size-brick.size/2,false));

    if((testx and testy)==false){

        return true;
    }else{
        return false;
    }
}

bool Brick::test_hit_pt(){

    if((Tools::test_range(hit_points,1,7))==false){

        return true;
    }else{
        return false;
    }
}

void Split_brick::find_hit_pts(){

    int new_pts(hit_points);
    double new_size((get_size()-split_brick_gap)/2);
    while(new_size > brick_size_min){
        new_size = (new_size-split_brick_gap)/2;
        new_pts++;
    }
    hit_points = new_pts;
}

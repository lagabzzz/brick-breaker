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


void Rainbowbrick::draw_brick()
{
    Tools::draw_square(brick,hit_points);
}

void Ball_brick::draw_brick(){

    Tools::draw_square(brick,hit_points);
    Circle ci(brick.centre.x,brick.centre.y,brick.size*20/100);
    Tools::draw_disk(ci,true);
}

void Split_brick::draw_brick(){

    draw_split(brick,hit_points,1);
}

void Split_brick::draw_split(const Square& sq,const int hit_pts,int count)
{
    Tools::draw_square(sq,count);

    if(count < hit_pts){
        double new_size((sq.size-split_brick_gap)/2);
        double delta_p((new_size+split_brick_gap)/2);
        Square s1(sq.centre.x-delta_p,sq.centre.y+delta_p,new_size);
        Square s2(sq.centre.x+delta_p,sq.centre.y+delta_p,new_size);
        Square s3(sq.centre.x+delta_p,sq.centre.y-delta_p,new_size);
        Square s4(sq.centre.x-delta_p,sq.centre.y-delta_p,new_size);

        draw_split(s1,hit_pts,count+1);
        draw_split(s2,hit_pts,count+1);
        draw_split(s3,hit_pts,count+1);
        draw_split(s4,hit_pts,count+1);
    }
}
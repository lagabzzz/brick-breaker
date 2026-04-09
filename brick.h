#ifndef BRICK_H
#define BRICK_H

#include "message.h"
#include "tools.h"
#include "constants.h"

enum  Type_brick{

    B_RAINBOW,
    B_BALL,
    B_SPLIT
};

class Brick {

public:
    
    Brick(Square brick)
    :brick(brick)
    {
        test_val(); 
        test_arene();
    }
    
    double get_x() const { return brick.centre.x; }
    double get_y() const { return brick.centre.y; }
    double get_size() const { return brick.size; }
    const Square& get_brick() const {return brick;}
    virtual ~Brick() = default;
    virtual int brick_type() = 0;
    virtual int get_hit_pts() = 0;


protected:
    Square brick;
    void test_val();
    void test_arene();
    int hit_points;
};

class Rainbowbrick : public Brick{

public:
    Rainbowbrick(Square brick,int hit_points)
    :Brick(brick),hit_points(hit_points)
    {test_hit_pt();}

    int get_hit_pts() const {return hit_points;}
    int brick_type() override {return B_RAINBOW;} 

private:
    
    void test_hit_pt();
};

class Ball_brick : public Brick{

public:
    Ball_brick(Square brick)
    :Brick(brick){}
    int brick_type() override {return B_BALL;}

private:
};

class Split_brick : public Brick{

public:
    Split_brick(Square brick)
    :Brick(brick){}
    int brick_type() override {return B_SPLIT;}

private:
};

#endif // BRICK_H
//bRICK
//C++17
//Jean-Michel Vellozzi
//Gabriel Plewinski

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
    
    Brick(Square brick,int hit_points = 1)
    :brick(brick),hit_points(hit_points)
    {}
    virtual ~Brick() = default;
    double get_x() const { return brick.centre.x; }
    double get_y() const { return brick.centre.y; }
    double get_size() const { return brick.size; }
    const Square& get_brick() const {return brick;}
    int get_hit_pts() const {return hit_points;}
    virtual int brick_type() = 0;
    bool test_hit_pt();
    bool test_val();
    bool test_arene();
    virtual void draw_brick() = 0;

protected:
    Square brick;
    int hit_points;
};

class Rainbowbrick : public Brick{

public:
    Rainbowbrick(Square brick,int hit_points)
    :Brick(brick,hit_points)
    {}

    int brick_type() override {return B_RAINBOW;}
    void draw_brick() override;

private:
    
};

class Ball_brick : public Brick{

public:
    Ball_brick(Square brick)
    :Brick(brick){}
    int brick_type() override {return B_BALL;}
    void draw_brick() override;
private:
};

class Split_brick : public Brick{

public:
    Split_brick(Square brick)
    :Brick(brick)
    {find_hit_pts();}

    int brick_type() override {return B_SPLIT;}
    void find_hit_pts();

    void draw_split(const Square& sq,const int hit_pts,int count);
    void draw_brick() override;

private:
};

#endif // BRICK_H
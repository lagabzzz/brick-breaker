#ifndef BRICK_H
#define BRICK_H

#include "message.h"
#include "tools.h"
#include "constants.h"

class Brick {
    public:
        
    Brick(Carre brick)
    :brick(brick)
    {test_val(); test_arene();}
    
    double get_x() const { return brick.centre.x; }
    double get_y() const { return brick.centre.y; }
    double get_size() const { return brick.size; }

    virtual ~Brick() = default;

    virtual void hit() = 0;
    double get_taille() const { return brick.size; }
    
    virtual ~Brick() = default;

    virtual void hit() = 0;
    
    protected:
    Carre brick;
    void test_val();
    void test_arene();
};

class Rainbowbrick : public Brick{

    public:
    Rainbowbrick(Const Carre& brick,int hit_points)
    :Brick(brick),hit_points(hit_points)
    {test_hit_pt();}

    
    private:
    int hit_points;
    void test_hit_pt();
};

class Ball_brick : public Brick{

    public:

    private:

};

class Split_brick : public Brick{

    public:

    private:
};

#endif // BRICK_H
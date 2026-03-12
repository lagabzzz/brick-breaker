#include "message.h"

class Brick {
    public:
        
    Brick(Carre brick)
    :brick(brick)
    {test_val}
    
    double get_x() const { return brick.get_x(); }
    double get_y() const { return brick.get_y(); }
    double get_taille() const { return brick.get_taille(); }
    void test_val();

    protected:
    Carre brick:

};

class Rainbowbrick : public Brick{

    public:

    private:

    int hit_points;
};

class Ball_brick : public Brick{

    public:

    private:

};

class Split_brick : public Brick{

    public:

    private:
};
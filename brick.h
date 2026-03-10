#include "tools.h"

class Brick {
    public:
        
    Brick(double taille, double x, double y) 
    :x(x), y(y), taille(taille)
    {}
    
    double get_x() const { return brick.centre.x; }
    double get_y() const { return brick.centre.y; }
    double get_taille() const { return brick.taille; }


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
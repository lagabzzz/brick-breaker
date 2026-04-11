#ifndef PADDLE_H
#define PADDLE_H

#include "tools.h"

class Paddle{
    
public:
    Paddle()=default;
    Paddle(double x, double y, double rayon)
    :paddle(x,y,rayon)
    {}

    double get_x() const { return paddle.centre.x; }
    double get_y() const { return paddle.centre.y; }
    void set_paddle_x(double x);
    const Circle& get_paddle() const;
    bool inclusion_arene();

private:
    Circle paddle;
};

#endif
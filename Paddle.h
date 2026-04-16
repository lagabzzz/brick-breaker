#ifndef PADDLE_H
#define PADDLE_H

#include "tools.h"
#include <cmath>
#include <algorithm>


class Paddle{
    
public:
    Paddle()=default;
    Paddle(double x, double y, double rayon)
    :paddle(x,y,rayon)
    {}

    double get_x() const { return paddle.centre.x; }
    double get_y() const { return paddle.centre.y; }
    double get_rayon() const { return paddle.rayon; }
    void set_follow_mouse(double x);
    void set_paddle_x();
    const Circle& get_paddle() const;
    bool inclusion_arene();
    void draw_paddle();


private:
    Circle paddle;
    double follow_mouse;
};

#endif
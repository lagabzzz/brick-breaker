#ifndef PADDLE_H
#define PADDLE_H

#include <cmath>
#include <algorithm>
#include "tools.h"

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
    double get_follow_mouse() const {return follow_mouse; }
    void set_paddle_x();
    void set_paddle_x(double futur_x) {paddle.centre.x = futur_x;}
    const Circle& get_paddle() const;
    bool inclusion_arene();
    void draw_paddle();


private:
    Circle paddle;
    double follow_mouse;
};

#endif

#ifndef BALL_H
#define BALL_H
#include "constants.h"
#include "tools.h"
#include <cmaths>

class Ball {
public:
    Ball(double x, double y, double rayon, double dx, double dy)
    : ball(x, y, rayon), dx(dx), dy(dy)
    {
        void include_arene(ball);
        void normes_delta(dx,dy);
    }
    Const Circle& getter_ball() const;

private:
    Circle ball; // Position and radius of the ball
    double dx, dy; // Velocity of the ball
    void include_arene(Const Circle& ball);
    void normes_delta(double dx, double dy);

/*
    void update() {
        x += dx;
        y += dy;
    }
*/

};

#endif // BALL_H

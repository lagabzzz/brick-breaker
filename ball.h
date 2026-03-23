
#ifndef BALL_H
#define BALL_H
#include "constants.h"
#include "tools.h"


class Ball {
public:
    Ball(double x, double y, double rayon, double dx, double dy)
    :ball(x, y, rayon), dx(dx), dy(dy)
    {
        void include_arene();
        void test_norme();
    }

    const Circle& get_ball() const{return ball;};
    double get_x() const { return ball.centre.x; }
    double get_y() const { return ball.centre.y; }
    double get_rayon() const { return ball.rayon; }

private:
    Circle ball; 
    double dx, dy;
    void include_arene();
    void test_norme();
};

#endif // BALL_H

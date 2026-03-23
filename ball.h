
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

    const Circle& get_ball() const;

private:
    Circle ball; 
    double dx, dy;
    void include_arene();
    void test_norme();
};

#endif // BALL_H

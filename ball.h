//ball
//Rendu 2
//Jean-Michel Vellozzi
//Gabriel Plewinski

#ifndef BALL_H
#define BALL_H
#include "constants.h"
#include "tools.h"


class Ball {
public:
    Ball(double x, double y, double rayon, double dx, double dy)
    :ball(x, y, rayon), dx(dx), dy(dy)
    {
        include_arene();
        test_norme();
    }

    const Circle& get_ball() const{return ball;};
    double get_x() const { return ball.centre.x; }
    double get_y() const { return ball.centre.y; }
    double get_rayon() const { return ball.rayon; }
    double get_dx() const { return dx; }
    double get_dy() const { return dy; }
    bool include_arene();
    bool test_norme();
    void draw_ball();

private:
    Circle ball; 
    double dx; 
    double dy;
    
};

#endif // BALL_H

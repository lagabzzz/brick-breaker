//ball
//Rendu 2
//Jean-Michel Vellozzi
//Gabriel Plewinski

#ifndef BALL_H
#define BALL_H

#include <algorithm>
#include "constants.h"
#include "tools.h"


class Ball {
public:
    Ball(double x, double y, double rayon, double dx, double dy)
    :ball(x, y, rayon), dx(dx), dy(dy)
    {
        //include_arene();
        //test_norme();
    }

    const Circle& get_ball() const{return ball;};
    double get_x() const { return ball.centre.x; }
    double get_y() const { return ball.centre.y; }
    double get_rayon() const { return ball.rayon; }
    double get_dx() const { return dx; }
    double get_dy() const { return dy; }
    void set_dx(double x){ dx = x; }
    void set_dy(double y){ dy = y; }
    bool include_arene();
    bool test_norme();
    void draw_ball();
    void future_pos();
    void last_pos();
    void coll_ball_arene();
    int get_rebond(){return rebond;}
    void set_rebond_to_zero(){rebond=0;}
    void coll_ball(Ball& other);
    void coll_brick(const Square& sq);
 
private:
    int rebond = 0;
    Circle ball; 
    double dx; 
    double dy;
    void normalize(Point& pt);
    void clamp_deltas(Point& ptA, Point ptB, Ball& other);
};

#endif // BALL_H

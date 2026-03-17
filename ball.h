
#ifndef BALL_H
#define BALL_H

class Ball {
public:
    Ball(double x, double y, double rayon, double dx, double dy)
    : ball(x, y, rayon), dx(dx), dy(dy)
    {}

private:
    Circle ball; // Position and radius of the ball
    double dx, dy; // Velocity of the ball
    

/*
    void update() {
        x += dx;
        y += dy;
    }
*/

};

#endif // BALL_H


#ifndef BALL_H
#define BALL_H

class Ball {
public:
    Ball(double x, double y, double rayon, double dx, double dy)
    : x(x), y(y), rayon(rayon), dx(dx), dy(dy)
    {}

private:
    double x, y; // Position of the ball
    double dx, dy; // Velocity of the ball
    double rayon; // Radius of the ball

/*
    void update() {
        x += dx;
        y += dy;
    }
*/

};

#endif // BALL_H

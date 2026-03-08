
#ifndef BALL_H
#define BALL_H

class Ball {
public:
    Ball(double x, double y, double dx, double dy, double rayon)
    : x(x), y(y), dx(dx), dy(dy), rayon(rayon)
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

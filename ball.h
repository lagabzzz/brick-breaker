
class Ball {
#ifndef BALL_H
#define BALL_H

class Ball {
public:
    Ball(double x, double y, double dx, double dy, double radius)
    : x(x), y(y), dx(dx), dy(dy), radius(radius)
    {}

private:
    double x, y; // Position of the ball
    double dx, dy; // Velocity of the ball
    double radius; // Radius of the ball

    void update() {
        x += dx;
        y += dy;
    }
};

#endif // BALL_H

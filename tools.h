#ifndef TOOLS_H
#define TOOLS_H

#include "message.h"
#include <iostream>
#include <cmath>
using namespace std;

struct Point {
  

    Point (double x, double y)
    :x(x),y(y)
    {}

    double x;
    double y;
};

struct Cicle : Point{

    Cercle (double x,double y,double rayon)
    :Point(x,y),rayon(rayon)
    {}

    double rayon;
};

struct Square : Point {


    Square (double x,double y,double size)
    :Point(x,y),size(size)
    {}

    double size;
};

constexpr double epsil_zero = 0.125

namespace Tools {
    bool test_range(double& size,double& lim_min,double& lim_max,bool with_epsil);
    void error_message(string message);
    double norme(double x, double y);

    double distance(double& p1x, double& p2x, double& p1y, double& p2y);
    bool intersects(Square& s1,Square& s2);
    bool intersects(Circle& c1,Circle& c2);
    bool intersects(Circle& c1,Square& s2);

}



#endif // TOOLS_H
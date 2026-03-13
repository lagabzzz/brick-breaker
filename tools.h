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

struct Cercle : Point{

    Cercle (Point centre,double rayon)
    :centre(centre),rayon(rayon)
    {}

    double rayon;
};

struct Carre : Point {


    Carre (Point centre,double size)
    :centre(centre),size(size)
    {}

    double size;
};

constexpr double epsil_zero = 0.125

namespace Tools {
    bool test_range(double size,double lim_min,double lim_max,bool with_epsil);
    void error_message(string message);
    double norme(double x, double y);
    double distance(Point p1, Point p2);
}

#endif // TOOLS_H
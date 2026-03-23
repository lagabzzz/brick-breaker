#ifndef TOOLS_H
#define TOOLS_H

#include "message.h"
#include <iostream>
#include <cmath>
using namespace std;

struct Point {
  
    Point()=default;
    Point (double x, double y)
    :x(x),y(y)
    {}

    double x;
    double y;
};

struct Circle {
    Circle()=default;
    Circle (double x,double y,double rayon)
    :centre(x,y),rayon(rayon)
    {}

    Point centre;
    double rayon;
};

struct Square {


    Square (double x,double y,double size)
    :centre(x,y),size(size)
    {}

    Point centre;
    double size;
};



namespace Tools {
    bool test_range(double val,double lim_min,double lim_max,bool with_epsil);
    bool test_range(int val,int lim_min,int lim_max);

    void error_message(string message);
    double norme(double x, double y);

    double distance(const Point& p1,const Point& p2);
    Point point_proche(const Point& ci,const Point& sq,double sq_size);
    bool intersects(const Square& s1,const Square& s2);
    bool intersects(const Circle& c1,const Circle& c2);
    bool intersects(const Circle& c1,const Square& s2);
    bool intersects(const Square& s2,const Circle& c1); //surcharge pour la commutativité

    constexpr double epsil_zero = 0.125;
}



#endif // TOOLS_H
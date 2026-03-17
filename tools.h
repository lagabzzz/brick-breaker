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
    :centre(x,y),rayon(rayon)
    {}

    Point centre;
    double rayon;
};

struct Square : Point {


    Square (double x,double y,double size)
    :centre(x,y),size(size)
    {}

    Point centre;
    double size;
};

constexpr double epsil_zero = 0.125;

namespace Tools {
    bool test_range(double& val,double& lim_min,double& lim_max,bool with_epsil);
    bool test_range(int& val,int& lim_min,int& lim_max);

    void error_message(string message);
    double norme(double& x, double& y);

    double distance(double& p1x, double& p2x, double& p1y, double& p2y);
    double pt_proche_1d(double& pt_ci,double& pt_sq,double& sq_size);
    bool intersects(Square& s1,Square& s2);
    bool intersects(Circle& c1,Circle& c2);
    bool intersects(Circle& c1,Square& s2);

}



#endif // TOOLS_H
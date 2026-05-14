//tools
//Rendu 2
//Jean-Michel Vellozzi
//Gabriel Plewinski

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include "graphic.h"
#include "message.h"
#include "constants.h"

constexpr double EPSIL_ZERO = 0.125;

struct Point {
  
    Point()=default;
    Point (double x, double y)
    :x(x),y(y)
    {}

    double x;
    double y;
    
    const Point operator+(const Point& pt);
    const Point operator-(const Point& pt);
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

    void error_message(std::string message);
    double norme(double x, double y);

    double distance(const Point& p1,const Point& p2);
    Point point_proche(const Point& ci,const Point& sq,double sq_size);
    bool intersects(const Square& s1,const Square& s2);
    bool intersects(const Circle& c1,const Circle& c2,bool with_epsil=true);
    bool intersects(const Circle& c1,const Square& s2,bool with_epsil=true);
    //surcharge commutativité
    bool intersects(const Square& s2,const Circle& c1,bool with_epsil=true);
     
    void draw_square(const Square& sq,const int hit_pts);
    void draw_disk(const Circle& sq, bool is_ball);
}

#endif // TOOLS_H
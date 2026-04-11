#include "tools.h"
using namespace std;

bool Tools:: test_range(double val, double lim_min,double lim_max, bool with_epsil){
    double epsil = (with_epsil)? epsil_zero:0;

    return ((lim_min+epsil <= val) and (val <= lim_max-epsil));
}

bool Tools::test_range(int val,int lim_min,int lim_max){

    return ((lim_min <= val) && (val <= lim_max));
}

void Tools::error_message(string message){
    cout << message << endl;
    has_error = true;
    return;
}  

double Tools::norme(double x,double y){
    return sqrt(x*x+y*y);
}

double Tools::distance(const Point& p1,const Point& p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


Point Tools::point_proche(const Point& ci,const Point& sq,double sq_size){

    Point pt_proche(0,0); //point du carre le plus proche du centre du cercle

    if(test_range(ci.x, sq.x-sq_size/2 ,sq.x+sq_size/2 ,false)){
        pt_proche.x = ci.x;
    }
    else{
        pt_proche.x = ((ci.x - sq.x)>0)? sq.x+sq_size/2 : sq.x-sq_size/2;
    }

    if(test_range(ci.y ,sq.y-sq_size/2 ,sq.y+sq_size/2 ,false)){
        pt_proche.y = ci.y;
    }
    else{
        pt_proche.y = ((ci.y - sq.y)>0)? sq.y+sq_size/2 : sq.y-sq_size/2;
    }

    return pt_proche;
}


bool Tools::intersects(const Square& s1,const Square& s2){

    double min_dist = (s1.size+s2.size)/2;

    return ((abs(s1.centre.x -s2.centre.x) < min_dist) and 
            (abs(s1.centre.y -s2.centre.y) < min_dist));
}

bool Tools::intersects(const Circle& c1,const Circle& c2){

    double dist = Tools::distance(c1.centre, c2.centre);
    return (dist <=(c1.rayon+c2.rayon));
}

bool Tools::intersects(const Circle& ci,const Square& sq){


   Point pt_proche = point_proche(ci.centre,sq.centre,sq.size);


   return (distance(pt_proche,ci.centre) <= ci.rayon);
}

bool Tools::intersects(const Square& s2,const Circle& c1){
    return Tools::intersects(c1,s2);
}

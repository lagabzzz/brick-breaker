#include "tools.h"

bool Tools:: test_range(double& val, double& lim_min,double& lim_max, bool with_epsil){
    double epsil = (with_epsil)? epsil_zero:0;

    return ( (lim_min+epsil <= val) and (val <= lim_max-epsil) );
}

bool Tools::test_range(int& val,int& lim_min,int& lim_max){

    return ( (lim_min <= val) and (val <= lim_max) );
}

void Tools:: error_message(string message){
    cout << message << endl;
    exit(0);
}  

double Tools::norme(double& x, double& y){
    return sqrt(x*x+y*y);
}

double Tools::distance(Point& p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


Point Tools::point_proche(Point& ci,Point& sq,double& sq_size){

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


bool Tools::intersects(Square& s1,Square& s2){

    double min_dist = (s1.size+s2.size)/2;

    return ((abs(s1.centre.x -s2.centre.x) <= min_dist) and (abs(s1.centre.y -s2.centre.y) <= min_dist));
}

bool Tools::intersects(Circle& c1,Circle& c2){

    double min_dist = Tools::distance(c1.centre, c2.centre);

    return (min_dist <=(c1.rayon+c2.rayon)/2);
}

bool Tools::intersects(Circle& ci,Square& sq){


   Point pt_proche = point_proche(ci.centre,sq.centre,sq.size);


   return ( distance(pt_proche,ci.centre) <= ci.rayon);
}

bool Tools::intersects(Square& s2,Circle& c1,){
    return Tools::intersects(c1,s2);
}

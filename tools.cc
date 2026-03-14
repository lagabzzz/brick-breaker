#include "tools.h"

bool Tools:: test_range(double& size, double& lim_min,double& lim_max, bool with_epsil){
    double epsil = (with_epsil)? epsil_zero:0;

    return ( (lim_min+epsil <= size) and (size <= lim_max-epsil) );
}

void Tools:: error_message(string message){
    cout << message << endl;
    exit(0);
}  

double Tools::norme(double& x, double& y){
    return sqrt(x*x+y*y);
}

double Tools::distance(double& p1x, double& p2x, double& p1y, double& p2y){
    return sqrt((p1x-p2x)*(p1x-p2x)+(p1y-p2y)*(p1y-p2y));
}

double pt_proche_1d(double& pt_ci,double& pt_sq,double& sq_size){

    double pt_proche; //point du carre le plus proche du cercle

    if(test_range(pt_ci ,pt_sq-sq_size/2 ,pt_sq+sq_size/2 ,false)){
        pt_proche = pt_ci
    }
    else{
        pt_proche = ((pt_ci - pt_sq)>0): pt_sq+sq_size/2 ? pt_sq-sq_size/2;
    }
    return pt_proche;
}


bool Tools::intersects(Square& s1,Square& s2){

    double min_dist = (s1.size+s2.size)/2;

    return ((abs(s1.x -s2.x) <= min_dist) and (abs(s1.y -s2.y) <= min_dist));
}

bool Tools::intersects(Circle& c1,Circle& c2){

    double min_dist = Tools::distance(c1.x, c2.x, c1.y, c2.y);

    return (min_dist <=(c1.rayon+c2.rayon)/2)
}



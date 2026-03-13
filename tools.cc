#include "tools.h"

bool Tools:: test_range(double size, double lim_min,double lim_max, bool with_epsil){
    double epsil = (with_epsil)? epsil_zero:0;

    return ( (lim_min+epsil <= size) and (size <= lim_max-epsil) );
}

void Tools:: error_message(string message){
    cout << message << endl;
    exit(0);
}  

double Tools::norme(double x, double y){
    return sqrt(x*x+y*y);
}
double Tools::distance(Point p1, Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

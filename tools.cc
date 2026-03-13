#include "tools.h"

bool Tools:: test_range(double size, double lim_min,double lim_max, bool with_epsil){
    double epsil = (with_epsil)? epsil_zero:0;
    
    return ( (lim_min+epsil <= size) and (size <= lim_max-epsil) );
}

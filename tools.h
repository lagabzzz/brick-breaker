#ifndef TOOLS_H
#define TOOLS_H

class Point {
    public:

    Point (double x, double y)
    :x(x),y(y)

    double get_x() const { return x; }
    double get_y() const { return y; } 

    protected:
    double x;
    double y;
};

class Cercle: public Point {

    public:
    Cercle (Point centre,double rayon)
    :centre(centre),rayon(rayon)
    {}
    double get_rayon() const{return rayon;}

    private:
    double rayon;
};

struct Carre : public Point {

    public:
    Carre (Point centre,double size)
    :centre(centre),size(size)
    {}
    double get_taille() const{return size;}
    
    private:
    double size;
};

constexpr double epsil_zero = 0.125

namespace Tools {
    bool test_range(double size,double lim_min,double lim_max,bool with_epsil);


}

#endif // TOOLS_H
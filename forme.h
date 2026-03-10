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
    Carre (Point centre,double taille)
    :centre(centre),taille(taille)
    {}
    double get_taille() const{return taille;}
    
    private:
    double taille;
};
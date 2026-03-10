class Point {
    public:

    Point (double x, double y)
    :x(x),y(y)

    protected:

    double x;
    double y;
};

class Cercle: public Point {

    Cercle (Point centre,double rayon)
    :centre(centre),rayon(rayon)
    {}

    double rayon;
};

struct Carre : public Point {

    Cercle (Point centre,double taille)
    :centre(centre),taille(taille)
    {}

    double taille;
};
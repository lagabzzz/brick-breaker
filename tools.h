struct Point {

    Point (double x, double y)
    :x(x),y(y)

    double x;
    double y;
};

struct Cercle {

    Cercle (Point centre,double rayon)
    :centre(centre),rayon(rayon)
    {}

    Point centre;
    double rayon;
};

struct Carre {

    Cercle (Point centre,double taille)
    :centre(centre),taille(taille)
    {}
    
    Point centre;
    double taille;
};
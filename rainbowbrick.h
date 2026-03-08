class RainbowBrick {
public:
    
    RainbowBrick(double taille, double x, double y, int hit_points) 
    :x(x), y(y), taille(taille), hit_points(hit_points) 
    {}
    
    double get_x() const { return x; }
    double get_y() const { return y; }
    double get_taille() const { return taille; }
    int get_hit_points() const { return hit_points; }
   
/*
    void hit() {
        if (hit_points > 0) {
            hit_points--;
        }
*/
    private:
        double x, y; // Position of the brick
        double taille; // Size of the brick
        int hit_points // Durability of the brick
};
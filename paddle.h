class Paddle {
public:
   
    Paddle(double startX, double startY, double r, double s) 
    : x(startX), y(startY), rayon(r), dx(0), dy(s) 
    {}
    
private:
    double x, y; // Position of the paddle
    double rayon; // Size of the paddle
    double dx, dy; // Velocity of the paddle

};
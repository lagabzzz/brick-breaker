#ifndef PADDLE_H
#define PADDLE_H


class Paddle{

    public:
      Paddle(double x, double y, double rayon)
      : x(x), y(y), rayon(rayon)
      {}

    private:
      double x;
      double y;
      double rayon;  

}

#endif
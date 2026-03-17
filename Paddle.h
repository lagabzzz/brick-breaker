#ifndef PADDLE_H
#define PADDLE_H

#include "tools.h"

class Paddle{

    public:
      Paddle(double x, double y, double rayon)
      :paddle(x,y,rayon)
      {}

    private:
      Circle paddle;  

};

#endif
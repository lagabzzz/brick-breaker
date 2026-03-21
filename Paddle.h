#ifndef PADDLE_H
#define PADDLE_H

#include "tools.h"

class Paddle{

    public:
      Paddle(double x, double y, double rayon)
      :paddle(x,y,rayon)
      {void inclusion_arene(paddle)}

      Const Circle& paddle_getter() const;

    private:
      Circle paddle;
      void inclusion_arene(Const Circle& paddle)  

    
};

#endif
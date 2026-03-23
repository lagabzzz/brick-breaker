#ifndef PADDLE_H
#define PADDLE_H

#include "tools.h"

class Paddle{
    public:
        Paddle(double x=0, double y=0, double rayon=0)
        :paddle(x,y,rayon)
        {inclusion_arene();}

        const Circle& get_paddle() const;

    private:
        Circle paddle;
        void inclusion_arene();
};

#endif
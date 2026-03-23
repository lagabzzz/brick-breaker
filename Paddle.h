#ifndef PADDLE_H
#define PADDLE_H

#include "tools.h"

class Paddle{
    public:
        Paddle()=default;
        Paddle(double x, double y, double rayon)
        :paddle(x,y,rayon)
        {inclusion_arene();}

        const Circle& get_paddle() const;

    private:
        Circle paddle;
        void inclusion_arene();
};

#endif
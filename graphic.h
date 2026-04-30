#ifndef GTKMM_EXAMPLE_GRAPHIC_H
#define GTKMM_EXAMPLE_GRAPHIC_H
#include <iostream>
#include <cmath>
#include "constants.h"

enum Color
{
    BLACK,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    CYAN,
    BLUE,
    PURPLE,
    GREY,
    WHITE,
};

namespace Graphic {
   
    
    
    void draw_contour();
    void clear_board();
    void draw_square(const double x,const double y,const double size,const int hit_pts);

    void draw_disk(const double x,const double y,const double rayon, bool is_ball);

    void set_color(int color);                                                    
};

#endif // GTKMM_EXAMPLE_GRAPHIC_H
#ifndef GTKMM_EXAMPLE_GRAPHIC_H
#define GTKMM_EXAMPLE_GRAPHIC_H
#include <iostream>

enum Color{

    NOIR,
    ROUGE,
    ORANGE,
    JAUNE,
    VERT,
    CYAN,
    BLEU,
    VIOLET
};

namespace Graphic {
   
    
    
    void draw_contour();
    void clear_board();
    void draw_square(const double x,const double y,const double size,const int hit_pts);

    void draw_disk(const double x,const double y,const double rayon, bool is_ball);

    void set_color(int color);                                                            
};

#endif // GTKMM_EXAMPLE_GRAPHIC_H
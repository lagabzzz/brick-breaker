#ifndef GTKMM_EXAMPLE_GRAPHIC_H
#define GTKMM_EXAMPLE_GRAPHIC_H

#include <giomm.h>
#include <gtkmm.h>
#include <iostream>
#include <cairomm/context.h>
#include "game.h"

using crptr = Cairo::RefPtr<Cairo::Context>;

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

class Graphic : public Gtk::DrawingArea {

public:
    Graphic(Game* gameptr = nullptr)
    :draw(true),
    gameptr(gameptr){}

    bool draw ; // current drawing state
    void on_draw(const crptr& cr, int width, int height);

private:
   
    Game* gameptr;

    // DrawingArea signal handler:

    void draw_contour(const crptr& cr, const int side);
    void draw_bricks(const crptr& cr, const int side);
    void draw_paddle(const crptr& cr, const int side);
    void draw_ball(const crptr& cr, const int side);

    void draw_rnb(const crptr& cr, const int side
,const Brick* brick);

    void draw_brball(const crptr& cr, const int side,const Brick* brick);

    void draw_split(const crptr& cr, const int side,const Brick* brick);                                                        

    void draw_square(const crptr& cr, const int side,const Square& sq);   
    
    void set_color(const crptr& cr,int color);                                                            
};

#endif // GTKMM_EXAMPLE_GRAPHIC_H
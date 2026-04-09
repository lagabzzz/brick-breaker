#ifndef GTKMM_EXAMPLE_GRAPHIC_H
#define GTKMM_EXAMPLE_GRAPHIC_H

#include <giomm.h>
#include <gtkmm.h>
#include <iostream>
#include <cairomm/context.h>
#include "game.h"

using crptr = Cairo::RefPtr<Cairo::Context>;


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

    void draw_contour(const crptr& cr, const int width, const int height);
    void draw_bricks(const crptr& cr, const int width, const int height);
    void draw_paddle(const crptr& cr, const int width, const int height);
    void draw_ball(const crptr& cr, const int width, const int height);

    void draw_square(const crptr& cr, const int width, const int height,Square sq);   
};

#endif // GTKMM_EXAMPLE_GRAPHIC_H
#ifndef GTKMM_EXAMPLE_GRAPHIC_H
#define GTKMM_EXAMPLE_GRAPHIC_H

#include <giomm.h>
#include <gtkmm.h>
#include <iostream>
#include <cairomm/context.h>
#include "game.h"




class Graphic : public Gtk::DrawingArea {

public:
   Graphic(Game* game_ptr = nullptr)
   :draw(true),
   game_ptr(game_ptr){}

   bool draw ; // current drawing state
   void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
   
private:
   
   Game* game_ptr;

   // DrawingArea signal handler:
   
   void graphic_draw_shape(const Cairo::RefPtr<Cairo::Context>& cr,
                                                   const int width,const int height);
};

#endif // GTKMM_EXAMPLE_GRAPHIC_H
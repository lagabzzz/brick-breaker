#include "graphic_gui.h"

static const Cairo::RefPtr<Cairo::Context>* ptcr(nullptr);

void graphic_set_context(const Cairo::RefPtr<Cairo::Context>& cr) {

   ptcr = &cr;
}

void graphic_draw_shape(const int width, const int height,int xc, int yc) {

   (*ptcr)->set_line_width(10.0);
   // draw red lines out from the center of the window
   (*ptcr)->set_source_rgb(0.8, 0.0, 0.0);
   (*ptcr)->move_to(0, 0);
   (*ptcr)->line_to(xc, yc);
   (*ptcr)->line_to(0, height);
   (*ptcr)->move_to(xc, yc);
   (*ptcr)->line_to(width, yc);
   (*ptcr)->stroke();
}
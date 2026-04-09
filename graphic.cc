#include "graphic.h"

void Graphic::on_draw(const Cairo::RefPtr<Cairo::Context>& cr
                                                            , int width, int height){

	if(draw)
	{      
      graphic_draw_shape(cr,width, height);
	}
}


void Graphic::graphic_draw_shape(const Cairo::RefPtr<Cairo::Context>& cr,
                                                   const int width, const int height){
   int xc, yc;
   xc = width / 2;
   yc = height / 2;

   cr->set_line_width(10.0);
   // draw red lines out from the center of the window
   cr->set_source_rgb(0.8, 0.0, 0.0);
   cr->move_to(0, 0);
   cr->line_to(xc, yc);
   cr->line_to(0, height);
   cr->move_to(xc, yc);
   cr->line_to(width, yc);
   cr->stroke();
}

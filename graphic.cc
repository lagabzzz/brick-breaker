#include "graphic.h"

void Graphic::on_draw(const crptr& cr, int width, int height){

	if(draw){
		  
		draw_contour(cr,width, height);
      draw_bricks(cr,width, height);
	}
}

void Graphic::draw_contour(const crptr& cr, const int width, const int height){
  
   cr->set_line_width(3.0);
   cr->set_source_rgb(0.5, 0.5, 0.5);
   cr->move_to(0, 0);
   cr->line_to(width, 0);
   cr->line_to(width, height);
   cr->line_to(0, height);
   cr->line_to(0, 0);
   cr->stroke();
}

void Graphic::draw_bricks(const crptr& cr, const int width, const int height){

   for(int i(0);i< gameptr->get_nb_bricks();i++){
	}
}

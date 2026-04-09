#include "graphic.h"

void Graphic::on_draw(const crptr& cr, int width, int height){

	if(draw){
		int side = std::min(width, height);

		draw_contour(cr,side);
      draw_bricks(cr,side);
	}
}

void Graphic::draw_contour(const crptr& cr, const int side){
  
   cr->set_line_width(3.0);
   cr->set_source_rgb(0.5, 0.5, 0.5);
   cr->move_to(0, 0);
   cr->line_to(side, 0);
   cr->line_to(side,side);
   cr->line_to(0, side);
   cr->line_to(0, 0);
   cr->stroke();
}

void Graphic::draw_bricks(const crptr& cr,const int side){

   for(int i(0);i< gameptr->get_nb_bricks();i++){
      
      switch(gameptr->get_brick(i)->brick_type()){

         case B_RAINBOW:   
            draw_rnb(cr,side,gameptr->get_brick(i));
            break;

         case B_BALL:
            
            break;
        
         case B_SPLIT:
            
            break;
      }      
	}
}

void Graphic::draw_rnb(const crptr& cr, const int side, const Brick* brick)
{
   set_color(cr,brick->get_hit_pts());

   draw_square(cr,side,brick->get_brick());
}

void Graphic::draw_square(const crptr& cr, const int side, const Square& sq)
{
   double px (side*sq.centre.x/100);
   double py (side*(1-sq.centre.x/100));
   double new_size(side*sq.size/100);
   cr->rectangle(px,py,new_size,new_size);
   cr->fill();
}                                                      


void Graphic::set_color(const crptr& cr,int color){

   switch(color){
      
      case NOIR:
         cr->set_source_rgb(0.0, 0.0, 0.0); break;
      case ROUGE:
         cr->set_source_rgb(1.0, 0.0, 0.0); break;
      case ORANGE:
         cr->set_source_rgb(1.0, 0.65, 0.0); break;
      case JAUNE:
         cr->set_source_rgb(1.0, 1.0, 0.0); break;
      case VERT:
         cr->set_source_rgb(0.0, 1.0, 0.0); break;
      case CYAN:
         cr->set_source_rgb(0.0, 1.0, 1.0); break;
      case BLEU:
         cr->set_source_rgb(0.0, 0.0, 1.0); break;
      case VIOLET:
         cr->set_source_rgb(0.5, 0.0, 0.5); break;
   }
}
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
      
      switch(gameptr->get_brick(i)->brick_type()){

         case B_RAINBOW:   
            draw_rnb(cr,width,height,gameptr->get_brick(i));
            break;

         case B_BALL:
            
            break;
        
         case B_SPLIT:
            
            break;
      }      
	}
}

void Graphic::draw_rnb(const crptr& cr, const int width, const int height
                                                        ,const Brick* brick)
{
   set_color(cr,brick->get_hit_pts());

   //draw_square(cr,widht,height,brick->get_brick());
   cr->rectangle(brick->get_x(),100-brick->get_y(),brick->get_size(),brick->get_size());
}



void Graphic::set_color(const crptr& cr,int color){

   switch(color){
      
      case NOIR:
         cr->set_source_rgb(0.0, 0.0, 0.0); break;
      case ROUGE:
         cr->set_source_rgb(1.0, 0.0, 0.0) break;
      case ORANGE:
         cr->set_source_rgb(1.0, 0.65, 0.0) break;
      case JAUNE:
         cr->set_source_rgb(1.0, 1.0, 0.0) break;
      case VERT:
         cr->set_source_rgb(0.0, 1.0, 0.0) break;
      case CYAN:
         cr->set_source_rgb(0.0, 1.0, 1.0) break;
      case BLEU:
         cr->set_source_rgb(0.0, 0.0, 1.0) break;
      case VIOLET:
         cr->set_source_rgb(0.5, 0.0, 0.5) break;
   }
}
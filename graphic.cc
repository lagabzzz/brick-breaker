#include "graphic.h"
#include "graphic_gui.h"

static const Cairo::RefPtr<Cairo::Context> *ptcr(nullptr);

// graphic_gui.h
void graphic_set_context(const Cairo::RefPtr<Cairo::Context> &cr)
{
    ptcr = &cr;
}

void Graphic::draw_contour(){
  
    (*ptcr)->set_line_width(arena_size/200);
    (*ptcr)->set_source_rgb(0.5, 0.5, 0.5);
    (*ptcr)->move_to(0, 0);
    (*ptcr)->line_to(arena_size, 0);
    (*ptcr)->line_to(arena_size,arena_size);
    (*ptcr)->line_to(0, arena_size);
    (*ptcr)->line_to(0, 0);
    (*ptcr)->stroke();
}

void Graphic::clear_board(){

    (*ptcr)->set_source_rgb(1.0, 1.0, 1.0);
    (*ptcr)->paint();
}
void Graphic::draw_square(const double x,const double y,const double size,const int hit_pts)
{

    double new_x(x-size/2);
    double new_y(y-size/2);
    set_color(hit_pts);
    (*ptcr)->rectangle(new_x,new_y,size,size);
    (*ptcr)->fill();
}

void Graphic::draw_disk(const double x,const double y,const double rayon,bool is_ball){

    set_color(NOIR);
    
    if (is_ball){
        (*ptcr)->arc(x,y,rayon,0.0,2*M_PI);
        (*ptcr)->fill();
    }
    else{
        (*ptcr)->arc(x,y,rayon,-std::asin(y/rayon),M_PI+std::asin(y/rayon));
        (*ptcr)->stroke();
    }
}


void Graphic::set_color(int color){

    switch(color){
        
        case NOIR:
            (*ptcr)->set_source_rgb(0.0, 0.0, 0.0); break;
        case ROUGE:
            (*ptcr)->set_source_rgb(1.0, 0.0, 0.0); break;
        case ORANGE:
            (*ptcr)->set_source_rgb(1.0, 0.65, 0.0); break;
        case JAUNE:
            (*ptcr)->set_source_rgb(1.0, 1.0, 0.0); break;
        case VERT:
            (*ptcr)->set_source_rgb(0.0, 1.0, 0.0); break;
        case CYAN:
            (*ptcr)->set_source_rgb(0.0, 1.0, 1.0); break;
        case BLEU:
            (*ptcr)->set_source_rgb(0.0, 0.0, 1.0); break;
        case VIOLET:
            (*ptcr)->set_source_rgb(0.5, 0.0, 0.5); break;
    }
}
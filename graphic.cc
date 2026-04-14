#include "graphic.h"
#include "graphic_gui.h"

static const Cairo::RefPtr<Cairo::Context> *ptcr(nullptr);
static int side(50);

// graphic_gui.h
void graphic_set_context(const Cairo::RefPtr<Cairo::Context> &cr,int l_side)
{
    ptcr = &cr;
    side = l_side;
}

void Graphic::draw_contour(){
  
    (*ptcr)->set_line_width(3.0);
    (*ptcr)->set_source_rgb(0.5, 0.5, 0.5);
    (*ptcr)->move_to(0, 0);
    (*ptcr)->line_to(side, 0);
    (*ptcr)->line_to(side,side);
    (*ptcr)->line_to(0, side);
    (*ptcr)->line_to(0, 0);
    (*ptcr)->stroke();
}

void Graphic::clear_board(){

    (*ptcr)->set_source_rgb(1.0, 1.0, 1.0);
    (*ptcr)->paint();
}
void Graphic::draw_square(const double x,const double y,const double size,const int hit_pts)
{

    double new_size(side*size/100);
    double new_x(side*x/100-new_size/2);
    double new_y(side*(1-y/100)-new_size/2);
    set_color(hit_pts);
    (*ptcr)->rectangle(new_x,new_y,new_size,new_size);
    (*ptcr)->fill();
}

void Graphic::draw_disk(const double x,const double y,const double rayon,bool is_ball){

    double new_size(side*rayon/100);
    double new_x(side*x/100);
    double new_y(side*(1-y/100));

    set_color(NOIR);
    (*ptcr)->arc(new_x,new_y,new_size,0.0,2*M_PI);
    if (is_ball){
        (*ptcr)->fill();
    }
    else{
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
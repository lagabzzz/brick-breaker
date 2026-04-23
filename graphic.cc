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

    set_color(BLACK);
    
    if (is_ball){
        (*ptcr)->arc(x,y,rayon,0.0,2*M_PI);
        (*ptcr)->fill();
    }
    else{
        (*ptcr)->arc(x,y,rayon,-std::asin(y/rayon),M_PI+std::asin(y/rayon));
        (*ptcr)->stroke();
    }
}


void Graphic::set_color(int color)
{
    double r(0.), g(0.), b(0.);

    switch (color)
    {
    case RED:
        r = 1.0;
        break;
    case ORANGE:
        r = 1.0;
        g = 0.5;
        break;
    case YELLOW:
        r = 1.0;
        g = 1.0;
        break;
    case GREEN:
        g = 1.0;
        break;
    case CYAN:
        g = 1.0;
        b = 1.0;
        break;
    case BLUE:
        b = 1.0;
        break;
    case PURPLE:
        r = 0.5;
        b = 1.0;
        break;
    case BLACK:
        r = g = b = 0.0;
        break;
    case GREY:
        r = g = b = 0.5;
        break;
    case WHITE:
        r = g = b = 1.0;
        break;
    default:
        break;
    }
    (*ptcr)->set_source_rgb(r, g, b);
}
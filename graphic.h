#ifndef GTKMM_EXAMPLE_GRAPHIC_H
#define GTKMM_EXAMPLE_GRAPHIC_H

#include <giomm.h>
#include <gtkmm.h>
#include <iostream>
#include <cairomm/context.h>
#include "game.h"

using crptr = Cairo::RefPtr<Cairo::Context>;

enum Color{

    NOIR,
    ROUGE,
    ORANGE,
    JAUNE,
    VERT,
    CYAN,
    BLEU,
    VIOLET
};

class Graphic : public Gtk::DrawingArea {

public:
    Graphic(Game* gameptr = nullptr)
    :draw(true),
    gameptr(gameptr){}

    std::string get_score_str(){return std::to_string(gameptr->get_score());}
    std::string get_lives_str(){return std::to_string(gameptr->get_lives());}
    std::string get_nb_bricks_str(){return std::to_string(gameptr->get_nb_bricks());}
    std::string get_nb_balls_str(){return std::to_string(gameptr->get_nb_balls());}
    bool draw ; // current drawing state
    void on_draw(const crptr& cr, int width, int height);
    Game* gameptr;
    
private:
   
    

    // DrawingArea signal handler:

    void draw_contour(const crptr& cr, const int side);
    void draw_bricks(const crptr& cr, const int side);
    void draw_paddle(const crptr& cr, const int side);
    void draw_ball(const crptr& cr, const int side);

    void draw_rnb(const crptr& cr, const int side,const Brick* brick);

    void draw_brball(const crptr& cr, const int side,const Brick* brick);

    void draw_split(const crptr& cr, const int side,const Square& sq
                                                ,const int hit_pts ,const int count);

    void draw_square(const crptr& cr, const int side,const Square& sq);   

    void draw_disk(const crptr& cr, const int side,const Circle& sq);
    
    void set_color(const crptr& cr,int color);                                                            
};

#endif // GTKMM_EXAMPLE_GRAPHIC_H
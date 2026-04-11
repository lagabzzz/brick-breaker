#ifndef GTKMM_EXAMPLE_GRAPHIC_H
#define GTKMM_EXAMPLE_GRAPHIC_H

#include <giomm.h>
#include <gtkmm.h>
#include <iostream>
#include <cairomm/context.h>
#include <string>
#include <filesystem>
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

 
    bool draw ; // current drawing state
    std::string get_score(){return std::to_string(gameptr->get_score());}
    std::string get_lives(){return std::to_string(gameptr->get_lives());}
    std::string get_nb_bricks(){return std::to_string(gameptr->get_nb_bricks());}
    std::string get_nb_balls(){return std::to_string(gameptr->get_nb_balls());}

    void on_draw(const crptr& cr, int width, int height);
    void save_game(const std::string& file_name);
    void reset_game(const std::filesystem::path& file_name);
    
private:
   
    Game* gameptr;

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
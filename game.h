//game
//Rendu 2
//Jean-Michel Vellozzi
//Gabriel Plewinski

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include "message.h"
#include "constants.h"
#include "tools.h"


typedef std::vector<std::unique_ptr<Brick>> LesBriques;
typedef std::vector<std::unique_ptr<Ball>> LesBalles;

enum Type_lecture{

    SCORE,
    LIVES,
    PADDLE,
    NB_BRICK,
    BRICK,
    NB_BALL,
    BALL,
    FIN
};


class Game {

public:
    Game(bool error=false):error(error){}

    void section_de_lecture(const char* test);
    Brick* get_brick(int i) const {return bricks[i].get();}
    Ball* get_ball(int i) const {return balls[i].get();}
    int get_score() const {return score;}
    int get_lives() const {return lives;}
    int get_nb_bricks() const {return nb_bricks;}
    int get_nb_balls() const {return nb_balls;}
    bool get_error() const {return error;}
    void spawn_ball();
    void set_follow_mouse(double x);
    void reset();
    void save_game(const std::string& file_name);
    void draw_bricks();
    void draw_balls();
    void draw_paddle();
    double get_paddle_radius();
    void update();
    double x_correction(const Square& brick, double futur_x);
    
private:

    LesBriques bricks;
    LesBalles balls;
    Paddle paddle;
    int score;
    int lives;
    int nb_bricks;
    int nb_balls;
    int count_lecture;
    bool error;
    void set_true(){error=true;}
    void error_message(std::string message);

    void test_collisions();

    void lecture_score(const std::string& line);

    void lecture_lives(const std::string& line);

    void lecture_paddle(const std::string& line);   

    void lecture_brick(const std::string& line);

    void lecture_ball(const std::string& line);

    void coll_ball_brick(const Circle&,const Square&);
};

#endif
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <vector>
#include <memory>
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

    void section_de_lecture(char* test);
    Brick* get_brick(int i) const {return bricks[i].get();}
    Ball* get_ball(int i) const {return balls[i].get();}
    int get_score() const {return score;}
    int get_lives() const {return lives;}
    int get_nb_bricks() const {return nb_bricks;}
    int get_nb_balls() const {return nb_balls;}
    

private:

    LesBriques bricks;
    LesBalles balls;
    Paddle paddle;
    int score;
    int lives;
    int nb_bricks;
    int nb_balls;
    int count_lecture;
    void test_collisions();

    void lecture_score(const std::string& line);

    void lecture_lives(const std::string& line);

    void lecture_paddle(const std::string& line);   

    void lecture_brick(const std::string& line);

    void lecture_ball(const std::string& line);
};


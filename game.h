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
using namespace std;

typedef vector<unique_ptr<Brick>> LesBriques;
typedef vector<unique_ptr<Ball>> LesBalles;

class Game {

    public:

        void section_de_lecture(char* test);
        

    private:
    
        LesBriques bricks;
        LesBalles balls;
        Paddle paddle;
        int score;
        int lives;
        int nb_bricks;
        int nb_balls;

        void test_collisions();

        void lecture_score(const string& line);

        void lecture_lives(const string& line);

        void lecture_paddle(const string& line);

        void lecture_brick(const string& line);

        void lecture_ball(const string& line);
};


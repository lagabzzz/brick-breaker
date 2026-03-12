#include <fstream>
#include <string>

enum Type_lecture
{
    SCORE,
    LIVES,
    PADDLE
    NB_BRICK,
    BRICK,
    NB_BALL,
    BALL,
    FIN
};

void lecture() {}

void lecture_score(string line);

void lecture_lives(string line);

void lecture_paddle(string line);

void lecture_brick(string line);

void lecture_ball(string line);


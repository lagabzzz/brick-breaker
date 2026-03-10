#include "lecture.h"
#include <iostream>
using namespace std;
 
enum Type_lecture
{
    SCORE,
    LIVES,
    BRICK,
    BALL,
    PADDLE
};

void section_de_lecture(Type_lecture type){

    switch(type){
    case SCORE:
        cout << "Section de lecture : SCORE" << endl;
        break;

    case LIVES:
        cout << "Section de lecture : LIVES" << endl;
        break;

    case BRICK:
        cout << "Section de lecture : BRICK" << endl;
        break;

    case BALL:
        cout << "Section de lecture : BALL" << endl;
        break;

    case PADDLE:
        cout << "Section de lecture : PADDLE" << endl;
        break;

    default:
        cout << "Section de lecture : UNKNOWN" << endl;
        break;
    }

}

int main()// Test de la fonction section_de_lecture
{
    Type_lecture test = SCORE;
    section_de_lecture(test);
    return 0;
}

#include "lecture.h"
#include <iostream>
using namespace std;
 


void section_de_lecture(){

    ifstream  fichier("test.txt")
    if(fichier.fail()) exit(); //sort si le fichier s'ouvre pas
    string line;

    Type_lecture etat = SCORE

    while (getline(fichier,line)){

        switch(etat){

        case SCORE:
            lecture_score(line);
            etat = LIVES;
            break;

        case LIVES:
            lecture_lives(line);
            etat = PADDLE;
            break;
        
        case PADDLE:
            lecture_paddle(line);
            etat = BRICK;
            break;

        case BRICK:
            lecture_brick(line);
            etat = BALL
            break;

        case BALL:
            lecture_ball(line);
            etat = FIN
            break;

        case FIN;
            break;
            
        default:
            break;
        }
    }    
}

int main()// Test de la fonction section_de_lecture
{

    section_de_lecture();
    return 0;
}

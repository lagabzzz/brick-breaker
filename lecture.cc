#include "lecture.h"
#include <iostream>
using namespace std;
 


void section_de_lecture(*char test){

    ifstream  fichier(test);
    if(fichier.fail()) exit(); //sort si le fichier s'ouvre pas
    string line;

    Type_lecture etat = SCORE

    while (getline(fichier,line)){
        if (line.empty() or line[0] == '#'){
            continue;
        }
    
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

void lecture_score(const string&){
    
}
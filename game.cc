#include <game.h>

void lecture_score(const string&);

void lecture_lives(const string&);

void lecture_paddle(const string&);

void lecture_brick(const string&);

void lecture_ball(const string&);

void section_de_lecture(*char test){

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

    ifstream  fichier(test);
    if(fichier.fail()) exit(); //sort si le fichier s'ouvre pas
    const string&;

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
            return;
            
        default:
            break;
        }
    }    
}


void lecture_score(const string&){
    
}

void lecture_lives(const string&){
    
}

void lecture_paddle(const string&){
    
}

void lecture_brick(const string&){
    
}

void lecture_ball(const string&){
    
}

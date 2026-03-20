#include <game.h>

void lecture_score(const string& line);

void lecture_lives(const string& line);

void lecture_paddle(const string& line);

void lecture_brick(const string& line, const int& nb_bricks);

void lecture_ball(const string& line, const int& nb_balls);

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
            etat = NB_BRICK;
            break;

        case NB_BRICK:
            nb_bricks = stoi(line);
            etat = BRICK;
            break;
             
        case BRICK:
            lecture_brick(line, nb_bricks);
            etat = NB_BALL;
            break;

        case NB_BALL:
           nb_balls = stoi(line);
           etat = BALL;
           break;

        case BALL:
            lecture_ball(line, nb_balls);
            etat = FIN
            break;

        case FIN;
            return;
            
        default:
            break;
        }
    }    
}


void lecture_score(const string& line){
    score = stoi(line); 
    if (score <= 0){
        cout << invalid_score(score) << endl;
        exit(0);
    }  
}

void lecture_lives(const string& line){
    lives = stoi(line);
    if (lives <= 0){
        cout << invalid_lives(lives) << endl;
        exit(0);
    }  
}

void lecture_paddle(const string& line){
    istringstream iss(line);
    double x;
    double y;
    double rayon;
    iss >> x >> y >> rayon;
    //methodes d'inclusion
    paddle = Paddle(x, y, rayon);
}

void lecture_brick(const string& line, const int& nb_bricks){
    istringstream iss(line);
    for(int i(0); i < nb_bricks; ++i){
        int type_brick;
        double x, y, c;
        iss >> type_brick >> x >> y >> c;
        Square s(x, y, c);
        
        switch(type_brick){
            case 0:
                int hit_points;
                iss >> hit_points;
                unique_ptr<Brick> rnb_brique_ptr(new Rainbowbrick(s,hit_points));
                bricks.push_back(&rnb_brique);
                break;

            case 1:
                unique_ptr<Brick> b_brique_ptr(new Ball_brick(s));
                bricks.push_back(b_brique_ptr);
                break;
            
            case 2:
                unique_ptr<Brick> s_brick_ptr(new Split_brick(s))
                bricks.push_back(s_brick_ptr);
                break;
        } 
    }
}

void lecture_ball(const string& line, const int& nb_balls){

    istringstream iss(line);
    for(int i(0); i < nb_balls; ++i){
        double x, y, r, dx, dy;
        iss >> x >> y >> r >> dx >> dy;
        balls.push_back(Ball(x, y, r, dx, dy))
    }
    
}


void test_collisions(//vector<Brick*> bricks, vector<Ball> balls, Paddle paddle, int nb_bricks, int nb_balls){
    
  for(int i(0); i < nb_bricks; ++i){

    for(int j(i+1); j < nb_bricks; ++j){

       if( //methode collsions bricks(bricks[i],brick[j]......))
          //return sur true
    }
  }


  for(int i(0); i < nb_bricks; ++i){

     for(int j(i+1); j < nb_balls; ++j){

        //methode collsions bricks&balls(bricks[i],balls[j]......)
     }
   }

    for(int i(0); i < nb_balls; ++i){

      for(int j(i+1); j < nb_balls; ++j){

        //methode collsions balls(balls[i],balls[j]......)
      }
    }

   for(int i(0); i < nb_bricks; ++i){
        //methode collisions paddle&bricks(paddle, bricks[i].....)
   }
   for(int j(0); j < nb_balls; ++j){

        //methode collsions paddle&balls(paddle,balls[j]......)
   }
  












}
#include "game.h"

void Game::section_de_lecture(char* test){

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

    ifstream fichier(test);
    if(fichier.fail()) exit(0); //sort si le fichier s'ouvre pas
    string line;
    
    Type_lecture etat = SCORE;

    count_lecture = 0;
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
            lecture_brick(line);
            count_lecture++;
            if (count_lecture == nb_bricks){
                etat = NB_BALL;
                count_lecture = 0;
            }
            break;

        case NB_BALL:
            
            nb_balls = stoi(line);
            etat = BALL;
            
            break;

        case BALL:
            lecture_ball(line);
            count_lecture++;
            if (count_lecture == nb_balls){
                etat = FIN;
                count_lecture = 0;
            }
            break;

        case FIN:
            break;
            
        default:
            break;
        }
    }  
    test_collisions(); 

        
    cout << message::success() << endl; 
}


void Game::lecture_score(const string& line){
    score = stoi(line); 
    if (score < 0){
        Tools::error_message(message::invalid_score(score));
    }  
}

void Game::lecture_lives(const string& line){
    lives = stoi(line);
    if (lives < 0){
        Tools::error_message(message::invalid_lives(lives));
    }  
}

void Game::lecture_paddle(const string& line){
    istringstream iss(line);
    double x;
    double y;
    double rayon;
    iss >> x >> y >> rayon;

    paddle = Paddle(x, y, rayon);
}

void Game::lecture_brick(const string& line){
    istringstream iss(line);
    
    int type_brick;
    double x, y, c;
    iss >> type_brick >> x >> y >> c;

    Square s(x, y, c);

    int hit_points;
    
    switch(type_brick){
        case 0:   
            iss >> hit_points;
            bricks.push_back(unique_ptr<Brick> (new Rainbowbrick(s,hit_points)));
            break;

        case 1:
            bricks.push_back(unique_ptr<Brick> (new Ball_brick(s)));
            break;
        
        case 2:
            bricks.push_back(unique_ptr<Brick> (new Split_brick(s)));
            break;

        default:
            Tools::error_message(message::invalid_brick_type(type_brick));
            break;
    } 
    
}

void Game::lecture_ball(const string& line){

    istringstream iss(line);
    for(int i(0); i < nb_balls; ++i){
        double x, y, r, dx, dy;
        iss >> x >> y >> r >> dx >> dy;
        balls.push_back(unique_ptr<Ball> (new Ball(x,y,r,dx,dy)));
    }
    
}


void Game::test_collisions(){
    
    for(int i(0); i < nb_bricks; ++i){

        if(Tools::intersects(bricks[i]->get_brick(),paddle.get_paddle())){
            Tools::error_message(message::collision_paddle_brick(i+1));
        }
    
        for(int j(i+1); j < nb_bricks; ++j){ //test brick brick

            if(Tools::intersects(bricks[i]->get_brick(),bricks[j]->get_brick())){

                Tools::error_message(message::collision_bricks(i+1,j+1));
            }
        }
    }


    for(int i(0); i < nb_balls; ++i){

        if(Tools::intersects(balls[i]->get_ball(),paddle.get_paddle())){
            Tools::error_message(message::collision_paddle_ball(i+1));
        }

        for(int j(i+1); j < nb_balls; ++j){

            if(Tools::intersects(balls[i]->get_ball(),balls[j]->get_ball())){
                
                Tools::error_message(message::collision_balls(i+1,j+1));
            }
        }
    }

    for(int i(0); i < nb_bricks; ++i){

        for(int j(0); j < nb_balls; ++j){ //test brick ball

            if(Tools::intersects(bricks[i]->get_brick(),balls[j]->get_ball())){
                
                Tools::error_message(message::collision_ball_brick(j+1,i+1));
            }
        }
    }
}
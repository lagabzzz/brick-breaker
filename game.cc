#include "game.h"
using namespace std;

void Game::error_message(string message){
    cout << message << endl;
    set_true();
}  
void Game::section_de_lecture(char* test){

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
                //count_lecture = 0;
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
        error_message(message::invalid_score(score));
    }  
}

void Game::lecture_lives(const string& line){
    lives = stoi(line);
    if (lives < 0){
        error_message(message::invalid_lives(lives));
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
        case B_RAINBOW:   
            iss >> hit_points;
            bricks.push_back(unique_ptr<Brick> (new Rainbowbrick(s,hit_points)));
            break;

        case B_BALL:
            bricks.push_back(unique_ptr<Brick> (new Ball_brick(s)));
            break;
        
        case B_SPLIT:
            bricks.push_back(unique_ptr<Brick> (new Split_brick(s)));
            break;

        default:
            error_message(message::invalid_brick_type(type_brick));
            break;
    } 
}

void Game::lecture_ball(const string& line){

    istringstream iss(line);
    double x, y, r, dx, dy;
    iss >> x >> y >> r >> dx >> dy;
    balls.push_back(unique_ptr<Ball> (new Ball(x,y,r,dx,dy)));
    
}


void Game::test_collisions(){
    
    if(paddle.inclusion_arene()){
        error_message(message::paddle_outside(paddle.get_x()
                                                    ,paddle.get_y()));
    }
    for(int i(0); i < nb_bricks; ++i){

        if(Tools::intersects(bricks[i]->get_brick(),paddle.get_paddle())){
            error_message(message::collision_paddle_brick(i));
        }
        if(bricks[i]->test_arene()){
            error_message(message::brick_outside(bricks[i]->get_x()
                                                    ,bricks[i]->get_y()));    
        } 
        if(bricks[i]->test_val()) error_message(message::invalid_brick_size(i));
        if(bricks[i]->test_hit_pt()) error_message(message::invalid_hit_points(i));
    
        for(int j(i+1); j < nb_bricks; ++j){ //test brick brick

            if(Tools::intersects(bricks[i]->get_brick(),bricks[j]->get_brick())){

                error_message(message::collision_bricks(i,j));
            }
        }
    }

    for(int i(0); i < nb_balls; ++i){

        if(Tools::intersects(balls[i]->get_ball(),paddle.get_paddle())){
            error_message(message::collision_paddle_ball(i));
        }
        if(balls[i]->include_arene()){
            error_message(message::ball_outside(balls[i]->get_x(),balls[i]->get_y()));
        }
        if(balls[i]->test_norme()){
            error_message(message::invalid_delta(balls[i]->get_dx()
                                                        ,balls[i]->get_dy()));
        }

        for(int j(i+1); j < nb_balls; ++j){

            if(Tools::intersects(balls[i]->get_ball(),balls[j]->get_ball())){
                
                error_message(message::collision_balls(i,j));
            }
        }
    }

    for(int i(0); i < nb_bricks; ++i){

        for(int j(0); j < nb_balls; ++j){ //test brick ball

            if(Tools::intersects(bricks[i]->get_brick(),balls[j]->get_ball())){
                
                error_message(message::collision_ball_brick(j,i));
            }
        }
    }
}
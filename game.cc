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
    cout << message::succes() << endl; 
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
        if (type_brick < 0 or type_brick > 2){
            cout << invalid_type_brick(type_brick) << endl;
            exit(0);
        }
        if (c <= brick_size_min){
            cout << invalid_brick_size(c) << endl;
            exit(0);
        }
        Square s(x, y, c);
        
        switch(type_brick){
            case 0:
                int hit_points;
                iss >> hit_points;
                bricks.push_back(new Rainbowbrick(s,hit_points));
                break;

            case 1:
                bricks.push_back(new Ball_brick(s));
                break;
            
            case 2:
                bricks.push_back(new Split_brick(s));
                break;

            default:
                Tools::error_message(message::invalid_brick_type(type_brick));
                break;
        } 
    }
}

void lecture_ball(const string& line, const int& nb_balls){

    istringstream iss(line);
    for(int i(0); i < nb_balls; ++i){
        double x, y, r, dx, dy;
        iss >> x >> y >> r >> dx >> dy;
        unique_ptr<Ball> ball_ptr(new Ball(x,y,r,dx,dy));
        balls.push_back(ball_ptr);
    }
    
}


void test_collisions(){
    
    for(size_t i(0); i < nb_bricks; ++i){
        Tools::intersects(bricks[i]->get_brick(),paddle.get_paddle()) //test brick paddle

        for(size_t j(i+1); j < nb_bricks; ++j){ //test brick brick

            if(Tools::intersects(bricks[i]->get_brick(),bricks[j]->get_brick())){
                
                Tools::error_message(message::collision_bricks(i,j));
            }
        }
    }


    for(size_t i(0); i < nb_balls; ++i){
        Tools::intersects(balls[i]->get_ball(),paddle.get_paddle()) //test ball paddle

        for(size_t j(i+1); j < nb_balls; ++j){

            if(Tools::intersects(balls[i]->get_ball(),balls[j]->get_ball())){
                
                Tools::error_message(message::collision_balls(i,j));
            }
        }
    }

    for(size_t i(0); i < nb_bricks; ++i){

        for(size_t j(0); j < nb_balls; ++j){ //test brick ball

            if(Tools::intersects(bricks[i]->get_brick(),balls[j]->get_ball())){
                
                Tools::error_message(message::collision_ball_brick(j,i));
            }
        }
    }
}
#include "game.h"
using namespace std;

//int Ball::count = 0;

void Game::error_message(string message){
    cout << message << endl;
    set_true();
}  
void Game::section_de_lecture(const char* test){

    ifstream fichier(test);
    if(fichier.fail()){
        set_true();
        return;    
    } 
    string line;
    if(error) error = false;
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
 
    if (!error) {
        cout << message::success() << endl; 
    }
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
        error_message(message::paddle_outside(paddle.get_x(),paddle.get_y()));
    }
    for(int i(0); i < nb_bricks; ++i){

        if(Tools::intersects(bricks[i]->get_brick(),paddle.get_paddle(),false)){
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

        if(Tools::intersects(balls[i]->get_ball(),paddle.get_paddle(),false)){
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

            if(Tools::intersects(balls[i]->get_ball(),balls[j]->get_ball(),false)){
                
                error_message(message::collision_balls(i,j));
            }
        }
    }
    for(int i(0); i < nb_bricks; ++i){

        for(int j(0); j < nb_balls; ++j){ //test brick ball

            if(Tools::intersects(bricks[i]->get_brick(),balls[j]->get_ball(),false)){
                
                error_message(message::collision_ball_brick(j,i));
            }
        }
    }
}
void Game::spawn_ball(){
    //appel de la fonction pour dessiner et generer la balle
    double new_y(paddle.get_y()+paddle.get_rayon()+EPSIL_ZERO);//pas sur du epsil_zero
    
    balls.push_back(unique_ptr<Ball> (new Ball(paddle.get_x(),new_y,new_ball_radius,0,
                                      new_ball_delta_norm)));
    nb_balls++;
    lives--;
}
void Game::reset(){

    bricks.clear();
    balls.clear();
    bricks.shrink_to_fit();
    balls.shrink_to_fit();
    score = 0;
    lives = 0;
    nb_balls= 0;
    nb_bricks= 0;
}

void Game::save_game(const std::string& file_name){
    std::fstream file(file_name);
    if(file.is_open()){

        file << score << "\n";
        file << lives << "\n";
        file << paddle.get_x() <<" "<<paddle.get_y()<<" "<<paddle.get_rayon() << "\n";
        file << nb_bricks << "\n";

        for(const auto& br : bricks){
            file << br->brick_type() <<" "<<br->get_x() <<" "<<br->get_y()<<" "
            <<br->get_size() <<" ";
            if(br->brick_type()==B_RAINBOW){
                file<<br->get_hit_pts();
            }
            file << "\n";
        }

        file << nb_balls << "\n";
        for(const auto& ba : balls){
            file << ba->get_x() <<" "<<ba->get_y()<<" "<<ba->get_rayon() <<" ";
            file <<ba->get_dx() <<" "<<ba->get_dy() << "\n";
        }
    }
}

void Game::draw_bricks(){

    for(int i(0);i < nb_bricks;i++){
        
        bricks[i]->draw_brick();
    }
}

void Game::draw_balls(){

    for(int i(0);i < nb_balls;i++){
        
        balls[i]->draw_ball();
    }
}

void Game::draw_paddle(){
        
    paddle.draw_paddle();    
}


void Game::set_follow_mouse(double x){

    paddle.set_follow_mouse(x);
}

double Game::get_paddle_radius(){

    return paddle.get_rayon();
}
 
void Game::update(){
    double future_x = clamp(paddle.get_follow_mouse(),(paddle.get_x()-delta_norm_max),
                           (paddle.get_x()+delta_norm_max) );
    for(int i(0);i < nb_bricks;i++){

        Paddle next_paddle(future_x,paddle.get_y(),paddle.get_rayon());
        if (Tools::intersects(next_paddle.get_paddle(), bricks[i]->get_brick())){
            double correct_x = x_correction(bricks[i]->get_brick(), future_x);
            paddle.set_paddle_x(correct_x);
            return;
        }
    }
    paddle.set_paddle_x();

    
    for (unsigned int i(0); i < balls.size(); i++){

        if(balls[i]->get_y() < 0){
            balls[i] = std::move(balls.back());
            balls.pop_back();
            nb_balls--;
            i--;
            continue;
        }
    }

    for(unsigned int i(0); i<balls.size(); i++){

        balls[i]->future_pos();
        balls[i]->coll_ball_arene();
        balls[i]->coll_ball_arene();

        for(unsigned int j(i+1); j < balls.size(); j++){
            balls[j]->future_pos();
            if(Tools::intersects(balls[i]->get_ball(), balls[j]->get_ball())){
                balls[i]->coll_ball(*balls[j]);
            }else{
                balls[j]->last_pos();
            }
        }
        for(unsigned j(0); j<bricks.size(); j++){
            if(Tools::intersects(balls[i]->get_ball(),bricks[j]->get_brick())){
                
                brick_got_hit(*bricks[j],j,i);
                balls[i]->coll_brick(bricks[j]->get_brick());
                
                std::cout<<"ha"<<std::endl;
                if(bricks[j]->get_hit_pts() <= 0){
                    destr_brick(j);
                }  
            }
        }
    }
}

double Game::x_correction(const Square& brick, double future_x){
    
    double radius_squared = paddle.get_rayon()*paddle.get_rayon();
    double dy = (paddle.get_y()- (brick.centre.y-brick.size/2));
    double offset = sqrt(radius_squared - dy * dy);
    if (future_x > paddle.get_x()){
        return brick.centre.x- brick.size/2 - offset;
    }
    else{
        return brick.centre.x + brick.size/2 + offset;
    }
}

void Game::destr_brick(unsigned &j){

    bricks[j] = std::move(bricks.back());
    bricks.pop_back();
    nb_bricks--;
    j--;
}

void Game::brick_got_hit(Brick & br,unsigned &j,int i){

    br.got_hit();

    switch(br.brick_type()){

        case B_RAINBOW:
            break;

        case B_BALL:
            {
            Ball new_b(bricks[j]->get_x(),bricks[j]->get_y(),new_ball_radius,
                                          balls[i]->get_dx(),balls[i]->get_dy());
        
            balls.push_back(unique_ptr<Ball> (new Ball(new_b)));
            nb_balls++;
            }
            break;

        case B_SPLIT:
        Square sq(br.get_brick());
            double new_size((sq.size-split_brick_gap)/2);
            double delta_p((new_size+split_brick_gap)/2);

            if(new_size >= brick_size_min){
                Square s1(sq.centre.x-delta_p,sq.centre.y+delta_p,new_size);
                Square s2(sq.centre.x+delta_p,sq.centre.y+delta_p,new_size);
                Square s3(sq.centre.x+delta_p,sq.centre.y-delta_p,new_size);
                Square s4(sq.centre.x-delta_p,sq.centre.y-delta_p,new_size);

                bricks.push_back(unique_ptr<Brick> (new Split_brick(s1)));
                bricks.push_back(unique_ptr<Brick> (new Split_brick(s2)));
                bricks.push_back(unique_ptr<Brick> (new Split_brick(s3)));
                bricks.push_back(unique_ptr<Brick> (new Split_brick(s4)));

                nb_bricks += 4;
            }
            br.set_hit_pts_zero();
            break;
    }
}
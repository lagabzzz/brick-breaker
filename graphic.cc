#include "graphic.h"

void Graphic::on_draw(const crptr& cr, int width, int height){

	if(draw){

		int side = std::min(width, height);
        draw_contour(cr,side);
        draw_bricks(cr,side);
        draw_ball(cr,side);
	}
}

void Graphic::draw_contour(const crptr& cr, const int side){
  
    cr->set_line_width(3.0);
    cr->set_source_rgb(0.5, 0.5, 0.5);
    cr->move_to(0, 0);
    cr->line_to(side, 0);
    cr->line_to(side,side);
    cr->line_to(0, side);
    cr->line_to(0, 0);
    cr->stroke();
}

void Graphic::draw_ball(const crptr& cr, const int side){

    set_color(cr,NOIR);
    for(int i(0);i < gameptr->get_nb_balls();i++){
        draw_disk(cr,side,gameptr->get_ball(i)->get_ball());
    }
}

void Graphic::draw_bricks(const crptr& cr,const int side){

    for(int i(0);i < gameptr->get_nb_bricks();i++){
        //std::cout<<gameptr->get_brick(i)->brick_type()<<std::endl;
        //std::cout<<gameptr->get_nb_bricks()<<std::endl;

        switch(gameptr->get_brick(i)->brick_type()){
            
            case B_RAINBOW:  
            draw_rnb(cr,side,gameptr->get_brick(i));
            break;

            case B_BALL:
            draw_brball(cr,side,gameptr->get_brick(i));
            break;
        
            case B_SPLIT:
            draw_split(cr,side,gameptr->get_brick(i)->get_brick(),
                                                gameptr->get_brick(i)->get_hit_pts(),1);
            break;
        }      
    }
}

void Graphic::draw_rnb(const crptr& cr, const int side, const Brick* brick)
{
    set_color(cr,brick->get_hit_pts());

    draw_square(cr,side,brick->get_brick());
}

void Graphic::draw_brball(const crptr& cr, const int side,const Brick* brick){

    set_color(cr,ROUGE);
    draw_square(cr,side,brick->get_brick());
    set_color(cr,NOIR);

    double new_size(side*brick->get_size()*20/(100*100));
    double new_x(side*brick->get_x()/100);
    double new_y(side*(1-brick->get_y()/100));

    cr->arc(new_x,new_y,new_size,0.0,2*M_PI);
    cr->fill();
}

void Graphic::draw_split(const crptr& cr, const int side,const Square& sq
                                                ,const int hit_pts ,const int count){

    set_color(cr,count);
    draw_square(cr,side,sq);

    if(count < hit_pts){
        double new_size((sq.size-split_brick_gap)/2);
        double delta_p((new_size+split_brick_gap)/2);
        Square s1(sq.centre.x-delta_p,sq.centre.y+delta_p,new_size);
        Square s2(sq.centre.x+delta_p,sq.centre.y+delta_p,new_size);
        Square s3(sq.centre.x+delta_p,sq.centre.y-delta_p,new_size);
        Square s4(sq.centre.x-delta_p,sq.centre.y-delta_p,new_size);

        draw_split(cr,side,s1,hit_pts,count+1);
        draw_split(cr,side,s2,hit_pts,count+1);
        draw_split(cr,side,s3,hit_pts,count+1);
        draw_split(cr,side,s4,hit_pts,count+1);
    }
}

void Graphic::draw_square(const crptr& cr, const int side, const Square& sq)
{

    double new_size(side*sq.size/100);
    double new_x(side*sq.centre.x/100-new_size/2);
    double new_y(side*(1-sq.centre.y/100)-new_size/2);

    cr->rectangle(new_x,new_y,new_size,new_size);
    cr->fill();
}

void Graphic::draw_disk(const crptr& cr, const int side,const Circle& ci){
   
    double new_size(side*ci.rayon/100);
    double new_x(side*ci.centre.x/100);
    double new_y(side*(1-ci.centre.y/100));

    cr->arc(new_x,new_y,new_size,0.0,2*M_PI);
    cr->fill();
}


void Graphic::set_color(const crptr& cr,int color){

    switch(color){
        
        case NOIR:
            cr->set_source_rgb(0.0, 0.0, 0.0); break;
        case ROUGE:
            cr->set_source_rgb(1.0, 0.0, 0.0); break;
        case ORANGE:
            cr->set_source_rgb(1.0, 0.65, 0.0); break;
        case JAUNE:
            cr->set_source_rgb(1.0, 1.0, 0.0); break;
        case VERT:
            cr->set_source_rgb(0.0, 1.0, 0.0); break;
        case CYAN:
            cr->set_source_rgb(0.0, 1.0, 1.0); break;
        case BLEU:
            cr->set_source_rgb(0.0, 0.0, 1.0); break;
        case VIOLET:
            cr->set_source_rgb(0.5, 0.0, 0.5); break;
    }
}
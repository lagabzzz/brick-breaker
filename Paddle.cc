#include "paddle.h"
using namespace std;

const Circle& Paddle::get_paddle() const{
    return paddle;
}

bool Paddle::inclusion_arene(){

    bool testx (Tools::test_range(paddle.centre.x,paddle.rayon,
                                  arena_size-paddle.rayon,false));
    
    bool testy (Tools::test_range(paddle.centre.y,-paddle.rayon,0,false));

      if((testx and testy)==false){

        return true;

    }else{

        return false;
    }
}

  



#include <iostream>
#include <cstdlib>
#include <fstream>
#include "game.h"
using namespace std;



int main(int argc, *char argv) {
    
    Game game;   
 
    //appel de la fonction de lecture avec (argv[1])aka "test.0x"
    game.section_de_lectrure(argv[1]);




    return 0;
}

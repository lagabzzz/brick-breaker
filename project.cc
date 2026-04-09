#include <iostream>
#include <cstdlib>
#include <fstream>
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "game.h"
#include "myevent.h"
using namespace std;

int main(int argc,char* argv[]) {
    
    Game game;   
 
    //appel de la fonction de lecture avec (argv[1])aka "test.0x"
    game.section_de_lecture(argv[1]);


    auto app = Gtk::Application::create();

    return app->make_window_and_run<MyEvent>(0,nullptr,&game);
}

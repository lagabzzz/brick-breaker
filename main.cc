#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;



int main(int argc, *char argv) {
    
    ifstream fichier_test(argv[1]);
    if (fichier_test.fail()){
        return EXIT_FAILURE;
    }
//appel de la fonction de lecture avec (argv[1])aka "test.0x"





    return 0;
}

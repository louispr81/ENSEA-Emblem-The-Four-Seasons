#include <iostream>
#include "../../src/shared/state.h"
#include "render.h"
#include "client.h"
#include <unistd.h>
#include <string.h> 
using namespace std;
using namespace state;
using namespace render;
using namespace client;


using namespace std;
using namespace state;


void usage(char * argv0){
    cout << "Usage: " << argv0 << " COMMAND" << endl;
    cout << "\tCOMMAND := { ";
        cout << "hello" << " | ";
        cout << "state";
    cout << " }" << endl;
}

int main(int argc, char* argv[])
{

if (argc == 1){
        usage(argv[0]);
        std::exit(EXIT_FAILURE);
    }


if (strcmp(argv[1],"hello") ==0 ){
        std::cout << "hello World " << std::endl;
    }
	else if (strcmp(argv[1],"state") == 0){
        state::State state;

		std::cout << "CREATION DU STATE" << std::endl;
    }

    else if (strcmp(argv[1],"render") == 0){
		std::cout << "Lancement du RENDU" << std::endl;
        state::State *state = new State();
        sf::Vector2u tileSize = sf::Vector2u(128,128);

        render::StateLayer *rendu = new StateLayer(tileSize, 128, 128, state);
        (*rendu).window();
	}
    
    else {
        std::cout << "Wrong command !" << std::endl ;
    }


   
    
   


    return 0;
}

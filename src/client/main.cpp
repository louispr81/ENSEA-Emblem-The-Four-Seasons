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
        cout << "state"<< " | ";;
        cout << "render"<< " | ";;
        cout << "engine"<< " | ";;
        cout << "random_ai"<< " | ";;
        cout << "heuristic_ai"<< " | ";;
        cout << "game";
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
        std::cout << "CREATION DU STATE" << std::endl;
        state::State state(17);
        state.print();
    }

    else if (strcmp(argv[1],"render") == 0){
		std::cout << "Lancement du RENDU" << std::endl;
        state::State *state = new State(17);
        sf::Vector2u tileSize = sf::Vector2u(32,32);
        render::StateLayer *rendu = new StateLayer(tileSize, 17, 17, state);
        (*rendu).windowExemple();
	}
    else if (strcmp(argv[1],"engine") == 0){
        std::cout << "Lancement de l'ENGINE" << std::endl;
        std::cout << "Les touches :" << std::endl;
        std::cout << "A : attendre (et valider la fin du tour du personnage)" << std::endl;
        std::cout << "Z,Q,S,D : se déplacer" << std::endl;
        std::cout << "UP,DOWN,LEFT,RIGHT : attaquer " << std::endl;
		client::Client *client= new Client;
        client->run();

	}
    else if (strcmp(argv[1],"game") == 0){
        std::cout << "Lancement du CLIENT" << std::endl;
        std::cout << "Les touches :" << std::endl;
        std::cout << "A : attendre (et valider la fin du tour du personnage)" << std::endl;
        std::cout << "Z,Q,S,D : se déplacer" << std::endl;
        std::cout << "UP,DOWN,LEFT,RIGHT : attaquer " << std::endl;
		client::Client *client= new Client;
        client->run();
	}
    else if (strcmp(argv[1],"random_ai") == 0){
        std::cout << "Work in Progress" << std::endl;
	}
    else if (strcmp(argv[1],"heuristic_ai") == 0){
        std::cout << "Work not started yet" << std::endl;
	}
    else {
        std::cout << "Wrong command !" << std::endl ;
    }


   
    
   


    return 0;
}

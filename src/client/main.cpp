#include <iostream>
#include "../../src/shared/state.h"
#include "client.h"
#include <unistd.h>
#include <string.h> 
using namespace std;
using namespace state;
//using namespace render;
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

		std::cout << "CREATION DE STATE" << std::endl;
    }

    else if (strcmp(argv[1],"render") == 0){
		std::cout << "RENDER" << std::endl;
	}
    
    else {
        std::cout << "Wrong command !" << std::endl ;
    }


   
    
   


    return 0;
}

#include "Client.h"
#include <iostream>
using namespace client;
using namespace state;
using namespace moteur;

Client::Client (){
    State* state=new State(17);
    Engine* engine=new Engine(/*state,currentCommands*/);
    this->engine=engine;
    this->state=state;
}

void Client::run(){
    while(1){
        //this->engine->update();
    }
}
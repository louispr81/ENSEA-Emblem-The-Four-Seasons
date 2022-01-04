#include "Engine.h"
#include <iostream>


using namespace state;
using namespace std;
namespace moteur{

Engine::Engine () {
    cout<<"Engine launched"<<endl;
}

Engine::Engine (state::State& currentState, Command currentCommands) {
    this->currentState=currentState;
    this->currentCommands=currentCommands;
}

state::State& Engine::getState() {
    return this->currentState;
}

Command Engine::getCommands(){
   
    return this->currentCommands;
}

int Engine::update(CommandId cmd){
    
    if(cmd == ATTENDRE){
        currentCommands.execute(&this->getState());
        return 2;
    }
    if(cmd == ATTACK){
        currentCommands.execute(&this->getState());
        return 0;
    }
    if(cmd == MOVE){
        currentCommands.execute(&this->getState());
        return 1;
    }
    else{
        return -1;
    }  
}
Engine::~Engine(){

}
}
#include "Engine.h"
//#include <iostream>


using namespace state;
using namespace std;
namespace moteur{

Engine::Engine () {
    cout<<"Engine launched"<<endl;
}
/*
Engine::Engine (state::State& currentState) {
    this->currentState=currentState;
}
*/
state::State& Engine::getState() {
    return this->currentState;
}

Command& Engine::getCommands(){
   
    return this->currentCommands;
}

void Engine::update(Command& cmd){
    
    if(cmd.getCommandId()==ATTENDRE){
        cmd.execute(&this->getState());
    }
    if(cmd.getCommandId()==ATTACK){
        cmd.execute(&this->getState());
    }
    if(cmd.getCommandId()==MOVE){
        cmd.execute(&this->getState());
    }

    
}
Engine::~Engine(){

}
}
#include "Engine.h"
#include "Engine.h"
#include <iostream>


using namespace state;
using namespace moteur;
using namespace std;
/*
Engine::Engine():{

}

state::State& Engine::getState() {
    return this->currentState;
}*/
state::State &Engine::getState(){
    state::State &refState = currentState;
    return refState;
}
void Engine::addPassiveCommands(){
    int priority = 0;
    if(currentCommands.size()>0){

    }
}
void Engine::update(){

}
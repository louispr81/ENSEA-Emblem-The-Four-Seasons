#include "Engine.h"
#include <iostream>


using namespace state;
using namespace moteur;
using namespace std;
/*
Engine::Engine(){
    cout<<"Engine launched"<<endl;
}*/

state::State& Engine::getState() {
    return this->currentState;
}

Command& Engine::getCommands(){
   
    return this->currentCommands;
}

void Engine::update(){
/*
    if(Command.getCommandId()==ATTENDRE){
        state.getPersonnageActif().Attendre();
        state::Personnage.setPlayed()= false;
    }

    if(Command.getCommandId()==ATTACK){
        state::Personnage.attaquer(state::Personnage personnage);
    }*/

    
}
Engine::~Engine(){

}
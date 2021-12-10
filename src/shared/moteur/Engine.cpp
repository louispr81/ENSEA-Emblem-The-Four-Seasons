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
   /* switch (this->currentState)
    {
        switch (this->currentCommands){
            case : ATTACT
                cout<<"Attact"<< endl;
                break;
    
    default:
        break;
        }
    }*/
}
Engine::~Engine(){

}
#include "Engine.h"
#include <iostream>


using namespace state;
using namespace std;
namespace moteur{

Engine::Engine () {
    cout<<"Engine launched"<<endl;
}

//doit avoir liste *commandes 
Engine::Engine (state::State* currentState) {
    this->currentState=currentState;
    std::vector<Command*> listeCommandes;
    CommandAttack *attack = new CommandAttack(currentState);
    CommandMove *move = new CommandMove(currentState);
    CommandAttendre *attendre = new CommandAttendre(currentState);
    this->listeCommandes.push_back(attack);
    this->listeCommandes.push_back(move);
    this->listeCommandes.push_back(attendre);

}

state::State* Engine::getState() {
    return this->currentState;
}

Command* Engine::getCommands(){
   
    return currentCommands;
}

int Engine::update(CommandId cmd){
    
    if(cmd == ATTENDRE){
        this->currentCommands=this->listeCommandes[2];
        currentCommands->execute();
        return 2;
    }
    if(cmd == ATTACK){
        this->currentCommands=this->listeCommandes[0];
        this->currentCommands->execute(state::Personnage target);
        return 0;
    }
    if(cmd == MOVE){
        //demander x et y cin
        this->currentCommands=this->listeCommandes[1];
        this->currentCommands->execute(int x,int y);
        return 1;
    }
    else{
        return -1;
    }  
}
Engine::~Engine(){

}
}
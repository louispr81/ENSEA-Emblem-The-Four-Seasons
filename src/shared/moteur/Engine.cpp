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

int Engine::update(CommandId cmd, MoveId move){
    
    if(cmd == ATTENDRE){
        this->currentCommands=this->listeCommandes[2];
        ((CommandAttendre*)this->currentCommands)->execute();
        return 2;
    }
    if(cmd == ATTACK){
        this->currentCommands=this->listeCommandes[0];
        cout<<"Select target"<<endl;
        std::vector<int> = position;
        std::vector<int> = position_enemy;
        state::Joueur joueur2;
        position = currentState->getPersonnageActif()->getCell()->getCoordonees();
        joueur2=currentState->getJoueurs()[((currentState->getJoueur()->getId()-40)+1)%2];
        if(move == LEFT){
            position[0]=position[0]-1;
            for(i=0;i<->joueur2->getPersonnages().size();i++){
                position_enemy = joueur2->getPersonnages()->
                if(currentState)
            }
        }

        this->currentCommands->execute(target);
        return 0;
    }
    if(cmd == MOVE){        
        this->currentCommands=this->listeCommandes[1];
        ((CommandMove*)this->currentCommands)->execute(move);
        return 1;
    }
    else{
        return -1;
    }  
}
Engine::~Engine(){

}
}
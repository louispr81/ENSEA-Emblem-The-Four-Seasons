#include "CommandAttendre.h"
#include <iostream>
using namespace std;
using namespace state;

namespace moteur{
CommandAttendre::CommandAttendre(){

} 
CommandAttendre::CommandAttendre(state::State* currentState){
  this->id = ATTENDRE;
  this->currentState = currentState;
}

void CommandAttendre::execute(){
    currentState->getPersonnageActif()->attendre();
    currentState->getPersonnageActif();
    if(currentState->getGameover()==false){
      std::cout<<"Au tour de "<<currentState->getPersonnageActif()->getNom()<<std::endl;
    }
}
}
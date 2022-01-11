#include "CommandAttendre.h"

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
}

}
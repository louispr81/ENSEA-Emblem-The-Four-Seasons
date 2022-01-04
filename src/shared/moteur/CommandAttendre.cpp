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
/*
Json::Value CommandAttendre::serialize(){
    Json::Value newCommand;
    newCommand["id"]=id;
    return newCommand;
}
*/
void CommandAttendre::execute(){
    currentState->getPersonnageActif()->attendre();
}

}
#include "CommandAttendre.h"

using namespace std;
using namespace state;

namespace moteur{
    
CommandAttendre::CommandAttendre(bool played){
  id = ATTENDRE;
  this->played =played;
}
Json::Value CommandAttendre::serialize(){
    Json::Value newCommand;
    newCommand["id"]=id;
    return newCommand;
}

void CommandAttendre::execute(state::State &state){
    state.getPersonnageActif()->setPlayed(false);
}

}
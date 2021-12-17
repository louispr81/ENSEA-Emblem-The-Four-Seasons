#include "Command.h"

using namespace std;
using namespace moteur;
using namespace state;




void Command::setCommand(CommandId id){
    this->id = id;
}

CommandId Command::getCommandId(){
    return this->id;
}

void Command::execute(state::State* state){

}
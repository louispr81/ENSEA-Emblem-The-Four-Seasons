#include "Command.h"

using namespace std;
using namespace moteur;
using namespace state;


void Command::execute(state::State& state){
   /* if(CommandId==1){
        
    }*/
}

CommandId Command::getCommandId(){
    return id;
}
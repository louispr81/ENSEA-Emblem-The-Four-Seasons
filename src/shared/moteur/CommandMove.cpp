#include "CommandMove.h"
#include <string>
#include <iostream>

using namespace std;
using namespace state;

namespace moteur{   

CommandMove::CommandMove(int x,int y){
  id = MOVE;
  this->x = x;
  this->y = y;
}

Json::Value CommandMove::serialize(){
    Json::Value newCommand;
    newCommand["id"]=id;
    return newCommand;
}

void CommandMove::execute(state::State &state){
  cout<< "Move character" <<endl;
      if(state.getPersonnageActif()->getMoved()==true){    
        cout<<state.getPersonnageActif() <<" has been moved" << endl;
      }
      else{
        cout<<state.getPersonnageActif()<<"has not been moved" << endl;
      }

      state::Personnage *personnage;
      if(Command::getCommandId()==MOVE){
        
        if (CommandMove::getMoveId()==LEFT){  
            this->x = x-1;         
            personnage->deplacer(this->x,this->y);
        }
        else if(CommandMove::getMoveId()==RIGHT){  
            this->y = y-1;  
            personnage->deplacer(this->x,this->y);
        }
        else if(CommandMove::getMoveId()==UP){
            this->x = x+1;
            personnage->deplacer(this->x,this->y);
        }
        else if(CommandMove::getMoveId()==DOWN){
            this->y = y+1;
            personnage->deplacer(this->x,this->y);
        }
      }


}

MoveId CommandMove::getMoveId(){
  return this->moveId;
}


}
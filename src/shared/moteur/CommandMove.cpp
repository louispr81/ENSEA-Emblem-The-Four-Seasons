#include "CommandMove.h"
#include <string>
#include <iostream>

using namespace std;
using namespace state;

namespace moteur{   
CommandMove::CommandMove(){

}

CommandMove::CommandMove(state::State* currentState){
  id = MOVE;
  this->currentState=currentState;
}

Json::Value CommandMove::serialize(){
    Json::Value newCommand;
    newCommand["id"]=id;
    return newCommand;
}

void CommandMove::execute(int x,int y){
  cout<< "Move character" <<endl;
      if(currentState->getPersonnageActif()->getMoved()==true){    
        cout<<currentState->getPersonnageActif()->getNom()<<" has been moved" << endl;
      }
      else{
        cout<<currentState->getPersonnageActif()->getNom()<<"has not been moved" << endl;
      }
  currentState->getPersonnageActif()->deplacer(x,y);

/*
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
*/

}

MoveId CommandMove::getMoveId(){
  return this->moveId;
}


}
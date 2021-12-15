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
/*
void CommandMove::execute(state::State &state){
  cout<< "Move character" <<endl;
      if(personnage.getMoved()==true){    
        cout<<personnage.getPersonnageActif() <<" has been moved" << endl;
      }
      else{
        cout<<personnage.getPersonnageActif()<<"has not been moved" << endl;
      }
      if(Command.getCommandId()==MOVE){
        
        if (CommandMove->getMoveId()==LEFT){
            state.getPersonnageActif()->setCoordonnees(*(getCoordonnees().at(1)-1));
        }
        else if(CommandMove->getMoveId()==RIGHT){
            state.getPersonnageActif()->setCoordonnees(*(getCoordonnees().at(2)-1));
        }
        else if(CommandMove->getMoveId()==UP){
            state.getPersonnageActif()->setCoordonnees(*(getCoordonnees().at(2)+1));
        }
        else if(CommandMove->getMoveId()==DOWN){
            state.getPersonnageActif()->setCoordonnees(*(getCoordonnees().at(1)+1));
        }
      }


}*/
/*
MoveId CommandMove::getCommandId(){
  return this->moveId;
}
*/

/*
MoveId CommandMove::convert(sf::Event event){
    if(sf::Keyboard::isKeyPressed(sf::Keyyboard::Left)){
      return LEFT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyyboard::Right)){
      return RIGHT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyyboard::Up)){
      return UP;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyyboard::Down)){
      return DOWN;
    }
}*/
}
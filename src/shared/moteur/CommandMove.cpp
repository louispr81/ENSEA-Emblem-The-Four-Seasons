#include "CommandMove.h"
#include <string>
#include <iostream>

using namespace std;
using namespace moteur;
using namespace state;
     
CommandMove::CommandMove(state::Personnage& personnage, state::Cell& position):personnage(personnage),position(position){
   id = MOVE;
}

Json::Value CommandMove::serialize(){
    Json::Value newCommand;
    newCommand["id"]=id;
    return newCommand;
}

void CommandMove::execute(state::State &state){
  cout<< "Move character" <<endl;
      if(personnage.getMoved()==true){    
        cout<<personnage.getPersonnageActif() <<" has been moved" << endl;
      }
      else{
        cout<<personnage.getPersonnageActif()<<"has not been moved" << endl;
      }
}

#include "CommandMove.h"
#include <string>
#include <iostream>

using namespace std;
using namespace moteur;
using namespace state;
     
CommandMove::CommandMove(state::Personnage &personnage, state::Cell &position):personnage(personnage),position(position){
   id = MOVE;
}

Json::Value CommandMove::serialize(){
    Json::Value newCommand;
    newCommand["id"]=id;
    return newCommand;
}

void CommandMove::execute(state::State &state){
  cout<< "Move character" <<endl;
  //if(personnage.getPersonnageActif()) //personnage est e statut selectionne
      //personnage.getMoved()
      bool move = true;
      if(move==true){    
        cout<<"The character has been moved" << endl;
      }
      if(move==false){
        cout<<"The character has been moved" << endl;
      }
}
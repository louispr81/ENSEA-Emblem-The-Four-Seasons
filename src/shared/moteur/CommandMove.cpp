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
/*
Json::Value CommandMove::serialize(){
    Json::Value newCommand;
    newCommand["id"]=id;
    return newCommand;
}
*/
void CommandMove::execute(MoveId move){
  cout<< "Move character" <<endl;
      if(currentState->getPersonnageActif()->getMoved()==true){    
        cout<<currentState->getPersonnageActif()->getNom()<<" Can be moved" << endl;
      }
      else{
        cout<<currentState->getPersonnageActif()->getNom()<<"Can not be moved" << endl;
      
      //currentState->getPersonnageActif()->deplacer(x,y);
        std::vector<int> coordonnees;
        coordonnees = currentState->getPersonnageActif()->getCell()->getCoordonees();
        if (move==LEFT){  
            coordonnees[0] = coordonnees[0]-1;         
            currentState->getPersonnageActif()->deplacer(coordonnees[0],coordonnees[1]);
        }
        else if(move==RIGHT){  
            coordonnees[1] = coordonnees[1]-1;  
            currentState->getPersonnageActif()->deplacer(coordonnees[0],coordonnees[1]);
        }
        else if(move==UP){
            coordonnees[0] = coordonnees[0]+1;
            currentState->getPersonnageActif()->deplacer(coordonnees[0],coordonnees[1]);
        }
        else if(move==DOWN){
            coordonnees[1] = coordonnees[1]+1;
            currentState->getPersonnageActif()->deplacer(coordonnees[0],coordonnees[1]);
        }
        else if(move==NONE){
            cout<<"Stay"<<endl;
        }
      }
}

}
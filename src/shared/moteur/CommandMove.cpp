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
      if(currentState->getPersonnageActif()->getMoved()==true){    
        cout<<currentState->getPersonnageActif()->getNom()<<" Can not be moved: NO PM" << endl;
      }
      else{
        cout<<currentState->getPersonnageActif()->getNom()<<" Can be moved" << endl;
      
      //currentState->getPersonnageActif()->deplacer(x,y);
        std::vector<int> coordonnees;
        coordonnees = currentState->getPersonnageActif()->getCell()->getCoordonees();
        if (move==LEFT){  
            coordonnees[0] = coordonnees[0]-1;
            if(coordonnees[0]>=0 and coordonnees[0]<currentState->getPlateau()->getSize()){
              if (coordonnees[1]>=0 and coordonnees[1]<currentState->getPlateau()->getSize()){
                cout<< "Move character" <<endl;
                currentState->getPersonnageActif()->deplacer(coordonnees[0],coordonnees[1]);
              }
              else{
                cout<< "y invalide" <<endl;
              }
            }  
            else{
              cout<< "x invalide" <<endl;
            }       
        }
        else if(move==RIGHT){  
            coordonnees[0] = coordonnees[0]+1;
            if(coordonnees[0]>=0 and coordonnees[0]<currentState->getPlateau()->getSize()){
              if (coordonnees[1]>=0 and coordonnees[1]<currentState->getPlateau()->getSize()){
                cout<< "Move character" <<endl;
                currentState->getPersonnageActif()->deplacer(coordonnees[0],coordonnees[1]);
              }
              else{
                cout<< "y invalide" <<endl;
              }
            }  
            else{
              cout<< "x invalide" <<endl;
            }  
        }
        else if(move==UP){
            coordonnees[1] = coordonnees[1]-1;
            if(coordonnees[0]>=0 and coordonnees[0]<currentState->getPlateau()->getSize()){
              if (coordonnees[1]>=0 and coordonnees[1]<currentState->getPlateau()->getSize()){
                cout<< "Move character" <<endl;
                currentState->getPersonnageActif()->deplacer(coordonnees[0],coordonnees[1]);
              }
              else{
                cout<< "y invalide" <<endl;
              }
            }  
            else{
              cout<< "x invalide" <<endl;
            }
        }
        else if(move==DOWN){
            coordonnees[1] = coordonnees[1]+1;
            if(coordonnees[0]>=0 and coordonnees[0]<currentState->getPlateau()->getSize()){
              if (coordonnees[1]>=0 and coordonnees[1]<currentState->getPlateau()->getSize()){
                cout<< "Move character" <<endl;
                currentState->getPersonnageActif()->deplacer(coordonnees[0],coordonnees[1]);
              }
              else{
                cout<< "y invalide" <<endl;
              }
            }  
            else{
              cout<< "x invalide" <<endl;
            }
        }
        else if(move==NONE){
            cout<<"Stay"<<endl;
        }
      }
}

}
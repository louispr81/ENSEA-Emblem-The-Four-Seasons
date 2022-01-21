#include "HeuristicAI.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
using namespace ai;

HeuristicAI::HeuristicAI(){

}
HeuristicAI::HeuristicAI(moteur::Engine* engine, state::State* state){
    this->engine = engine;
    this->state = state;
}
void HeuristicAI::generateCommand(){
    std::vector<int> position;
    std::vector<int> positionEnemy;
    std::vector<state::Personnage*> personnageAlive;
    state::Joueur* joueurEnemy;
    int signeX,signeY;
    int distanceMin;
    int distanceXmin,distanceYmin;
    int distanceMinIndex;
    int distance,distanceX,distanceY; 
    joueurEnemy = state->getJoueurs()[((state->getJoueur()->getId()-40)+1)%2];
    position = state->getPersonnageActif()->getCell()->getCoordonees();
    cout<<state->getPersonnageActif()->getNom()<<endl;
    for(int i=0;i<joueurEnemy->getPersonnages().size();i++){         
        if(joueurEnemy->getPersonnages()[i]->getAlive()==true){   
            personnageAlive.push_back(joueurEnemy->getPersonnages()[i]);
        }
    }
    for(int i=0;i<personnageAlive.size();i++){                  
        positionEnemy = personnageAlive[i]->getCell()->getCoordonees();
        distanceX = abs(positionEnemy[0]-position[0]);
        distanceY = abs(positionEnemy[1]-position[1]);
        distance = distanceX+distanceY;           
        //find the closest enemy                
        if(i>0 && distance < distanceMin){
            distanceMinIndex = i;
            distanceMin = distance;
            distanceXmin=distanceX;
            distanceYmin=distanceY;
        }
        else if(i==0){
            distanceMinIndex = i;
            distanceMin = distance;
            distanceXmin=distanceX;
            distanceYmin=distanceY;
        }
        else{
            distanceMin = distanceMin;
            distanceXmin=distanceXmin;
            distanceYmin=distanceYmin;
        }
    }
    positionEnemy = personnageAlive[distanceMinIndex]->getCell()->getCoordonees();
    if((positionEnemy[0]-position[0])>=0){  
        signeX = 1;  // x, left
    }
            else{
                signeX = -1; // x, right
            }
            if((positionEnemy[1]-position[1])>=0){
                signeY = 1;  // y, down
            }
            else{
                signeY = -1; // y, up 
            }

    int pm;
    pm=state->getPersonnageActif()->getStatistic()->getPoint_mouvement();
    if(distanceXmin>=0 && distanceYmin>=0){
        if(distanceXmin == 0 && distanceYmin == 1 ){ //up and down
            commandId = 1; //attack
            if(signeY == 1){
                moveId = 4; //down
            }
            else if(signeY == -1){
                moveId = 3; //up
            }
        }
        else if(distanceXmin == 1 && distanceYmin == 0){ //left and right
            commandId = 1;
            if(signeX == 1){
                moveId = 2; //right
            }
            else if(signeX == -1){
                moveId = 1; //left
            }
        }
        else{
            commandId = 0; // move 
            if(pm > 0){
                if(distanceXmin>=distanceYmin && signeX==1 ){  // x > y, dx > 0
                    if(state->getPlateau()->getCase(position[0]+1,position[1])->getOccupe()==false && state->getPlateau()->getCase(position[0]+1,position[1])->getWalkable()==true && pm-state->getPlateau()->getCase(position[0]+1,position[1])->getCostPm()>=0 ){
                        moveId = 2;//RIGHT;
                    }
                    else{
                        moveId = 0;
                        commandId = 2; //attendre
                    }
                }
                else if(distanceXmin>=distanceYmin && signeX==-1 ){  // x > y, dx < 0
                    if(state->getPlateau()->getCase(position[0]-1,position[1])->getOccupe()==false && state->getPlateau()->getCase(position[0]-1,position[1])->getWalkable()==true && pm-state->getPlateau()->getCase(position[0]-1,position[1])->getCostPm()>=0){
                        moveId = 1;//LEFT;
                    }
                    else{
                        moveId = 0;
                        commandId = 2;
                    }                  
                }
                else if(distanceXmin<=distanceYmin && signeY==1 ){  // x < y, dx > 0
                    if(state->getPlateau()->getCase(position[0],position[1]+1)->getOccupe()==false && state->getPlateau()->getCase(position[0],position[1]+1)->getWalkable()==true && pm-state->getPlateau()->getCase(position[0],position[1]+1)->getCostPm()>=0){
                        moveId = 4;//DOWN;
                    }
                    else{
                        moveId = 0;
                        commandId = 2;                        
                    }
                }
                else if(distanceXmin<=distanceYmin && signeY==-1 ){  // x < y, dx < 0
                    if(state->getPlateau()->getCase(position[0],position[1]-1)->getOccupe()==false && state->getPlateau()->getCase(position[0],position[1]-1)->getWalkable()==true && pm-state->getPlateau()->getCase(position[0],position[1]-1)->getCostPm()>=0){
                        moveId = 3;//UP;
                    }
                    else{
                        moveId = 0;
                        commandId = 2;
                    }
                }
            }
            else{
                commandId = 2; //attendre
                moveId = 0;
            }
        }
    }
    else{
        cout << "distance error"<<endl;
    }
}
int HeuristicAI::getMoveId(){
    return moveId;
}

int HeuristicAI::getCommandId(){
    return commandId;
}

HeuristicAI::~HeuristicAI(){

}
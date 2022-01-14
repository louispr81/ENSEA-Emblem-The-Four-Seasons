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
    std::vector<int> distanceEnemy;
    state::Joueur* joueurEnemy;
    int signeX,signeY;
    int distanceMin;
    int distanceXmin,distanceYmin;
    int distanceMinIndex;
    joueurEnemy = state->getJoueurs()[((state->getJoueur()->getId()-40)+1)%2];
    position = state->getPersonnageActif()->getCell()->getCoordonees();
    for(int i=0;i<joueurEnemy->getPersonnages().size();i++){
        if(joueurEnemy->getPersonnages()[i]->getAlive()==true){
            int distance,distanceX,distanceY;            
            positionEnemy = joueurEnemy->getPersonnages()[i]->getCell()->getCoordonees();
            distanceX = abs(positionEnemy[0]-position[0]);
            distanceY = abs(positionEnemy[1]-position[1]);
            if((positionEnemy[0]-position[0])>0){  
                signeX = 1;  // x, left
            }
            else{
                signeX = -1; // x, right
            }
            if((positionEnemy[1]-position[1])>0){
                signeY = 1;  // y, down
            }
            else{
                signeY = -1; // y, up 
            }
            distance = sqrt(pow(distanceX,2)+pow(distanceY,2));
            distanceEnemy.push_back(distance);
            distanceMin = distanceEnemy[0];
            //find the closest enemy
            if(i>0 && distanceEnemy[i]<distanceMin){
                distanceMinIndex = i;
                distanceMin = distanceEnemy[i];
                distanceXmin=distanceX;
                distanceYmin=distanceY; 
            }
        }
    }

    int pm;
    pm=state->getPersonnageActif()->getStatistic()->getPoint_mouvement();
    if(distanceXmin>0 && distanceYmin>0){
        if((distanceXmin == 0 && distanceYmin == 1) || (distanceXmin == 1 && distanceYmin == 0)){
            commandId = 1; //attack
            if(signeX == 1){
                moveId = 2; 
            }
            else{
                moveId = 1;
            }
            if(signeY == 1){
                moveId = 4;
            }
            else{
                moveId = 3;
            }
        }
        else{
            commandId = 1; // move 
            if(pm > 0){
                if(distanceXmin>distanceYmin && signeX==1 ){  // x > y, dx > 0
                    if(state->getPlateau()->getCase(position[0]+1,position[1])->getOccupe()==false){
                        moveId = 2;//RIGHT;
                        pm = pm-1;
                    }
                    else{
                        moveId = 0;
                        commandId = 2;
                    }
                }
                if(distanceXmin>distanceYmin && signeX==-1 ){  // x > y, dx < 0
                    if(state->getPlateau()->getCase(position[0]-1,position[1])->getOccupe()==false){
                        moveId = 1;//LEFT;
                        pm = pm-1;
                    }
                    else{
                        moveId = 0;
                        commandId = 2;
                    }
                   
                }
                if(distanceXmin<distanceYmin && signeX==1 ){  // x < y, dx > 0
                    if(state->getPlateau()->getCase(position[0],position[1]+1)->getOccupe()==false){
                        moveId = 4;//DOWN;
                        pm = pm-1;
                    }
                    else{
                        moveId = 0;
                        commandId = 2;                        
                    }
                }
                if(distanceXmin<distanceYmin && signeX==-1 ){  // x < y, dx < 0
                    if(state->getPlateau()->getCase(position[0],position[1]-1)->getOccupe()==false){
                        moveId = 3;//UP;
                        pm = pm-1;
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
        cout << "diatance error"<<endl;
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
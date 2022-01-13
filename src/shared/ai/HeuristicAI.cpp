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

    commandId = 1; // move
    position = state->getPersonnageActif()->getCell()->getCoordonees();
    for(int i=0;i<joueurEnemy->getPersonnages().size();i++){
        if(joueurEnemy->getPersonnages()[i]->getAlive()==true){
            int distance,distanceX,distanceY;            
            distanceMin = distanceEnemy[0];            
            positionEnemy = joueurEnemy->getPersonnages()[i]->getCell()->getCoordonees();
            distanceX = abs(positionEnemy[0]-position[0]);
            distanceY = abs(positionEnemy[1]-position[1]);
            if((positionEnemy[0]-position[0])>0){
                signeX = 1;
            }
            else{
                signeX = -1;
            }
            if((positionEnemy[1]-position[1])>0){
                signeY = 1;
            }
            else{
                signeY = -1;
            }
            distance = sqrt(pow(distanceX,2)+pow(distanceY,2));
            distanceEnemy.push_back(distance);
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
    
    while(pm>0){
        if(distanceXmin>distanceYmin){
            
        }
    }
    
    //state->getPersonnageActif()->deplacer((position[0]+(signeX)*distanceXmin),(position[1]+(signeY)*distanceYmin));


}
int HeuristicAI::getMoveId(){
    return moveId;
}

int HeuristicAI::getCommandId(){
    return commandId;
}

HeuristicAI::~HeuristicAI(){

}
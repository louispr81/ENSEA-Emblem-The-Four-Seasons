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
    joueurEnemy = state->getJoueurs()[((state->getJoueur()->getId()-40)+1)%2];


//https://en.cppreference.com/w/cpp/algorithm/max_element

    if(state->getPersonnageActif()->getStatistic()->getPoint_movement()>0){
        position = state->getPersonnageActif()->getCell()->getCoordonees();
        for(int i=0;i<joueurEnemy->getPersonnages().size();i++){
            if(joueurEnemy->getPersonnages()[i]->getAlive()==true){
                int distanceX;
                int distanceY;
                int distance;
                positionEnemy = joueurEnemy->getPersonnages()[i]->getCell()->getCoordonees();
                distanceX = abs(positionEnemy[0]-position[0]);
                distanceY = abs(positionEnemy[1]-position[1]);
                distance = sqrt(pow(distanceX,2)+pow(distanceY,2));
            //    distanceEnemy.push_back(distance);
            //    if(joueurEnemy->getPersonnages[i])
            //    positionEnemy = joueurEnemy->getPersonnages()[i]->getCell()->getCoordonees();
            }
        }
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
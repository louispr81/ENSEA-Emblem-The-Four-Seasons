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
    state::Joueur* joueurEnemy;
    int signeX,signeY;
    int distanceMin;
    int distanceXmin,distanceYmin;
    int distanceMinIndex;
    int distance,distanceX,distanceY; 
    joueurEnemy = state->getJoueurs()[((state->getJoueur()->getId()-40)+1)%2];
    position = state->getPersonnageActif()->getCell()->getCoordonees();
    for(int i=0;i<joueurEnemy->getPersonnages().size();i++){         
        if(joueurEnemy->getPersonnages()[i]->getAlive()==true){                     
            positionEnemy = joueurEnemy->getPersonnages()[i]->getCell()->getCoordonees();
            distanceX = abs(positionEnemy[0]-position[0]);
            distanceY = abs(positionEnemy[1]-position[1]);
            std::cout<<"xEnemy="<<positionEnemy[0]<<std::endl;
            std::cout<<"yEnemy="<<positionEnemy[1]<<std::endl;
            std::cout<<"xPlayer="<<position[0]<<std::endl;
            std::cout<<"yPlayer="<<position[1]<<std::endl;
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
            distance = sqrt(pow(distanceX,2)+pow(distanceY,2));           
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
    }
        cout << "distanceY avant = " << distanceYmin << endl;
        cout << "distanceX avant = " << distanceXmin << endl;
        cout << "signeX = "<< signeX << endl;
        cout << "signeY = "<< signeY << endl;
        cout << "enemy = "<<distanceMinIndex<<endl;
        

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
            cout << "dx=" <<distanceXmin<<endl;
            cout << "dy=" <<distanceYmin<<endl;
            cout << "signeX=" <<signeX<<endl;
            cout << "signeY=" <<signeY<<endl;
            commandId = 0; // move 
            if(pm > 0){
                if(distanceXmin>=distanceYmin && signeX==1 ){  // x > y, dx > 0
                cout <<"move"<<endl;
                    if(state->getPlateau()->getCase(position[0]+1,position[1])->getOccupe()==false && state->getPlateau()->getCase(position[0]+1,position[1])->getWalkable()==true){
                        moveId = 2;//RIGHT;
                    }
                    else{
                        moveId = 0;
                        commandId = 2; //attendre
                    }
                }
                else if(distanceXmin>=distanceYmin && signeX==-1 ){  // x > y, dx < 0
                    if(state->getPlateau()->getCase(position[0]-1,position[1])->getOccupe()==false && state->getPlateau()->getCase(position[0]-1,position[1])->getWalkable()==true){
                        moveId = 1;//LEFT;
                    }
                    else{
                        moveId = 0;
                        commandId = 2;
                    }                  
                }
                else if(distanceXmin<=distanceYmin && signeY==1 ){  // x < y, dx > 0
                    if(state->getPlateau()->getCase(position[0],position[1]+1)->getOccupe()==false && state->getPlateau()->getCase(position[0],position[1]+1)->getWalkable()==true){
                        moveId = 4;//DOWN;
                    }
                    else{
                        moveId = 0;
                        commandId = 2;                        
                    }
                }
                else if(distanceXmin<=distanceYmin && signeY==-1 ){  // x < y, dx < 0
                    if(state->getPlateau()->getCase(position[0],position[1]-1)->getOccupe()==false && state->getPlateau()->getCase(position[0],position[1]-1)->getWalkable()==true){
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
        cout << "distanceY = " << distanceYmin << endl;
        cout << "distanceX = " << distanceXmin << endl;

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
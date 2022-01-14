#include "RandomAI.h"
#include <iostream>

using namespace std;
using namespace state;
using namespace moteur;
using namespace ai;

RandomAI::RandomAI(Engine* engine){
    this->engine=engine;
}
 
void RandomAI::generateCommand(){
    //[a,b]  (rand() % (b-a+1))+ a 
    this->commandId=(rand() % (engine->getListCommand().size()));    
    if(this->commandId == 0 || this->commandId == 1){
        this->moveId=(rand() % 4)+1;
    }
    else{
        this->moveId=0;
    }       
}
int RandomAI::getCommandId(){
    return this->commandId;
}
int RandomAI::getMoveId(){
    return this->moveId;
}


RandomAI::~RandomAI(){

}

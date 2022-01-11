#include "RandomAI.h"
#include <iostream>

using namespace std;
using namespace state;
using namespace moteur;
using namespace ai;

RandomAI::RandomAI(){

}
 
void RandomAI::generateCommand(){
    //[a,b]  (rand() % (b-a+1))+ a 
    cout<<"1"<<std::endl;
    this->commandId=(rand() % (engine->getListCommand().size()));    
    cout<<"2"<<std::endl;
    this->moveId=(rand() % 5); 
    cout<<"3"<<std::endl;
    if(this->commandId == 0 || this->commandId == 1){
        cout<<"4"<<std::endl;
        this->moveId=(rand() % 4)+1;
    }       
    cout<<"IA OK"<<std::endl;
}
int RandomAI::getCommandId(){
    return this->commandId;
}
int RandomAI::getMoveId(){
    return this->moveId;
}


RandomAI::~RandomAI(){

}

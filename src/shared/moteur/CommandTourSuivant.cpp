/*
#include "CommandToursuivant.h"
#include <string>
#include <iostream>

using namespace std;
using namespace moteur;
using namespace state;

CommandTourSuivant::CommandTourSuivant(){
    id=FINTOUR;
}
Json::Value CommandTourSuivant::serialize(){
    Json::Value newCommand;
    newCommand["id"]=id;
    return newCommand;
}
void CommandTourSuivant::execute (state::State &state){

}
*/
#include "Client.h"
#include <iostream>
using namespace client;
using namespace state;
using namespace moteur;

Client::Client (){
    State* state=new State(17);
    Engine* engine=new Engine(/*state,currentCommands*/);
    this->engine=engine;
    this->state=state;
}

void Client::run(){
    int cmd;
    std::cout<<"Liste des commandes:\n"<<"ATTACK=0"<<std::endl<<"MOVE=1"<<std::endl<<"WAIT=2"<<std::endl;
    std::cout<<"\n";
    while(1){
        std::cout<<state->getJoueur()->getNom()<< " quelle commande voulez faire avec "<<state->getPersonnageActif()->getNom()<<" ?"<<std::endl;
        std::cin>>cmd;
        std::cout<<"\n";
        std::cout<<cmd<<" va être éxécutée"<<std::endl;
        //this->engine->update(cmd);
    }
}
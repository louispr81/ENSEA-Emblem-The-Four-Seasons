#include "Client.h"
#include <iostream>
using namespace client;
using namespace state;
using namespace moteur;
using namespace render;

Client::Client (){
    State* state=new State(17);
    Engine* engine=new Engine(/*state,currentCommands*/);
    sf::Vector2u tileSize = sf::Vector2u(32,32);
    StateLayer* render = new StateLayer(tileSize, 17, 17, state);
    this->engine=engine;
    this->state=state;
    this->render=render;
}

void Client::run(){
    int cmd;
    std::cout<<"Liste des commandes:\n"<<"ATTACK=0"<<std::endl<<"MOVE=1"<<std::endl<<"WAIT=2"<<std::endl;
    std::cout<<"\n";
    render->windowInit();
    while(1){
        render->windowPersonnages(); 
        std::cout<<state->getJoueur()->getNom()<< " quelle commande voulez vous faire avec "<<state->getPersonnageActif()->getNom()<<" ?"<<std::endl;
        std::cin>>cmd;
        std::cout<<"\n";
        std::cout<<cmd<<" va être éxécutée"<<std::endl;
        //this->engine->update(cmd);
    }
}
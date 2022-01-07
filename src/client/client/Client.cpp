#include "Client.h"
#include <iostream>
using namespace client;
using namespace state;
using namespace moteur;
using namespace render;

Client::Client (){
    State* state=new State(17);
    Engine* engine=new Engine(state);
    sf::Vector2u tileSize = sf::Vector2u(32,32);
    StateLayer* render = new StateLayer(tileSize, 17, 17, state);
    this->engine=engine;
    this->state=state;
    this->render=render;
}

void Client::run(){
    sf::Event event;
    int cmd;
    render->windowInit();
    while (render->getWindow()->isOpen()){
        while (render->getWindow()->pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    render->getWindow()->close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code){
                        case sf::Keyboard::Escape:
                            std::cout << "the Escape key was pressed" << std::endl;
                            break;
                        case sf::Keyboard::A:
                            std::cout << "the A key was pressed" << std::endl;
                            engine->update(ATTENDRE,NONE);
                            render->windowPersonnages();
                            break;
                        case sf::Keyboard::Up:
                            std::cout << "the Up key was pressed" << std::endl;
                            render->windowPersonnages();
                            break;
                        case sf::Keyboard::Left:
                            std::cout << "the Left key was pressed" << std::endl;
                            render->windowPersonnages();
                            break; 
                        case sf::Keyboard::Right:
                            std::cout << "the Right key was pressed" << std::endl;
                            render->windowPersonnages();
                            break;
                        case sf::Keyboard::Down:
                            std::cout << "the Down key was pressed" << std::endl;
                            render->windowPersonnages();
                            break;
                        case sf::Keyboard::Z:
                            std::cout << "the Z key was pressed" << std::endl;
                            engine->update(MOVE,UP);
                            render->windowPersonnages();                            
                            break;
                        case sf::Keyboard::Q:
                            std::cout << "the Q key was pressed" << std::endl;
                            engine->update(MOVE,LEFT);
                            render->windowPersonnages();
                            break; 
                        case sf::Keyboard::D:
                            std::cout << "the D key was pressed" << std::endl;
                            engine->update(MOVE,RIGHT);
                            render->windowPersonnages();
                            break;
                        case sf::Keyboard::S:
                            std::cout << "the S key was pressed" << std::endl;
                            engine->update(MOVE,DOWN);
                            render->windowPersonnages();
                            break; 
                        default:
                            break;       
                    }
                    break;
                default:
                    break;
            }
        }
    }
    /*
    while(render->getWindow()->isOpen()){
        render->windowPersonnages(); 
        std::cout<<state->getJoueur()->getNom()<< " quelle commande voulez vous faire avec "<<state->getPersonnageActif()->getNom()<<" ?"<<std::endl;
        std::cin>>cmd;
        std::cout<<"\n";
        std::cout<<cmd<<" va être éxécutée"<<std::endl;
        //this->engine->update(cmd);
    }*/
}
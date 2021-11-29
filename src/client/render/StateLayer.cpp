#include "StateLayer.h"
#include <iostream>
using namespace render;
using namespace state;

StateLayer::StateLayer(sf::Vector2u tileSize, unsigned int width, unsigned int height, state::State* state){
    (*this).tileSize=tileSize;
    (*this).width=width;
    (*this).height=height;
    (*this).state=state;
}

std::vector<int> StateLayer::getPlateauIdFromState (){
    std::vector<int> plateauId;
    Plateau* pPlateau=(*(*this).state).getPlateau();
    int res;
    int size = pPlateau->getSize();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            res=((*pPlateau).getCase(j,i)).getType();
            plateauId.push_back(res-10);
        }
    }
    return plateauId;
}
std::vector<int> StateLayer::getPlateauId (){
    return (*this).plateauId;
}

state::State* StateLayer::getState (){
    return (*this).state;
}

void StateLayer::setState (state::State* state){
    (*this).state=state;
}

void StateLayer::window(){
    // on crée la fenêtre
    (*this).plateauId=(*this).getPlateauIdFromState();
    sf::RenderWindow window(sf::VideoMode((*this).width*tileSize.x, (*this).height*tileSize.y), "Tilemap");
    Surface map;
    float scaleY;
    float scaleX;
    map.load("res/cases.png", (*this).tileSize, (*this).plateauId, (*this).width, (*this).height);
    while (window.isOpen()){
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }
}

/*
int main()
{
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // on définit le niveau à l'aide de numéro de tuiles
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}
*/
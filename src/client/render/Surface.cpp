#include "Surface.h"
#include <iostream>
using namespace render;
using namespace std;


bool Surface::load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)

{
    static sf::Texture m_tileset;
    static sf::VertexArray m_vertices;
    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // on récupère le numéro de tuile courant
            int tileNumber = tiles[i + j * width];

            // on en déduit sa position dans la texture du tileset
            //int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            //int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tileNumber * 128, 0);
            quad[1].texCoords = sf::Vector2f((tileNumber + 1) * 128, 0);
            quad[2].texCoords = sf::Vector2f((tileNumber + 1) * 128, 128);
            quad[3].texCoords = sf::Vector2f(tileNumber * 128,  128);
        }
    this->m_tileset=m_tileset;
    this->m_vertices=m_vertices;
    return true;
}

bool Surface::loadStat(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height){
    static sf::Texture m_tileset;
    static sf::VertexArray m_vertices;
    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize((width * height * 4 ) + 4);

    sf::Vertex* quad = &m_vertices[(17 + 17* width) * 4];
    // on définit ses quatre coins
    /*
    quad[0].position = sf::Vector2f((width+1)*tileSize.x,0);
    quad[1].position = sf::Vector2f((1.5*width) * tileSize.x, 0);
    quad[2].position = sf::Vector2f((1.5*width) * tileSize.x, (height + 1) * tileSize.y);
    quad[3].position = sf::Vector2f((width+1)*tileSize.x, (height + 1) * tileSize.y);
*/

    quad[0].position = sf::Vector2f(0,0);
    quad[1].position = sf::Vector2f(10, 0);
    quad[2].position = sf::Vector2f(10, 10);
    quad[3].position = sf::Vector2f(0,10);
            std::cout<<"000000000000="<<width*tileSize.x<<std::endl;
            std::cout<<"111111111111="<<(1.5*width) * tileSize.x<<std::endl;
            std::cout<<"222222222222="<<height * tileSize.y<<std::endl;
         
    // on définit ses quatre coordonnées de texture
    quad[0].texCoords = sf::Vector2f(0, 0);
    quad[1].texCoords = sf::Vector2f(344, 0);
    quad[2].texCoords = sf::Vector2f(344, 462);
    quad[3].texCoords = sf::Vector2f(0,  462);


    this->m_tileset=m_tileset;
    this->m_vertices=m_vertices;
    return true;
}

void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    // on applique la transformation
    states.transform *= getTransform();

    // on applique la texture du tileset
    states.texture = &(this->m_tileset);

    // et on dessine enfin le tableau de vertex

    target.draw(this->m_vertices, states);
}


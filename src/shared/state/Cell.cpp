#include "Cell.h"
using namespace state;

 Cell::Cell (Personnage* personnage, CellId type, std::vector<int> coordonees, bool walkable, int costPm, bool occupe){

    (*this).personnage=personnage;
    (*this).type=type;
    (*this).coordonees=coordonees;
    (*this).walkable=walkable;
    (*this).costPm=costPm;
    (*this).occupe=occupe;
 }



CellId Cell::getType (){
    return (*this).type;
}


int Cell::getCostPm (){
   return (*this).costPm;
}


void Cell::setCostPm (int costPm){
    (*this).costPm=costPm;
}

void Cell::setPersonnage (Personnage* personnage){
    (*this).personnage=personnage;
}

void Cell::setOccupe (bool occupe){
    (*this).occupe=occupe;
}

void Cell::setWalkable (bool walkable){
    (*this).walkable=walkable;

}

bool Cell::getWalkable (){
    return (*this).walkable;
}

void Cell::setCoordonnees (std::vector<int> coordonnees){
    (*this).coordonees=coordonees;
}

std::vector<int> Cell::getCoordonees(){
    return (*this).coordonees=coordonees;
}

bool Cell::getOccupe(){
    return (*this).occupe;
}
Cell::~Cell (){
    
}
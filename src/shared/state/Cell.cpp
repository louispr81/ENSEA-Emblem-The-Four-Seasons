#include "Cell.h"
#include <iostream>
using namespace state;

 Cell::Cell (Personnage* personnage, CellId type, std::vector<int> coordonees, Cell* ptCell, bool walkable, int costPm, bool occupe){

    (*this).personnage=personnage;
    (*this).type=type;
    (*this).coordonees=coordonees;
    (*this).walkable=walkable;
    (*this).costPm=costPm;
    (*this).occupe=occupe;
    (*this).ptCell=ptCell;
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

Cell* Cell::getPtCell (){
    return (*this).ptCell;
}

void Cell::setCoordonnees (std::vector<int> coordonnees){
    (*this).coordonees=coordonees;
}

std::vector<int> Cell::getCoordonees(){
    return (*this).coordonees=coordonees;
}

void Cell::setPtCell (Cell* ptCell){
    (*this).ptCell=ptCell;
}

bool Cell::getOccupe(){
    return (*this).occupe;
}

void Cell::print(){
    std::cout<<"---------------CELL---------------"<<std::endl;
    std::cout<<"ptCell="<<this->ptCell<<std::endl;
    std::cout<<"( x="<<this->getCoordonees()[0]<<";y="<<this->getCoordonees()[1]<<")"<<std::endl;
    std::cout<<"type="<<this->type<<std::endl;
    std::cout<<"costPm="<<this->costPm<<std::endl;
    std::cout<<"walkable="<<this->walkable<<std::endl;
    std::cout<<"occupe="<<this->occupe<<std::endl;
    std::cout<<"personnage="<<this->personnage<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;
}

Cell::~Cell (){
    
}
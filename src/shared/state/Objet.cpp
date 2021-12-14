#include "Objet.h"
#include <iostream>

using namespace state;

Objet::Objet(){

}
int Objet::getId() const{
    return (*this).id;
}
void Objet::setId(int id){

}
int Objet::getDurabilite() const{
    return (*this).durabilite;
}
void Objet::setDurabilite(int durabilite){

}
bool Objet::getUsable() const{
    return (*this).usable;
} 
void Objet::setUsable(bool usable){

}
ObjetId Objet::getObjetId() const{
    return (*this).objetId;
}
void Objet::setObjetId(ObjetId objetId){
    this->objetId=objetId;
}
void Objet::print(){
    std::cout<<"---------------OBJET---------------"<<std::endl;
    std::cout<<"nom="<<this->nom<<std::endl;
    std::cout<<"type="<<this->objetId<<std::endl;
    std::cout<<"id="<<this->id<<std::endl;
    std::cout<<"durabilite="<<this->durabilite<<std::endl;
    std::cout<<"usable="<<this->usable<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;
}
Objet::~Objet(){    

}
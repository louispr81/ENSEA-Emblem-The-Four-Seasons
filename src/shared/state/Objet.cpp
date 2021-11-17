#include "Objet.h"

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

}
Objet::~Objet(){    

}
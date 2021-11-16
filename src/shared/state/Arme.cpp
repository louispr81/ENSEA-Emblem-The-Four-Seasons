#include "Arme.h"
using namespace state;

Arme::Arme (std::string nom, int id, int durabilite, bool usable, ObjetId objetId, int degats, int critique, int range, int precision){
    (*this).nom=nom;
    (*this).id=id;
    (*this).durabilite=durabilite;
    (*this).usable=usable;
    (*this).objetId=objetId;
    (*this).degats=degats;
    (*this).critique=critique;
    (*this).range=range;
    (*this).precision=precision;
}
int Arme::getDegats (){
    return (*this).degats;
}
int Arme::getCritique (){
    return (*this).critique;
}
int Arme::getRange (){
    return (*this).range;
}
int Arme::getPrecision (){
    return (*this).precision;
}

Arme::~Arme(){
    
}
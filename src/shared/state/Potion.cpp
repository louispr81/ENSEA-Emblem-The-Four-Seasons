#include "Potion.h"
using namespace state;

Potion::Potion(int id,int soin,ObjetId objetId,std::string nom, int durabilite, bool usable){
    (*this).id = id;
    (*this).soin = soin;
    (*this).objetId = objetId;
    (*this).nom = nom;
    (*this).durabilite = durabilite;
    (*this).usable = usable;
}

int Potion::getSoin(){

    return (*this).soin;
}

/*
Potion::~Potion(){

}
*/
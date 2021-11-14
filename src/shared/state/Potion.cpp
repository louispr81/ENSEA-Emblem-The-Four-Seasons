#include "Potion.h"
using namespace state;

Potion::Potion(int id,int soin,ObjetId objetId,std::string nom, int durabilite, bool usable){
    (*this).id = id;
    (*this).soin = soin;
    (*this).objetId = objetId;
    (*this).nom = "potion";
    (*this).durabilite = 3;
    (*this).usable = true;
}

int Potion::getSoin(){

    return (*this).soin;
}

/*
Potion::~Potion(){

}
*/
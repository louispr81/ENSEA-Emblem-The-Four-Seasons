#include "Joueur.h"

using namespace state;

Joueur::Joueur(std::string nom,JoueurId id, std::vector<Personnage> personnages){
    (*this).nom = nom;
    (*this).id = id;
    (*this).personnages = personnages;
}
std::vector<Personnage> Joueur::getPersonnages(){
    
    return this->personnages;
}
int Joueur::getId(){

    return this->id;
}
std::string getNom(){

    return this->nom;
}

Joueur::~Joueur(){
    
}
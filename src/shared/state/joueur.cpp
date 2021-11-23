#include "Joueur.h"

using namespace state;

Joueur::Joueur(std::string nom,JoueurId id, std::vector<Personnage*> personnages){
    (*this).nom = nom;
    (*this).id = id;
    (*this).personnages = personnages;
}
std::vector<Personnage*> Joueur::getPersonnages(){
    
    return (*this).personnages;
}
JoueurId Joueur::getId(){

    return (*this).id;
}
std::string Joueur::getNom(){

    return (*this).nom;
}

Joueur::~Joueur(){
    
}
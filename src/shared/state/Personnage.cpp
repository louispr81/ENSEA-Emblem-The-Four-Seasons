#include "Personnage.h" 
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace state;

Personnage::Personnage(std::string nom, int id, Statistiques statistiquesBase, std::vector<Objet> inventaire, Arme* arme, Classe* classe, Saison* saison, Cell* cell, std::vector<int> bonus, Statistiques statistiques, bool played , bool alive ){
    (*this).nom=nom;
    (*this).id=id;
    (*this).statistiquesBase=statistiquesBase;
    (*this).arme=arme;
    inventaire.push_back((*this).arme);
    (*this).inventaire=inventaire;
    (*this).classe=classe;
    (*this).saison=saison;
    (*this).cell=cell;
    (*this).bonus=bonus;
    (*this).statistiques=statistiques;
    (*this).played=played;
    (*this).alive=alive;
}

Saison Personnage::getSaison(){
    return *((*this).saison);
}
void Personnage::setBonus(std::vector<int> x){

}

void Personnage::attendre(){ 
    if ((*this).played != true){
        (*this).statistiques.setPoint_mouvement(0);
        (*this).played=true;
    }
}
/* 
void Personnage::ouvrirCoffre(){ 
    if (Personnage.getCell().getType()==CHEST){
        //choose a random weapon 
        tab_arme = new char[5] {TOME,LANCE,HACHE,EPEE,ARC,POTION};
        srand((unsigned)time(NULL));
        for(int i=0; i<5;i++){
            choix_arme_num=rand()%6+0;
        }
        this->ObjetId=tab_arme[choix_arme_num];
        Personnage.inventaireAdd(Objet objet(ObjetId)); // Il faut rajouter un constructeur qui crée un objet grâce à l'id
    }
    CellId=GRASS; 
    this->played = true;
} 
*/
/*
void Personnage::echangerObjet(Personnage personnageB, Objet objet){
    if (Personnage.getCell()=Personnage.getCell().personnageB)    
    this->played = true;
}
*/

Personnage::~Personnage(){
   // delete[] tab_arme;
}



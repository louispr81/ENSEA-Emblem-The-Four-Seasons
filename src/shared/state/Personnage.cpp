#include "Personnage.h" 
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace state;

void Personnage::Personnage(){

}
void Personnage::attendre(){ 
    if ((*this).played != true){
        (*this).statistiques.setPoint_mouvement(0);
        (*this).played=true;
    }
}

void Personnage::deplacer(){

}
void Personnage::attaquer(){

}
void Personnage::utiliserPotion(){

}
void Personnage::pouvoir(){

}
void Personnage::gainNiveau(){

}
void Personnage::ouvrirCoffre(){
if (CellId == CHEST){    
    if (Personnage.getCell().getType()=CHEST){
        //choose a random weapon 
        tab_arme = new char[5] {TOME,LANCE,HACHE,EPEE,ARC,POTION};
        srand((unsigned)time(NULL));
        for(int i=0; i<5;i++){
            choix_arme_num=rand()%6+0;
        }
        this->ObjetId=tab_arme[choix_arme_num];
        Personnage.inventaireAdd(this->ObjetId);
    }
    CellId=GRASS; 
    this->played = true;
}      
void Personnage::echangerObjet(){
    if (Personnage.getCell()=)
}

void Personnage::~Personnage(){
    delete[] tab_arme;
}



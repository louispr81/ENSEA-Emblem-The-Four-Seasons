#include "Personnage.h" 
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace state;
using namespace std;


Personnage::Personnage(std::string nom, int id, Statistiques statistiquesBase, std::vector<Objet*> inventaire, Arme* arme, Classe* classe, Saison* saison, Cell* cell, std::vector<int> bonus, Statistiques statistiques, Plateau* plateau, bool played, bool alive){
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
    (*this).plateau=plateau;
    (*this).played=played;
    (*this).alive=alive;
    (*this).plateau=plateau;
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


int Personnage::deplacer(int x1, int y1){

    
    int reply;
     std::vector<int> coordonne_a ,coordonne_destination,coordonne_1,coordonne_2,coordonne_3,coordonne_4;
    
    coordonne_a=(*((*this).cell)).getCoordonees(); // coordonees du personnage 
    coordonne_destination=this->plateau->getCase(x1,y1).getCoordonees();
     
    coordonne_1[0]=coordonne_a[0]-1;       // coordonees de la case à gauche du personage
    coordonne_1[1]=coordonne_a[1];        

    coordonne_2[0]=coordonne_a[0];       // coordonees de la case devant le personage
    coordonne_2[1]=coordonne_a[1]+1;

    coordonne_3[0]=coordonne_a[0]+1;    // coordonees de la case à droite le personage
    coordonne_3[1]=coordonne_a[1];

    coordonne_4[0]=coordonne_a[0];      // coordoness de la case derriere le personnage 
    coordonne_4[1]=coordonne_a[1]-1;


   

    if (coordonne_a==coordonne_destination){
        cout<< " le personnage ne bouge pas "<<endl;
        reply=1;
    }




     if (coordonne_destination==coordonne_1 ){
        if(this->plateau->getCase(coordonne_1[0],coordonne_1[1]).getWalkable()==true){
            if(this->plateau->getCase(coordonne_1[0],coordonne_1[1]).getOccupe()==false){
                 if((*this).statistiques.getPoint_mouvement()>=1){
                    (*((*this).cell)).getCoordonees()=coordonne_1;
                    (*this).statistiques.setPoint_mouvement((*this).statistiques.getPoint_mouvement()-1);
                  reply=1;
                 }
            }

        }
    }


    if (coordonne_destination==coordonne_2 ){
        if(this->plateau->getCase(coordonne_2[0],coordonne_2[1]).getWalkable()==true){
            if(this->plateau->getCase(coordonne_2[0],coordonne_2[1]).getOccupe()==false){
                if((*this).statistiques.getPoint_mouvement()>=1){  
                    (*((*this).cell)).getCoordonees()=coordonne_2;
                    (*this).statistiques.setPoint_mouvement((*this).statistiques.getPoint_mouvement()-1);
                    reply=1;
                }
            }

        }
    }



if (coordonne_destination==coordonne_3 ){
        if(this->plateau->getCase(coordonne_3[0],coordonne_3[1]).getWalkable()==true){
            if(this->plateau->getCase(coordonne_3[0],coordonne_3[1]).getOccupe()==false){
                if((*this).statistiques.getPoint_mouvement()>=1){
                    (*((*this).cell)).getCoordonees()=coordonne_3;
                    (*this).statistiques.setPoint_mouvement((*this).statistiques.getPoint_mouvement()-1);
                    reply=1;
                }
            }

        }
    }


if (coordonne_destination==coordonne_4 ){
        if(this->plateau->getCase(coordonne_4[0],coordonne_4[1]).getWalkable()==true){
            if(this->plateau->getCase(coordonne_4[0],coordonne_4[1]).getOccupe()==false){
                if((*this).statistiques.getPoint_mouvement()>=1){
                    (*((*this).cell)).getCoordonees()=coordonne_4;
                    (*this).statistiques.setPoint_mouvement((*this).statistiques.getPoint_mouvement()-1);
                    reply=1;
                }
            }

        }
    }





    else {
        cout<< " la case n'est pas disponible "<<endl;
        reply = -1;
    }   
 return reply;
}



Personnage::~Personnage(){
   // delete[] tab_arme;
}



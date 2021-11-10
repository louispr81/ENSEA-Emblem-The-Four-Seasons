// my_class.cpp
#include "Jeu.h" // header in local directory
#include "Joueur.h"
#include "Saison.h"
#include "Plateau.h"
#include <iostream> // header in standard library
#include <string>
using namespace state;
using namespace std;


Jeu::Jeu(){
    std::vector<Joueur> joueurs;
    int tour     = 1;
    bool gameover     = false;
    Joueur joueur1;
    Joueur joueur2;
    Saison saison;
    Plateau plateau1;
  
   
}


string Joueur::getNom(){
    return (*this).nom;
};



void Jeu::tourSuivant(){
   if ((*this).gameover== false ){
    (*this).tour++;
    
    
    }
};

void Jeu::abandonner (Joueur joueur){
    if ((*this).gameover== false){
     (*this).gameover     = true;
     
     cout<<"le joueur: "<<joueur.getNom()<<" a abandonné la partie "<< endl;
    }
    
};
    void Jeu::updateSaison (){
        
        if ((*this).gameover== false){
            if((*this).saison.getId() ==printemps){
               // (*this).saison=ete;
           }
           if((*this).saison.getId() == ete){
               // (*this).saison=automne;                         //les objets printemps ,automne,ete,hiver
           }                                                      // sont à créer !!
           if((*this).saison.getId() == automne){   
               // (*this).saison=hiver;
           }
           if((*this).saison.getId() == hiver){
               // (*this).saison=printemps; 
           }
        }
        

    };


Jeu::~Jeu(){

}
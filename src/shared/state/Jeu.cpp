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
    saison.nom ="automne"  ;
    Plateau plateau1;
  
   
}

void Jeu::tourSuivant(){
   if ((*this).gameover== false ){
    tour++;
    }
};

void Jeu::abandonner (){
    if ((*this).gameover== false){
     gameover     = true;
    }
    
};
    void Jeu::updateSaison (){
        if ((*this).gameover== false){
            if((*this).saison.nom == "automne"){
                (*this).saison.nom ="hiver";
           }
        }

    };


Jeu::~Jeu(){

}
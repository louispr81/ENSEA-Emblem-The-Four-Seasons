// my_class.cpp
#include "Jeu.h" // header in local directory
#include "Joueur.h"
#include "Saison.h"
#include "Plateau.h"
#include <iostream> // header in standard library
#include <string>
using namespace state;
using namespace std;

void Jeu::tourSuivant(){
   if ((*this).gameover== false ){
    (*this).tour++;
    }
};

void Jeu::abandonner (){
    if ((*this).gameover== false){
     (*this).gameover     = true;
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
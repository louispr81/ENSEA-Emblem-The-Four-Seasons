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
    Saison hiver;
    Plateau plateau1;
  
   
}

void Jeu::tourSuivant(){
   if (joueur1.gameover== false and joueur2.gameover==false){
    tour++;
    }
};

void Jeu::abandonner (){
    if (joueur1.gameover== false and joueur2.gameover==false){
     gameover     = true;
    }
    
};
    void updateSaison (){
        if (joueur1.gameover== false and joueur2.gameover==false){
        saison++;
        }

    };


Jeu::~Jeu(){

}
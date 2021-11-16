// my_class.cpp
#include "State.h" // header in local directory
#include <iostream> // header in standard library
#include <string>
using namespace state;
using namespace std;


State::State(){
    
    std::vector<Joueur> joueurs;
    std::vector<Personnage> personnagesJ1;
    std::vector<Personnage> personnagesJ2;
    std::vector<Saison*> listeSaison;
    std::vector<int> bonus; 
    std::vector<int> bonusP;

    // Creation des bonus des saisons (pour le moment les 4 ont le meme)
    for (int i=0; i<12; ++i){
        bonus.push_back(1);
    }
    // Creation des 4 saisons
    Saison printemps(PRINTEMPS,  bonus, "Printemps", AUTOMNE);
    Saison ete(ETE, bonus, "Ete", HIVER);
    Saison automne(AUTOMNE, bonus, "Automne", PRINTEMPS);
    Saison hiver(HIVER, bonus, "hiver", ETE);
    listeSaison.push_back(&printemps);
    listeSaison.push_back(&ete);
    listeSaison.push_back(&automne);
    listeSaison.push_back(&hiver);
    //Creation du plateau
    Plateau plateau(64); 

    //Creation des statistiques
    Statistiques statistiquesBaseA1;
    Statistiques statistiquesBaseM1;

    //Creation des inventaires
    std::vector<Objet> inventaireA1;
    std::vector<Objet> inventaireM1;

    //Creation des armes
    Arme dague("Dague", 0, 30, true, EPEE, 5, 1, 1, 90);
    Arme tome("Tome", 2, 30, true, TOME, 5, 1, 2, 90);

    //Creation des tableaux de probabilités d'augmentation d'une statistique
    std::vector<float> probaGainStatsA1;
    std::vector<float> probaGainStatsM1;
    //Creation des classes
    Classe assassin(ASSASSIN, "Assassin", probaGainStatsA1);
    Classe mage(MAGE, "Mage", probaGainStatsM1);

    // Creation des bonus les personnages(pour le moment les 4 ont le meme)
    for (int i=0; i<12; ++i){
        bonusP.push_back(1);
    }
    
    //Creation des statistiques des personnages
    Statistiques statistiquesA1;
    Statistiques statistiquesM1;

    //Choix des cases des personnages
    Cell caseA1=plateau.getCase(0,0);
    Cell caseM1=plateau.getCase(63,63);

    //Creation des personnages
    Personnage assassin1((std::string)"assassin1", 0,  statistiquesBaseA1,  inventaireA1, dague, assassin, &automne, &(caseA1), bonusP,  statistiquesA1,false,true);
    Personnage mage1((std::string)"mage1", 1,  statistiquesBaseM1,  inventaireM1, tome, mage, &printemps, &(caseM1), bonusP,  statistiquesM1,false,true);
    
    personnagesJ1.push_back(assassin1);
    personnagesJ2.push_back(mage1);

    //Creation des joueurs
    Joueur joueur1("J1", JOUEUR1, personnagesJ1);
    Joueur joueur2("J2", JOUEUR2, personnagesJ2);
    joueurs.push_back(joueur1);
    joueurs.push_back(joueur2);

    //Atributs
    (*this).joueurs=joueurs;
    (*this).tour=1;
    (*this).gameover=false;
    (*this).joueur=&joueur1;
    (*this).saison=&printemps;
    (*this).listeSaison=listeSaison;
    (*this).plateau=&plateau;
    
}


void State::tourSuivant(){
   if ((*this).gameover== false ){
        (*this).tour++;
    }
}

void State::abandonner (Joueur joueur){
    if ((*this).gameover== false){
     (*this).gameover     = true;
     
     cout<<"le joueur: "<<joueur.getNom()<<" a abandonné la partie "<< endl;
    }
    
}
void State::updateSaison (){
        
    if ((*this).gameover== false){
        if((*this).saison->getId() ==PRINTEMPS){
            // (*this).saison=ete;
        }
        if((*this).saison->getId() == ETE){
            // (*this).saison=automne;                         //les objets printemps ,automne,ete,hiver
        }                                                      // sont à créer !!
        if((*this).saison->getId() == AUTOMNE){   
            // (*this).saison=hiver;
        }
        if((*this).saison->getId() == HIVER){
            // (*this).saison=printemps; 
        }
    }
}

int State::getTour (){
    return (*this).tour;
}

bool State::getGameover (){
    return (*this).gameover;
}

Joueur State::getJoueurs(int i){
    return (*this).joueurs[i];
}
State::~State(){
    
}
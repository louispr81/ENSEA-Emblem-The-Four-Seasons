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
    (*this).listeSaison=listeSaison;
    (*this).joueurs=joueurs;

    // Creation des bonus des saisons (pour le moment les 4 ont le meme)
    for (int i=0; i<12; ++i){
        bonus.push_back(1);
    }
    // Creation des 4 saisons
    Saison *printemps = new Saison(PRINTEMPS,  bonus, "Printemps", AUTOMNE);
    Saison *ete = new Saison(ETE, bonus, "Ete", HIVER);
    Saison *automne = new Saison(AUTOMNE, bonus, "Automne", PRINTEMPS);
    Saison *hiver = new Saison(HIVER, bonus, "hiver", ETE);
    this->listeSaison.push_back(printemps);
    this->listeSaison.push_back(ete);
    this->listeSaison.push_back(automne);
    this->listeSaison.push_back(hiver);

    //Creation du plateau
    Plateau *plateau = new Plateau(64); 

    //Creation des statistiques
    Statistiques statistiquesBaseA1;
    Statistiques statistiquesBaseM1;

    //Creation des inventaires
    std::vector<Objet> inventaireA1;
    std::vector<Objet> inventaireM1;

    //Creation des armes
    Arme *dague = new Arme("Dague", 0, 30, true, EPEE, 5, 1, 1, 90);
    Arme *tome = new Arme("Tome", 2, 30, true, TOME, 5, 1, 2, 90);

    //Creation des tableaux de probabilités d'augmentation d'une statistique
    std::vector<float> probaGainStatsA1;
    std::vector<float> probaGainStatsM1;
    //Creation des classes
    Classe *assassin = new Classe(ASSASSIN, "Assassin", probaGainStatsA1);
    Classe *mage = new Classe(MAGE, "Mage", probaGainStatsM1);

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
    Personnage *assassin1 = new Personnage((std::string)"assassin1", 0,  statistiquesBaseA1,  inventaireA1, dague, assassin, &automne, &(caseA1), bonusP,  statistiquesA1,false,true);
    Personnage *mage1 = new Personnage((std::string)"mage1", 1,  statistiquesBaseM1,  inventaireM1, tome, mage, &printemps, &(caseM1), bonusP,  statistiquesM1,false,true);
    
    personnagesJ1.push_back(assassin1);
    personnagesJ2.push_back(mage1);

    //Creation des joueurs
    Joueur *joueur1 = new Joueur("J1", JOUEUR1, personnagesJ1);
    Joueur *joueur2 = new Joueur("J2", JOUEUR2, personnagesJ2);
    joueurs.push_back(joueur1);
    joueurs.push_back(joueur2);

    //Atributs


    (*this).tour=1;
    (*this).gameover=false;
    (*this).joueur=&joueur1;
    (*this).saison=&printemps;

    (*this).plateau=&plateau;
    
}

std::vector<Saison*> State::getListeSaison(){
    return (*this).listeSaison;
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
        switch(this->saison){
            case PRINTEMPS：
                (*this).saison=(*this).ListeSaison[1];
                break;
            case ETE：
                (*this).saison=(*this).ListeSaison[2];
                break;
            case AUTOMNE：
                (*this).saison=(*this).ListeSaison[3];
                break;
            case HIVER：
                (*this).saison=(*this).ListeSaison[0]; 
                break;
            }
            default：
                cout<<"Invalid selection \n";
            break;
        }
        else{
            cout<<"Invalid!!!!! \n" ;
        }
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

Saison* State:: getSaison(){
    return (*this).saison;
}

State::~State(){
    
}
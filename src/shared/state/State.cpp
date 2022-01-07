// my_class.cpp
#include "State.h" // header in local directory
#include <iostream> // header in standard library
#include <string>
using namespace state;
using namespace std;


State::State(){
    
}
State::State(int size){
    
    std::vector<Joueur*> joueurs;
    std::vector<Personnage*> personnagesJ1;
    std::vector<Personnage*> personnagesJ2;
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
    Saison *printemps = new Saison(SaisonId::PRINTEMPS,  bonus, "Printemps", SaisonId::AUTOMNE);
    Saison *ete = new Saison(SaisonId::ETE, bonus, "Ete", SaisonId::HIVER);
    Saison *automne = new Saison(SaisonId::AUTOMNE, bonus, "Automne", SaisonId::PRINTEMPS);
    Saison *hiver = new Saison(SaisonId::HIVER, bonus, "hiver", SaisonId::ETE);
    this->listeSaison.push_back(printemps);
    this->listeSaison.push_back(ete);
    this->listeSaison.push_back(automne);
    this->listeSaison.push_back(hiver);

    //Creation du plateau
    Plateau *plateau = new Plateau(size); 

    //Creation des statistiques
    //Statistiques (int vie, int vie_max, int point_mouvement, int point_mouvement_max, int force, int intelligence, int vitesse, int defense, int resistance, int technique, int experience, int experience_max, int niveau);
    Statistiques* statistiquesBaseA1=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesBaseM1=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesBaseC1=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesBaseCH1=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesBaseAR1=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesBaseA2=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesBaseM2=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesBaseC2=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesBaseCH2=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesBaseAR2=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);

    //Creation des inventaires
    std::vector<Objet*> inventaireA1;
    std::vector<Objet*> inventaireM1;
    std::vector<Objet*> inventaireC1;
    std::vector<Objet*> inventaireCH1;
    std::vector<Objet*> inventaireAR1;
    std::vector<Objet*> inventaireA2;
    std::vector<Objet*> inventaireM2;
    std::vector<Objet*> inventaireC2;
    std::vector<Objet*> inventaireCH2;
    std::vector<Objet*> inventaireAR2;
    
    //Creation des armes
    Arme *dague1 = new Arme("Dague", 0, 30, true, EPEE, 5, 1, 1, 90);
    Arme *dague2 = new Arme("Dague", 0, 30, true, EPEE, 5, 1, 1, 90);
    Arme *tome1 = new Arme("Tome", 2, 30, true, TOME, 5, 1, 2, 90);
    Arme *tome2 = new Arme("Tome", 2, 30, true, TOME, 5, 1, 2, 90);
    Arme *lance1 = new Arme("Lance", 0, 30, true, LANCE, 5, 1, 1, 90);
    Arme *lance2 = new Arme("Lance", 0, 30, true, LANCE, 5, 1, 1, 90);
    Arme *hache1 = new Arme("Hache", 0, 30, true, HACHE, 5, 1, 1, 90);
    Arme *hache2 = new Arme("Hache", 0, 30, true, HACHE, 5, 1, 1, 90);
    Arme *arc1 = new Arme("Arc", 0, 30, true, ARC, 5, 1, 3, 90);
    Arme *arc2 = new Arme("Arc", 0, 30, true, ARC, 5, 1, 3, 90);

    //Creation des tableaux de probabilités d'augmentation d'une statistique
    std::vector<float> probaGainStatsA;
    std::vector<float> probaGainStatsM;
    std::vector<float> probaGainStatsC;
    std::vector<float> probaGainStatsCH;
    std::vector<float> probaGainStatsAR;
    
    //Creation des classes
    Classe *assassin = new Classe(ClasseId::ASSASSIN, "Assassin", probaGainStatsA);
    Classe *mage = new Classe(ClasseId::MAGE, "Mage", probaGainStatsM);
    Classe *archer = new Classe(ClasseId::ARCHER, "Archer", probaGainStatsAR);
    Classe *chevalier = new Classe(ClasseId::CHEVALIER, "Chevalier", probaGainStatsCH);
    Classe *combattant = new Classe(ClasseId::COMBATTANT, "Combattant", probaGainStatsC);
   
    // Creation des bonus les personnages(pour le moment les 4 ont le meme)
    for (int i=0; i<12; ++i){
        bonusP.push_back(1);
    }
    
    //Creation des statistiques des personnages
    Statistiques* statistiquesA1=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques*statistiquesM1=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesC1=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesCH1=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesAR1=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesA2=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesM2=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesC2=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesCH2=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    Statistiques* statistiquesAR2=new Statistiques(20,20,5,5,1,1,1,1,1,1,0,100,1);
    
    //Choix des cases des personnages
    Cell* caseA1=(*plateau).getCase(0,0)->getPtCell();
    (*plateau).getCase(0,0)->setOccupe(true);
    Cell* caseM1=(*plateau).getCase(1,0)->getPtCell();
    (*plateau).getCase(1,0)->setOccupe(true);
    Cell* caseAR1=(*plateau).getCase(2,0)->getPtCell();
    (*plateau).getCase(2,0)->setOccupe(true);
    Cell* caseCH1=(*plateau).getCase(3,0)->getPtCell();
    (*plateau).getCase(3,0)->setOccupe(true);
    Cell* caseC1=(*plateau).getCase(4,0)->getPtCell();
    (*plateau).getCase(4,0)->setOccupe(true);
    Cell* caseA2=(*plateau).getCase(0,size-1)->getPtCell();
    (*plateau).getCase(0,size-1)->setOccupe(true);
    Cell* caseM2=(*plateau).getCase(1,size-1)->getPtCell();
    (*plateau).getCase(1,size-1)->setOccupe(true);
    Cell* caseAR2=(*plateau).getCase(2,size-1)->getPtCell();
    (*plateau).getCase(2,size-1)->setOccupe(true);
    Cell* caseCH2=(*plateau).getCase(3,size-1)->getPtCell();
    (*plateau).getCase(3,size-1)->setOccupe(true);
    Cell* caseC2=(*plateau).getCase(4,size-1)->getPtCell();
    (*plateau).getCase(4,size-1)->setOccupe(true);

    //Creation des personnages
    Personnage *assassin1 = new Personnage((std::string)"assassin 1", 0, statistiquesBaseA1, inventaireA1, dague1, assassin, automne, (caseA1), bonusP, statistiquesA1, plateau, false,true);
    Personnage *mage1 = new Personnage((std::string)"mage 1", 1, statistiquesBaseM1, inventaireM1, tome1, mage, printemps, (caseM1), bonusP, statistiquesM1, plateau, false, true);
    Personnage *chevalier1 = new Personnage((std::string)"chevalier 1", 2, statistiquesBaseCH1, inventaireCH1, lance1, chevalier, hiver, (caseCH1), bonusP, statistiquesCH1, plateau, false, true);
    Personnage *archer1 = new Personnage((std::string)"archer 1", 3, statistiquesBaseAR1, inventaireAR1, arc1, archer, ete, (caseAR1), bonusP, statistiquesAR1, plateau, false, true);
    Personnage *combattant1 = new Personnage((std::string)"combattant 1", 4, statistiquesBaseC1, inventaireC1, hache1, combattant, NULL, (caseC1), bonusP, statistiquesC1, plateau, false, true);
    Personnage *assassin2 = new Personnage((std::string)"assassin 2", 5, statistiquesBaseA2, inventaireA2, dague2, assassin, automne, (caseA2), bonusP, statistiquesA2, plateau, false,true);
    Personnage *mage2 = new Personnage((std::string)"mage 2", 6, statistiquesBaseM2, inventaireM2, tome2, mage, printemps, (caseM2), bonusP, statistiquesM2, plateau, false, true);
    Personnage *chevalier2 = new Personnage((std::string)"chevalier 2", 7, statistiquesBaseCH2, inventaireCH2, lance2, chevalier, hiver, (caseCH2), bonusP, statistiquesCH2, plateau, false, true);
    Personnage *archer2 = new Personnage((std::string)"archer 2", 8, statistiquesBaseAR2, inventaireAR2, arc2, archer, ete, (caseAR2), bonusP, statistiquesAR2, plateau, false, true);
    Personnage *combattant2 = new Personnage((std::string)"combattant 2", 9, statistiquesBaseC2, inventaireC2, hache2, combattant, NULL, (caseC2), bonusP, statistiquesC2, plateau, false, true);

    //(std::string nom, int id, Statistiques statistiquesBase, std::vector<Objet*> inventaire, Arme* arme, Classe* classe, Saison* saison, Cell* cell, std::vector<int> bonus, Statistiques statistiques, Plateau* plateau, bool played, bool alive)
    personnagesJ1.push_back(assassin1);
    personnagesJ1.push_back(mage1);
    personnagesJ1.push_back(chevalier1);
    personnagesJ1.push_back(archer1);
    personnagesJ1.push_back(combattant1);
    
    

    personnagesJ2.push_back(assassin2);
    personnagesJ2.push_back(mage2);
    personnagesJ2.push_back(chevalier2);
    personnagesJ2.push_back(archer2);
    personnagesJ2.push_back(combattant2);

    //Creation des joueurs
    Joueur *joueur1 = new Joueur("J1", JOUEUR1, personnagesJ1);
    Joueur *joueur2 = new Joueur("J2", JOUEUR2, personnagesJ2);
    this->joueurs.push_back(joueur1);
    this->joueurs.push_back(joueur2);

    //Atributs
    (*this).tour=1;
    (*this).gameover=false;
    (*this).joueur=joueur1;
    (*this).saison=printemps;
    (*this).plateau=plateau;
    
}

std::vector<Saison*> State::getListeSaison(){
    return (*this).listeSaison;
}
void State::tourSuivant(){
   if ((*this).gameover== false ){
        this->tour=tour+1;
        std::cout<<"Début du tour "<<this->tour<<std::endl;
        int i(0);
        for(i=0;i<this->joueurs[0]->getPersonnages().size();i++){
            if(this->joueurs[0]->getPersonnages()[i]->getAlive()==true){
                joueurs[0]->getPersonnages()[i]->setPlayed(false);
                joueurs[0]->getPersonnages()[i]->setMoved(false);
                joueurs[0]->getPersonnages()[i]->resetPm();
            }
        }
        for(i=0;i<this->joueurs[1]->getPersonnages().size();i++){
            if(this->joueurs[1]->getPersonnages()[i]->getAlive()==true){
                joueurs[1]->getPersonnages()[i]->setPlayed(false);
                joueurs[1]->getPersonnages()[i]->setMoved(false);
                joueurs[1]->getPersonnages()[i]->resetPm();
            }
        }

    }
}
void State::joueurSuivant(){
    if ((*this).gameover== false ){
        if(this->joueur->getId()==JOUEUR2){
            std::cout<<"Fin du tour !"<<std::endl;
            this->tourSuivant();
            this->joueur=joueurs[0];
        }
        else if(this->joueur->getId()==JOUEUR1){
            this->joueur=joueurs[1];
        }
        else{
            perror("joueur suivant");
            exit(1);
        }
        std::cout<<"Au tour de "<<this->joueur->getNom()<<std::endl;
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
        switch((*(this->saison)).getId()){
            case PRINTEMPS:
                (*this).saison=(*this).listeSaison[1];
                break;
            case ETE:
                (*this).saison=(*this).listeSaison[2];
                break;
            case AUTOMNE:
                (*this).saison=(*this).listeSaison[3];
                break;
            case HIVER:
                (*this).saison=(*this).listeSaison[0]; 
                break;
            
            default:
                cout<<"Invalid selection \n";
            break;
        }
    }
    else{
        cout<<"Invalid!!!!! \n" ;
    }   
}

int State::getTour (){
    return (*this).tour;
}

bool State::getGameover (){
    return (*this).gameover;
}

std::vector<Joueur*> State::getJoueurs(){
    return (*this).joueurs;
}

Saison* State:: getSaison(){
    return (*this).saison;
}

Plateau* State::getPlateau (){
    return (*this).plateau;
}

Personnage* State::getPersonnageActif(){
    if (this->gameover== false ){
        int i(0);
        for(i=0;i<this->joueur->getPersonnages().size();i++){
            if(this->joueur->getPersonnages()[i]->getPlayed()==false){
                return joueur->getPersonnages()[i];
            }
        }
        this->joueurSuivant();
        i=0;
        for(i=0;i<this->joueur->getPersonnages().size();i++){
            if(this->joueur->getPersonnages()[i]->getPlayed()==false){
                return joueur->getPersonnages()[i];
            }
        }
    }
    else{
        std::cout<<"The game is over !"<<std::endl;
        perror("GameOver");
        exit(1);
    }
}


void State::print(){
    std::cout<<"---------------STATE---------------"<<std::endl;
    std::cout<<"tour="<<this->tour<<std::endl;
    std::cout<<"saison="<<this->saison->getNom()<<std::endl;
    std::cout<<"joueur="<<this->joueur->getNom()<<std::endl;
    std::cout<<"gameover="<<this->gameover<<std::endl;
    int i(0);
    int j(0);
    for(i=0;i<this->joueurs.size();i++){
        std::cout<<"Personnages Joueur \""<<this->joueurs[i]->getNom()<<"\":"<<std::endl;
        for(j=0;j<(this->joueurs[i]->getPersonnages()).size();j++){
            this->joueurs[i]->getPersonnages()[j]->print();
        }
    }
    this->plateau->print();
    std::cout<<"----------------------------------------"<<std::endl;
    
}
Joueur* State::getJoueur(){
    return this->joueur;
}

State::~State(){
    
}

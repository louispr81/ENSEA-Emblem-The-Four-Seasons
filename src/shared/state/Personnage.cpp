#include "Personnage.h" 
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace state;
using namespace std;


Personnage::Personnage(std::string nom, int id, Statistiques* statistiquesBase, std::vector<Objet*> inventaire, Arme* arme, Classe* classe, Saison* saison, Cell* cell, std::vector<int> bonus, Statistiques* statistiques, Plateau* plateau, bool played, bool alive, bool moved){
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
    (*this).moved=moved;
}

Saison Personnage::getSaison(){
    return *((*this).saison);
}
void Personnage::setBonus(std::vector<int> x){

}

void Personnage::attendre(){ 
    if ((*this).played != true){
        (*this).statistiques->setPoint_mouvement(0);
        (*this).moved=true;
        (*this).played=true;
    }
    else{
        std::cout<<"this character has already played"<<std::endl;
    }
}

void Personnage::setPlayed (bool played){
    (*this).played=played;
}

void Personnage::setMoved (bool moved){
    this->moved=moved;
}

std::string Personnage::getNom(){
 return (*this).nom;
}

bool Personnage::getPlayed (){
        return (*this).played;
}

bool Personnage::getAlive (){
    return (*this).alive;
}

void Personnage::setAlive(bool alive){
    (*this).alive=alive;
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









void Personnage::echangerObjet(Personnage personnageB, Objet objet){
    for (size_t i = 0; i <(*this).inventaire.size() ; i++)
    {
        
    if ((*this).inventaire.at(i) == &objet)
    {
        personnageB.inventaire.push_back(&objet);
        (*this).inventaire.erase((*this).inventaire.begin()+i);
    }
    
    }
}

int Personnage::deplacer(int x1, int y1){
    Cell* dest=this->plateau->getCase(x1,y1);
    if(dest->getOccupe()==true){
        std::cout<<"Cell occupied"<<std::endl;
    }
    else if(dest->getWalkable()==false){
        std::cout<<"Cell unwalkable"<<std::endl;
    }
    else{
        int pm=this->statistiques->getPoint_mouvement();
        int cost=this->cell->getCostPm();
        if(cost<=pm){
            this->cell->setOccupe(false);
            this->cell->setPersonnage(NULL);
            this->cell=dest;
            this->cell->setOccupe(true);
            this->cell->setPersonnage(this);
            this->statistiques->setPoint_mouvement(pm-cost);
            if(this->statistiques->getPoint_mouvement()==0){
                this->moved=true;
            }
            return 1;
        }
        else{
            std::cout<<"pas assez de PM"<<std::endl;
            return -1;
        }
    }
    /*
    int reply;
    this->moved=false;
    std::vector<int> coordonne_a ,coordonne_destination,coordonne_1,coordonne_2,coordonne_3,coordonne_4;
    
    coordonne_a=((*((*this).cell)).getCoordonees()); // coordonees du personnage 
    coordonne_destination=(this->plateau->getCase(x1,y1)->getCoordonees());
     
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
        if(this->plateau->getCase(coordonne_1[0],coordonne_1[1])->getWalkable()==true){
            if(this->plateau->getCase(coordonne_1[0],coordonne_1[1])->getOccupe()==false){
                 if((*this).statistiques.getPoint_mouvement()>=1){
                    ((*((*this).cell)).getCoordonees())=coordonne_1;
                    (*this).statistiques.setPoint_mouvement((*this).statistiques.getPoint_mouvement()-1);
                  reply=1;
                  this->moved=true;
                 }
            }

        }
    }


    if (coordonne_destination==coordonne_2 ){
        if(this->plateau->getCase(coordonne_2[0],coordonne_2[1])->getWalkable()==true){
            if(this->plateau->getCase(coordonne_2[0],coordonne_2[1])->getOccupe()==false){
                if((*this).statistiques.getPoint_mouvement()>=1){  
                    ((*((*this).cell)).getCoordonees())=coordonne_2;
                    (*this).statistiques.setPoint_mouvement((*this).statistiques.getPoint_mouvement()-1);
                    reply=1;
                    //this->moved=true;
                }
            }

        }
    }



    if (coordonne_destination==coordonne_3 ){
        if(this->plateau->getCase(coordonne_3[0],coordonne_3[1])->getWalkable()==true){
            if(this->plateau->getCase(coordonne_3[0],coordonne_3[1])->getOccupe()==false){
                if((*this).statistiques.getPoint_mouvement()>=1){
                    ((*((*this).cell)).getCoordonees())=coordonne_3;
                    (*this).statistiques.setPoint_mouvement((*this).statistiques.getPoint_mouvement()-1);
                    reply=1;
                    //this->moved=true;
                }
            }

        }
    }
    if (coordonne_destination==coordonne_4 ){
        if(this->plateau->getCase(coordonne_4[0],coordonne_4[1])->getWalkable()==true){
            if(this->plateau->getCase(coordonne_4[0],coordonne_4[1])->getOccupe()==false){
                if((*this).statistiques.getPoint_mouvement()>=1){
                    ((*((*this).cell)).getCoordonees())=coordonne_4;
                    (*this).statistiques.setPoint_mouvement((*this).statistiques.getPoint_mouvement()-1);
                    reply=1;
                    //this->moved=true;
                }
            }
        }
    }
    else {
        cout<< " la case n'est pas disponible "<<endl;
        reply = -1;
        //this->moved=false;
    }   
 return reply;
 /*
    if(this->moved==false){
        int pm;
        pm=this->statistiques->getPoint_mouvement();
        if(pm>0){
            Cell* Destination=this->plateau->getCase(x1,y1);
            Cell* tmpDestination;
            int distanceX;
            int distanceY;
            int signe;
            int test;
            while (pm>0){
                int x0=this->cell->getCoordonees()[0];
                int y0=this->cell->getCoordonees()[1];
                distanceX=x1-x0;
                distanceY=y1-y0;
                if(abs(distanceX)>=abs(distanceY)){
                    if(distanceX>0){
                        signe=1;
                    }
                    else{
                        signe=-1;
                    }
                    tmpDestination=this->plateau->getCase(x0+signe,y0);
                    test=this->deplacer1Dist(tmpDestination,pm);
                    if(test==0){
                        this->moved=true;
                        return 1;
                    }
                    else if(test==-1){
                        if(distanceY>0){
                            signe=1;
                        }
                        else{
                            signe=-1;
                        }
                        tmpDestination=this->plateau->getCase(x0,y0+signe);
                        test=this->deplacer1Dist(tmpDestination,pm);
                        if(test==0){
                            this->moved=true;
                            return 1;
                        }
                        else if(test==-1){
                            std::cout<<"Personnage bloqué mouvement stopé"<<std::endl;
                            return 1;
                        }
                    }
                }
                else{                   
                    if(distanceY>0){
                        signe=1;
                    }
                    else{
                        signe=-1;
                    }
                    tmpDestination=this->plateau->getCase(x0,y0+signe);
                    test=this->deplacer1Dist(tmpDestination,pm);
                    if(test==0){
                        return 1;
                    }
                    else if(test==-1){
                        if(distanceX>0){
                            signe=1;
                        }
                        else{
                            signe=-1;
                        }
                        tmpDestination=this->plateau->getCase(x0+signe,y0);
                        test=this->deplacer1Dist(tmpDestination,pm);
                        if(test==0){
                            return 1;
                        }
                        else if(test==-1){
                            std::cout<<"Personnage bloqué mouvement stopé"<<std::endl;
                            return 1;
                        }
                    }

                }
                pm=this->statistiques->getPoint_mouvement();
            }
            this->moved=true;
            return 1;
        }
        else{
            std::cout<<"Le personnage n'a pas assez de points de mouvements"<<std::endl;
            return -1;
        }
    }
    else{
        std::cout<<"Le personnage a déjà bougé"<<std::endl;
        return -1;
    }
*/  
}

bool Personnage::getMoved(){
    return this->moved;  
}

int Personnage::deplacer1Dist(Cell* dest,int pm){
    if(dest->getWalkable()==true){
        if(pm-dest->getCostPm()>=0){
            pm=pm-dest->getCostPm();
            this->cell=dest;
            this->statistiques->setPoint_mouvement(pm);
            return 1;
        }
        else{
            this->statistiques->setPoint_mouvement(pm);
            return 0;
        }
    }
    else{
        return -1;
    }
}


void Personnage::attaquer (Personnage personnageD){
    std::vector<int> coordonne_a,coordonnees_b,coordonne_1,coordonne_2,coordonne_3,coordonne_4,coordonne_5,coordonne_6,coordonne_7,coordonne_8,coordonne_9,coordonne_10,coordonne_11,coordonne_12;
    coordonne_a=((*this).cell->getCoordonees());
    coordonnees_b=(personnageD.cell->getCoordonees());

    coordonne_1[0]=coordonne_a[0]-1;  coordonne_2[0]=coordonne_a[0];    coordonne_3[0]=coordonne_a[0]+1;
    coordonne_1[1]=coordonne_a[1];    coordonne_2[1]=coordonne_a[1]+1;  coordonne_3[1]=coordonne_a[1];

    coordonne_4[0]=coordonne_a[0];    coordonne_5[0]=coordonne_a[0]-2;  coordonne_6[0]=coordonne_a[0]-1;     
    coordonne_4[1]=coordonne_a[1]-1;  coordonne_5[1]=coordonne_a[1];    coordonne_6[1]=coordonne_a[1]+1;

   

    coordonne_7[0]=coordonne_a[0];    coordonne_8[0]=coordonne_a[0]+1;  coordonne_9[0]=coordonne_a[0]+2;
    coordonne_7[1]=coordonne_a[1]+2;  coordonne_8[1]=coordonne_a[1]+1;  coordonne_9[1]=coordonne_a[1];



    coordonne_10[0]=coordonne_a[0]+1;  coordonne_11[0]=coordonne_a[0];   coordonne_12[0]=coordonne_a[0]-1;
    coordonne_10[1]=coordonne_a[1]-1;  coordonne_11[1]=coordonne_a[1]-2; coordonne_12[1]=coordonne_a[1]-1;


if((*this).getAlive()==true and personnageD.getAlive()==true and (*this).getPlayed()==false ){

    if((*this).arme->getRange()==1) 
        {
            if(coordonnees_b==coordonne_1||coordonnees_b==coordonne_2||coordonnees_b==coordonne_3||coordonnees_b==coordonne_4){
                personnageD.statistiques->setVie(personnageD.statistiques->getVie()-1);
                (*this).setPlayed(true);
                if (personnageD.statistiques->getVie()==0)
                {
                   (*this).setAlive(false); 
                }
                
            }

        }

    
    else if ((*this).arme->getRange()==2){
       
        if(coordonnees_b==coordonne_1||coordonnees_b==coordonne_2||coordonnees_b==coordonne_3||coordonnees_b==coordonne_4){
                personnageD.statistiques->setVie(personnageD.statistiques->getVie()-1);
                (*this).setPlayed(true);
                if (personnageD.statistiques->getVie()==0)
                {
                   (*this).setAlive(false); 
                }
                
            }



         else if(coordonnees_b==coordonne_5||coordonnees_b==coordonne_6||coordonnees_b==coordonne_7||coordonnees_b==coordonne_8||coordonnees_b==coordonne_9||coordonnees_b==coordonne_10||coordonnees_b==coordonne_11||coordonnees_b==coordonne_12){
                personnageD.statistiques->setVie(personnageD.statistiques->getVie()-1);
                (*this).setPlayed(true);
                if (personnageD.statistiques->getVie()==0)
                {
                   (*this).setAlive(false); 
                }
        
         }
        
        

    }

    else {
        cout<<"pas d'attaque"<<endl;
    }


}
}

std::string Personnage::getPersonnageActif(){
    return this->nom;
}
ClasseId Personnage::getClasseId (){
    return (*((*this).classe)).getId();
}

Cell* Personnage::getCell (){
    return (*this).cell;
}

void Personnage::print(){
    std::cout<<"---------------PERSONNAGE---------------"<<std::endl;
    std::cout<<"nom="<<this->nom<<std::endl;
    std::cout<<"classe="<<this->classe->getNom()<<std::endl;
    std::cout<<"coords= ("<<this->cell->getPtCell()->getCoordonees()[0]<<";"<<this->cell->getPtCell()->getCoordonees()[1]<<")"<<std::endl;
    std::cout<<"moved="<<this->moved<<std::endl;
    std::cout<<"alive="<<this->alive<<std::endl;
    std::cout<<"id="<<this->id<<std::endl;
    this->statistiques->print();
    std::cout<<"----------------------------------------"<<std::endl;
}
    std::string nom;
    int id;
    Statistiques statistiquesBase;
    std::vector<Objet*> inventaire;
    Arme* arme;
    Classe* classe;
    Saison* saison;
    bool alive     = true;
    bool played     = false;
    std::vector<int> bonus;
    Statistiques statistiques;
    Cell* cell;
    Plateau* plateau;
    bool moved     = false;
Personnage::~Personnage(){
   // delete[] tab_arme;
}



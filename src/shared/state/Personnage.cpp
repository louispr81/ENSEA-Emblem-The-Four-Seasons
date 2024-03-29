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

void Personnage::attendre(){ //statistique base rajouter
    if ((*this).played != true){
        (*this).statistiques->setPoint_mouvement(0);
        (*this).moved=true;
        (*this).played=true;
        std::cout<<"Fin du tour de "<<this->nom<<std::endl;
    }
    else{
        std::cout<<"this character has already played"<<std::endl;
    }
}

void Personnage::resetPm(){
    this->statistiques->setPoint_mouvement(this->statistiques->getPoint_mouvement_max());
    this->statistiquesBase->setPoint_mouvement(this->statistiquesBase->getPoint_mouvement_max());
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

int Personnage::deplacer(int x1, int y1){ //statistique base rajouter
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

void Personnage::attaquer (Personnage* personnageD){ 
    int degatsAttaquant;
    if(this->statistiques->getVitesse()>=personnageD->getStatistic()->getVitesse()+3){   
        std::cout<<this->nom<<" attaque 2 fois !"<<std::endl; 
        degatsAttaquant=this->degat(personnageD);
        degatsAttaquant=this->degat(personnageD)+degatsAttaquant;
    }
    else{
        degatsAttaquant=this->degat(personnageD);
    }
    int hpDefenseur=personnageD->statistiques->getVie();
    personnageD->statistiques->setVie(hpDefenseur-degatsAttaquant);
    personnageD->statistiquesBase->setVie(hpDefenseur-degatsAttaquant);
    if(personnageD->statistiques->getVie()<=0){
        this->statistiques->setExperience(this->statistiques->getExperience()+this->statistiques->getExperience_max());
        this->statistiquesBase->setExperience(this->statistiques->getExperience()+this->statistiques->getExperience_max());
        this->levelUp();
        std::cout<<personnageD->getNom()<<" a été tué par "<<this->getNom()<<std::endl;
        personnageD->setAlive(false);
        personnageD->getCell()->setOccupe(false);
        personnageD->getCell()->setPersonnage(NULL);
        personnageD->setCell(NULL);
    }
    else{
        this->statistiques->setExperience(this->statistiques->getExperience()+this->statistiques->getExperience_max()/2);
        this->statistiquesBase->setExperience(this->statistiques->getExperience()+this->statistiques->getExperience_max()/2);
        this->levelUp();
        std::cout<<personnageD->getNom()<<" a  "<<personnageD->statistiques->getVie()<<"HP après l'attaque de "<<this->getNom()<<std::endl;
    }   
    this->attendre(); 
    /*
    std::vector<int> coordonne_a,coordonnees_b,coordonne_1,coordonne_2,coordonne_3,coordonne_4,coordonne_5,coordonne_6,coordonne_7,coordonne_8,coordonne_9,coordonne_10,coordonne_11,coordonne_12;
    coordonne_a=((*this).cell->getCoordonees());
    coordonnees_b=(personnageD->cell->getCoordonees());

    coordonne_1[0]=coordonne_a[0]-1;  coordonne_2[0]=coordonne_a[0];    coordonne_3[0]=coordonne_a[0]+1;
    coordonne_1[1]=coordonne_a[1];    coordonne_2[1]=coordonne_a[1]+1;  coordonne_3[1]=coordonne_a[1];

    coordonne_4[0]=coordonne_a[0];    coordonne_5[0]=coordonne_a[0]-2;  coordonne_6[0]=coordonne_a[0]-1;     
    coordonne_4[1]=coordonne_a[1]-1;  coordonne_5[1]=coordonne_a[1];    coordonne_6[1]=coordonne_a[1]+1;

   

    coordonne_7[0]=coordonne_a[0];    coordonne_8[0]=coordonne_a[0]+1;  coordonne_9[0]=coordonne_a[0]+2;
    coordonne_7[1]=coordonne_a[1]+2;  coordonne_8[1]=coordonne_a[1]+1;  coordonne_9[1]=coordonne_a[1];



    coordonne_10[0]=coordonne_a[0]+1;  coordonne_11[0]=coordonne_a[0];   coordonne_12[0]=coordonne_a[0]-1;
    coordonne_10[1]=coordonne_a[1]-1;  coordonne_11[1]=coordonne_a[1]-2; coordonne_12[1]=coordonne_a[1]-1;


if((*this).getAlive()==true and personnageD->getAlive()==true and (*this).getPlayed()==false ){

    if((*this).arme->getRange()==1) 
        {
            if(coordonnees_b==coordonne_1||coordonnees_b==coordonne_2||coordonnees_b==coordonne_3||coordonnees_b==coordonne_4){
                personnageD->statistiques->setVie(personnageD->statistiques->getVie()-1);
                (*this).setPlayed(true);
                if (personnageD->statistiques->getVie()==0)
                {
                   (*this).setAlive(false); 
                }
                
            }

        }

    
    else if ((*this).arme->getRange()==2){
       
        if(coordonnees_b==coordonne_1||coordonnees_b==coordonne_2||coordonnees_b==coordonne_3||coordonnees_b==coordonne_4){
                personnageD->statistiques->setVie(personnageD->statistiques->getVie()-1);
                (*this).setPlayed(true);
                if (personnageD->statistiques->getVie()==0)
                {
                   (*this).setAlive(false); 
                }
                
            }



         else if(coordonnees_b==coordonne_5||coordonnees_b==coordonne_6||coordonnees_b==coordonne_7||coordonnees_b==coordonne_8||coordonnees_b==coordonne_9||coordonnees_b==coordonne_10||coordonnees_b==coordonne_11||coordonnees_b==coordonne_12){
                personnageD->statistiques->setVie(personnageD->statistiques->getVie()-1);
                (*this).setPlayed(true);
                if (personnageD->statistiques->getVie()==0)
                {
                   (*this).setAlive(false); 
                }        
         }
    }
    else {
        cout<<"pas d'attaque"<<endl;
    }
}
*/
}

ClasseId Personnage::getClasseId (){
    return (*((*this).classe)).getId();
}

Cell* Personnage::getCell (){
    return (*this).cell;
}
void Personnage::setCell (Cell* cell){
    this->cell=cell;
}
Statistiques* Personnage::getStatistic (){
    return this->statistiques;
}
void Personnage::print(){
    std::cout<<"---------------PERSONNAGE---------------"<<std::endl;
    std::cout<<"nom="<<this->nom<<std::endl;
    std::cout<<"classe="<<this->classe->getNom()<<std::endl;
    if(this->alive==true){
        std::cout<<"coords= ("<<this->cell->getPtCell()->getCoordonees()[0]<<";"<<this->cell->getPtCell()->getCoordonees()[1]<<")"<<std::endl;
    }
    else{
        std::cout<<"coords= NULL"<<std::endl;
    }
    std::cout<<"moved="<<this->moved<<std::endl;
    std::cout<<"alive="<<this->alive<<std::endl;
    std::cout<<"id="<<this->id<<std::endl;
    this->statistiques->print();
    std::cout<<"----------------------------------------"<<std::endl;
}

int Personnage::degat(Personnage* target){
    srand((unsigned)time(NULL));
    int degat;
    float probDegat;
    int diffTech;
    int randomValue;
    diffTech = this->statistiques->getTechnique()-target->statistiques->getTechnique();
    probDegat = 0.7 + diffTech*0.05;
    if(probDegat > 1){
        probDegat == 1;
    }
    randomValue = rand()%101; // random value from 0-100
    if(randomValue <= 100*probDegat){
        if(this->classe->getId() == MAGE){
            degat = (this->statistiques->getIntelligence() - target->statistiques->getResistance()/2) ;
        }
        else{
            degat = (this->statistiques->getForce() - target->statistiques->getDefense()/2) ;
        }
        cout<<"Dammage ="<<degat<<endl;
    }
    else{
        degat = 0;
        cout<<"Miss"<<endl;
    }
    if(degat<=0){
        degat=0;
    }
    return degat;
}

void Personnage::levelUp(){
    srand((unsigned)time(NULL)); 
    while(this->statistiques->getExperience()>=this->statistiques->getExperience_max()){
        this->statistiques->setExperience(this->statistiques->getExperience()-this->statistiques->getExperience_max());
        this->statistiquesBase->setExperience(this->statistiquesBase->getExperience()-this->statistiques->getExperience_max());
        this->statistiques->setNiveau(this->statistiques->getNiveau()+1);
        this->statistiquesBase->setNiveau(this->statistiquesBase->getNiveau()+1);
        std::cout<<this->nom<<" passe niveau "<<this->statistiques->getNiveau()<<std::endl;
        float randomGain;
        std::vector<int> listStatTmp;
        std::vector<int> listStatBaseTmp;
        listStatTmp=this->statistiques->getListStatistique();
        listStatBaseTmp=this->statistiquesBase->getListStatistique();
        for(int j = 0; j < this->classe->getProbaGainStats().size(); j++){          
            randomGain = ((float)(rand()%101))/(float)100;
            //float sumProb = 0;
            //sumProb = sumProb + this->classe->getProbaGainStats()[j];
            if(randomGain <= this->classe->getProbaGainStats()[j]){
                std::cout<<"+1 "<<"stat numero : "<<j<<std::endl;
                listStatTmp[j] = this->statistiquesBase->getListStatistique()[j]+1;
                listStatBaseTmp[j] = this->statistiquesBase->getListStatistique()[j]+1;
            }
        }  
        this->statistiques->setListStatistique(listStatTmp);
        this->statistiquesBase->setListStatistique(listStatBaseTmp);
        //calculer probabilite d'avoir une competance
        /*
        if(0 <= randomGain < prob[0]){
            this->statistiques->setVie_max(this->statistiques->getVie_max()+1);
            this->statistiques->setVie(this->statistiques->getVie()+1);
        }
        else if(prob[0] < randomGain < prob[1]){
            this->statistiques->setPoint_mouvement_max(this->statistiques->getPoint_mouvement_max()+1);
        }
        else if(prob[1] < randomGain < prob[2]){
            this->statistiques->setForce(this->statistiques->getForce()+1);
        }
        else if(prob[2] < randomGain < prob[3]){
            this->statistiques->setIntelligence(this->statistiques->getIntelligence()+1);
        }
        else if(prob[3] < randomGain < prob[4]){
            this->statistiques->setVitesse(this->statistiques->getVitesse()+1);
        }
        else if(prob[4] < randomGain < prob[5]){
            this->statistiques->setDefense(this->statistiques->getDefense()+1);
        }
        else if(prob[5] < randomGain < prob[6]){
            this->statistiques->setResistance(this->statistiques->getResistance()+1);
        }
        else if(prob[6] < randomGain < prob[7]){
            this->statistiques->setTechnique(this->statistiques->getTechnique()+1);
        }
        else if(prob[7] < randomGain <= 1){
            cout<<"You are unluckyyyyy, you get nothing !!!"<<endl;
        }
        else{
            cout<<"error calcul probGainState"<<endl;
        }*/
    }

    
}

void Personnage::gainBonusSaison(Saison* saison){
    if(this->saison!=NULL){
        if(this->saison->getId() == saison->getId()){
            std::vector<int> listStatTmp;
            listStatTmp=this->statistiquesBase->getListStatistique();
            for(int i = 0; i < this->saison->getBonus().size(); i++){
                listStatTmp[i] = this->statistiquesBase->getListStatistique()[i]+this->saison->getBonus()[i]; 
            }
            this->statistiques->setListStatistique(listStatTmp);
            std::cout<<this->nom<<" bonus saison !"<<std::endl;
        }
        else if(this->saison->getSaisonOppId()==saison->getId()){
            std::vector<int> listStatTmp;
            listStatTmp=this->statistiquesBase->getListStatistique();
            for(int i = 0; i < this->saison->getBonus().size(); i++){
                listStatTmp[i] = this->statistiquesBase->getListStatistique()[i]-this->saison->getBonus()[i]; 
            }
            this->statistiques->setListStatistique(listStatTmp);
            std::cout<<this->nom<<" malus saison !"<<std::endl;
        }
        else{
            this->statistiques->setListStatistique(this->statistiquesBase->getListStatistique());

        }
    }
}
Personnage::~Personnage(){
   // delete[] tab_arme;
}



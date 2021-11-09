#include "Saison.h"
using namespace state;

void Saison::Saison(std::string nom, std::list<int> bonus, SaisonId id, Jeu saison)
{    
    (*this).nom = nom;
    (*this).bonus = bonus;
    (*this).id = id;
    (*this).saison = saison;
}


void Saison::updateStatsSaison(Personnage personnage)
{
    /*when the saison and the saison of the character are the same*/
    if(personnage.getSaison().id == jeu.getSaison().id)  
    {
        personnage.setBonus(this->bonus);
    }
    /*when the saison and the saison of the character are contrary*/
    else if(personnage.getSaison().saisonOppId == jeu.getSaison().id)
    {       
        tab = new int[12];
        personnage.setBonus(tab);
    }
}

void Saison::updateCell(Cell cell)
{
    if (id == hiver && Cell.type == RIVER){
        Cell.walkable = true;
        Cell.costPm = 2;
    }
    else{
        Cell.walkable = false;
        
   }

    
}

void Saison::~Saison(){
    delete[] tab;
}

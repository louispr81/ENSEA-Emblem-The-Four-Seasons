#include "Saison.h"
#include "limits.h"
using namespace state;

Saison::Saison(std::string nom, std::list<int> bonus, SaisonId id, Jeu saison)
{    
    (*this).nom = nom;
    (*this).bonus = bonus;
    (*this).id = id;
    (*this).saison = saison;
}


void Saison::updateStatsSaison(Personnage personnage)
{
    //when the saison and the saison of the character are the same
    if(personnage.getSaison().id == jeu.getSaison().id)  
    {
        personnage.setBonus(this->bonus);
    }
    //when the saison and the saison of the character are contrary
    else if(personnage.getSaison().saisonOppId == jeu.getSaison().id)
    {       
        
        tab_bonus = new int[12];      
        personnage.setBonus(tab);
    }
    else{
        tab_no_bonus = new int[12] {0}；
        personnage.setBonus(tab_no_bonus);
    }
}

void Saison::updateCell(Cell cell)
{
    if(Cell.type == GRASS){
        Cell.setcostPm = 1;
        Cell.setWalkable = true;
    }
    if(Cell.type == FOREST){
        Cell.setcostPm = 1;
        Cell.setWalkable = true;
    }
    if(Cell.type == STONE){
        Cell.setcostPm = 1;
        Cell.setWalkable = false;   
    }
    if(Cell.type == RIVER){
        Cell.setcostPm = 1;
        Cell.setWalkable = false;     
    }
    if(Cell.type == BRIDGE){
        Cell.setcostPm = 1;  
        Cell.setWalkable = true;      
    }
    if(Cell.type == PASSAGE){
        Cell.setcostPm = 3;  
        Cell.setWalkable = true;      
    }
    if(Cell.type == MOUTAINS){
        Cell.setcostPm = 1;
        Cell.setWalkable = false;             
    }


    if (this->id == hiver)
        Cell.setcostPm = 2*Cell.setcostPm;
        if (Cell.type == RIVER){
         Cell.walkable = true;
        }
    }
    if (this->id == printemps){
        Cell.setcostPm = Cell.setcostPm/2;
    }
        
   }

}

Saison::~Saison(){
    delete[] tab_bonus;
    delete[] tab_no_bonus;
}

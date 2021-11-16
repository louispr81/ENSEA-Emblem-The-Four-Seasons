#include "Saison.h"
using namespace state;
        
Saison::Saison (SaisonId id, std::vector<int> bonus, std::string nom, SaisonId saisonOppId)
{    
    (*this).id = id;
    (*this).bonus = bonus;
    (*this).nom = nom;
    (*this).saisonOppId = saisonOppId;
}


void Saison::updateStatsSaison(Personnage personnage, State jeu)
{
    //when the saison and the saison of the character are the same
    if(personnage.getSaison().id == jeu.getSaison().id)  
    {
        personnage.setBonus(this->bonus);
    }
    //when the saison and the saison of the character are contrary
    else if(personnage.getSaison().saisonOppId == jeu.getSaison().id)
    {       
        
        std::vector<int> tab_malus; 
         for (int i=0; i<12; ++i){
            tab_malus.push_back(-(this->bonus[i]));
        }
        personnage.setBonus(tab_malus);
    }
    else{
        std::vector<int> tab_no_bonus;
        for (int i=0; i<12; ++i){
            tab_no_bonus.push_back(0);
        }
        personnage.setBonus(tab_no_bonus);
    }
}

void Saison::updateCell(Cell cell)
{
    if(cell.getType() == GRASS){
        cell.setCostPm (1);
        cell.setWalkable (true);
    }
    if(cell.getType() == FOREST){
        cell.setCostPm (1);
        cell.setWalkable (true);
    }
    if(cell.getType() == STONE){
        cell.setCostPm(1);
        cell.setWalkable(false);   
    }
    if(cell.getType() == RIVER){
        cell.setCostPm(1);
        cell.setWalkable(false);     
    }
    if(cell.getType() == BRIDGE){
        cell.setCostPm(1);  
        cell.setWalkable(true);      
    }
    if(cell.getType() == PASSAGE){
        cell.setCostPm(3);  
        cell.setWalkable(true);      
    }
    if(cell.getType() == MOUTAINS){
        cell.setCostPm(1);
        cell.setWalkable(false);             
    }


    if (this->id == HIVER){
        cell.setCostPm (2*cell.getCostPm());
        if (cell.getType() == RIVER){
        cell.setWalkable (true);
        }
    }
    if (this->id == PRINTEMPS){
        cell.setCostPm(cell.getCostPm()/2);
    }
        
   

}


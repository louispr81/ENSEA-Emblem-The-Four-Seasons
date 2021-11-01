#include "Saison.h"
#include "SaisonId.h"
#include "Personnage.h"
#include "Jeu.h"
using namespace state;

/*void Saison::Saison(std::string nom, std::list<int> bonus, SaisonId id)
{    
    this->nom = nom;
    this->bonus = bonus;
    this->id = id;
}


void Saison::updateStatsSaison(Personnage personnage)
{
    /*when the saison and the saison of the character are the same
    if(personnage.getSaison().id == jeu.getSaison().id)  
    {
        personnage.setBonus(this->bonus);
    }
    /*when the saison and the saison of the character are contrary
    else if(personnage.getSaison().saisonOppId == jeu.getSaison().id)
    {
        
        personnage.setBonus(tab);
    }
}

void Saison::updateCell(Cell cell)
{

}
/*void Classe::~Classe()
{
    Il faut mettre sur dia!!!!!
}*/

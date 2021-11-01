#include "Personnage.h" 
using namespace state;

void Personnage::attendre(){ 
    if ((*this).played != true){
        (*this).statistiques.setPoint_mouvement(0);
        (*this).played=true;
    }
}
    
    





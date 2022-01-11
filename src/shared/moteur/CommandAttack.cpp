#include "CommandAttack.h"
#include <iostream>
#include "../state/Personnage.h"

using namespace std;
using namespace state;

namespace moteur{
CommandAttack::CommandAttack(){

}
CommandAttack::CommandAttack(state::State* currentState){
    id = ATTACK;
    this->currentState = currentState;
}
/*
void CommandAttack::execute(state::State& state){

    target.attaquer(attacker);
cout <<  attacker.getNom() << " attaque " << target.getNom() << endl;
cout <<  target.getNom() << " a  " << target.statistiques.getVie()<< "  de vie " << endl;

    if (target.statistiques.getVie()<=0){
        cout <<  target.getNom() << " est mort  " <<endl;
        target.setAlive(false);

    }
}*/
void CommandAttack::execute(state::Personnage* target){
    cout <<  target->getNom() << " a  " << target->statistiques->getVie()<< "  de vie " << endl;
    if (target->statistiques->getVie()<=0){
        cout <<"ERREUR "<<  target->getNom() << " est déjà mort  " <<endl;
        exit(0);
    }
    cout <<  currentState->getPersonnageActif()->getNom() << " attaque " << target->getNom() << endl;
    currentState->getPersonnageActif()->attaquer(target);
    currentState->getPersonnageActif();
}
}
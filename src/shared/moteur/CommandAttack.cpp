#include "CommandAttack.h"
#include <iostream>
#include "../state/Personnage.h"

using namespace std;
using namespace moteur;
using namespace state;

CommandAttack::CommandAttack(state::Personnage attacker, state::Personnage target) : attacker(attacker), target(target)
{
    id = ATTACK;
}

void CommandAttack::execute(state::State& state){

    target.attaquer(attacker);
cout <<  attacker.getNom() << " attaque " << target.getNom() << endl;
cout <<  target.getNom() << " a  " << target.statistiques.getVie()<< "  de vie " << endl;

    if (target.statistiques.getVie()<=0){
        cout <<  target.getNom() << " est mort  " <<endl;
        target.setAlive(false);

    }

}


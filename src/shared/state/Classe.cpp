#include "Classe.h"

using namespace state;
Classe::Classe(){
    
}
Classe::Classe(ClasseId classeId, std::string nom, std::vector<float> probaGainStats){    
    (*this).classeId = classeId;
    (*this).probaGainStats = probaGainStats;
    (*this).nom = nom;
    
}

ClasseId Classe::getId(){
    return (*this).classeId;
}
Classe::~Classe(){
    
}
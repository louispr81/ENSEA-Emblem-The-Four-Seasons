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
std::string Classe::getNom(){
    return (*this).nom;
}
std::vector<float> Classe::getProbaGainStats(){
    return (*this).probaGainStats;
}
Classe::~Classe(){
    
}
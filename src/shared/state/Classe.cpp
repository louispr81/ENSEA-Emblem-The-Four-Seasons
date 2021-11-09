#include "Classe.h"
#include "ClasseId.h"
#include <vector>

void Classe::Classe(ClasseId classeId, std::vector<float> probaGainStats )
{    
    this->classeId = classeId;
    this->probaGainStats = probaGainStats;
}

void Classe::~Classe()
{
    
}



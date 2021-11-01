#include "Statistiques.h" 
using namespace state;

void Statistiques::setVie (int vie){
    (*this).vie=vie;
}
void Statistiques::setVie_max (int vie_max){
    (*this).vie_max=vie_max;
}
void Statistiques::setPoint_mouvement (int point_mouvement){
    (*this).point_mouvement=point_mouvement;
}
void Statistiques::setPoint_mouvement_max (int point_mouvement_max){
    (*this).point_mouvement_max=point_mouvement_max;
}
void Statistiques::setForce (int force){
    (*this).force=force;
}
void Statistiques::setIntelligence (int intelligence){
    (*this).intelligence=intelligence;
}
void Statistiques::setVitesse (int vitesse){
    (*this).vitesse=vitesse;
}
void Statistiques::setDefense (int defense){
    (*this).defense=defense;
}
void Statistiques::setResistance (int resistance){
    (*this).resistance=resistance;
}
void Statistiques::setTechnique (int technique){
    (*this).technique=technique;
}
void Statistiques::setExperience (int experience){
    (*this).experience=experience;
}
void Statistiques::setExperience_max (int experience_max){
    (*this).experience_max=experience_max;
}
void Statistiques::setNiveau (int niveau){
    (*this).niveau=niveau;
}
int Statistiques::getVie (){
    return (*this).vie;
}

int Statistiques::getVie_max (){
    return (*this).vie_max;
}
int Statistiques::getPoint_mouvement (){
    return (*this).point_mouvement;
}
int Statistiques::getPoint_mouvement_max (){
    return (*this).point_mouvement_max;
}
int Statistiques::getForce (){
    return (*this).force;
}
int Statistiques::getIntelligence (){
    return (*this).intelligence;
}
int Statistiques::getVitesse (){
    return (*this).vitesse;
}
int Statistiques::getDefense (){
    return (*this).defense;
}
int Statistiques::getResistance (){
    return (*this).resistance;
}
int Statistiques::getTechnique (){
    return (*this).technique;
}
int Statistiques::getExperience (){
    return (*this).experience;
}
int Statistiques::getExperience_max (){
    return (*this).experience_max;
}
int Statistiques::getNiveau (){
    return (*this).niveau;
}
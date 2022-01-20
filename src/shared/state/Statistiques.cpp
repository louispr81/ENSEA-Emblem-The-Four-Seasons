#include "Statistiques.h" 
#include <iostream>
using namespace state;


Statistiques::Statistiques (){}

Statistiques::Statistiques (int vie, int vie_max, int point_mouvement, int point_mouvement_max, int force, int intelligence, int vitesse, int defense, int resistance, int technique, int experience, int experience_max, int niveau){
    this->vie=vie;
    this->vie_max=vie_max;
    this->point_mouvement=point_mouvement;
    this->point_mouvement_max=point_mouvement_max;
    this->force=force;
    this->intelligence=intelligence;
    this->vitesse=vitesse;
    this->defense=defense;
    this->resistance=resistance;
    this->technique=technique;
    this->experience=experience;
    this->experience_max=experience_max;
    this->niveau=niveau;
}

Statistiques::~Statistiques (){}


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
std::vector<int> Statistiques::getListStatistique(){
    std::vector<int> listStatistique;
    listStatistique.push_back(this->vie);
    listStatistique.push_back(this->vie_max);
    listStatistique.push_back(this->point_mouvement_max);
    listStatistique.push_back(this->force);
    listStatistique.push_back(this->intelligence);
    listStatistique.push_back(this->vitesse);
    listStatistique.push_back(this->defense);
    listStatistique.push_back(this->resistance);
    listStatistique.push_back(this->technique);
    return listStatistique;
}
void Statistiques::setListStatistique(std::vector<int> listStatistique){
    this->vie=listStatistique[0]; 
    this->vie_max=listStatistique[1];
    this->point_mouvement_max=listStatistique[2];
    this->force=listStatistique[3];
    this->intelligence=listStatistique[4];
    this->vitesse=listStatistique[5];
    this->defense=listStatistique[6];
    this->resistance=listStatistique[7];
    this->technique=listStatistique[8];
}
void Statistiques::print(){
    std::cout<<"---------------STATISTIQUES---------------"<<std::endl;
    std::cout<<"niveau="<<this->niveau<<std::endl;
    std::cout<<"XP="<<this->experience<<"/"<<this->experience_max<<std::endl;
    std::cout<<"HP="<<this->vie<<"/"<<this->vie_max<<std::endl;
    std::cout<<"PM="<<this->point_mouvement<<"/"<<this->point_mouvement_max<<std::endl;
    std::cout<<"force="<<this->force<<std::endl;
    std::cout<<"intelligence="<<this->intelligence<<std::endl;
    std::cout<<"vitesse="<<this->vitesse<<std::endl;
    std::cout<<"defense="<<this->defense<<std::endl;
    std::cout<<"resistance="<<this->resistance<<std::endl;
    std::cout<<"technique="<<this->technique<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;
}

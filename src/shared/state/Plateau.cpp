 #include "Plateau.h"
 using namespace state;

 Plateau::Plateau(int size){
    std::vector<Cell*> liste_case;
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            std::vector<int> coordonees;
            coordonees.push_back(j);
            coordonees.push_back(i);
            Cell *cell= new Cell(NULL, GRASS, coordonees, true, 1, false);
            liste_case.push_back(cell);
        }
    }
    (*this).size = size;
    (*this).liste_case = liste_case;
 }

Cell Plateau::getCase (int x, int y){
    return *((*this).liste_case[y*((*this).size)+x]);
}
int Plateau::getSize (){
    return (*this).size;
}

Plateau::~Plateau(){
    
}
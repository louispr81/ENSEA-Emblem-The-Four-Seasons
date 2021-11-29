 #include "Plateau.h"
 using namespace state;

 Plateau::Plateau(int size){
    std::vector<Cell*> liste_case;
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            std::vector<int> coordonees;
            coordonees.push_back(j);
            coordonees.push_back(i);
            if (i==size/2 and j!=size/2){
                Cell *cell= new Cell(NULL, RIVER, coordonees, true, 1, false);
                liste_case.push_back(cell);
            }
            else if (i==size/2 and j==size/2){
                Cell *cell= new Cell(NULL, BRIDGE, coordonees, true, 1, false);
                liste_case.push_back(cell);
            }
            else{
                Cell *cell= new Cell(NULL, GRASS_SPRING, coordonees, true, 1, false);
                liste_case.push_back(cell);
            }
            
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
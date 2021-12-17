 #include "Plateau.h"
 #include <iostream>
 using namespace state;

 Plateau::Plateau(int size){
    std::vector<Cell*> liste_case;
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            std::vector<int> *coordonees=new std::vector<int>;
            (*coordonees).push_back(j);
            (*coordonees).push_back(i);
            if (i==size/2 and j!=size/2){
                Cell *cell= new Cell(NULL, RIVER, *coordonees,NULL, true, 1, false);
                cell->setPtCell(cell);
                liste_case.push_back(cell);
            }
            else if (i==size/2 and j==size/2){
                Cell *cell= new Cell(NULL, BRIDGE, *coordonees,NULL, true, 1, false);
                cell->setPtCell(cell);
                liste_case.push_back(cell);
            }
            else{
                Cell *cell= new Cell(NULL, GRASS_SPRING, *coordonees,NULL, true, 1, false);
                cell->setPtCell(cell);
                liste_case.push_back(cell);
            }
            
        }
    }
    (*this).size = size;
    (*this).liste_case = liste_case;
 }

Cell* Plateau::getCase (int x, int y){
    return (*this).liste_case[y*((*this).size)+x]->getPtCell();
}
int Plateau::getSize (){
    return (*this).size;
}

void Plateau::print(){
    std::cout<<"---------------PLATEAU---------------"<<std::endl;
    int y(0);
    int x(0);
    /*
    int printX(0);
    int printY(0);    
    for(y=0;y<this->size;y++){
        for(x=0;x<this->size;x++){
            printX=liste_case[y*((*this).size)+x]->getCoordonees()[0];
            printY=liste_case[y*((*this).size)+x]->getCoordonees()[1];
            std::cout<<"("<<printX<<";"<<printY<<") ";
        }
        std::cout<<"\n";
        for(x=0;x<this->size;x++){
            std::cout<<" type="<<liste_case[y*((*this).size)+x]->getType()<<" ";
        } 
        std::cout<<"\n";
    }
    */
    for(y=0;y<this->size;y++){
        for(x=0;x<this->size;x++){
            if(liste_case[y*((*this).size)+x]->getOccupe()==true){
                std::cout<<" X ";
            }
            else if(liste_case[y*((*this).size)+x]->getOccupe()==false){
                std::cout<<" - ";  
            }
            else{
                std::cout<<" E ";
            }
        }
        std::cout<<"\n";
    }
    std::cout<<"----------------------------------------"<<std::endl;
    for(y=0;y<this->size;y++){
        for(x=0;x<this->size;x++){
            std::cout<<" "<<this->liste_case[y*((*this).size)+x]->getType()<<" ";    
        }
        std::cout<<"\n";
    }
    std::cout<<"----------------------------------------"<<std::endl;
}

Plateau::~Plateau(){
    
}
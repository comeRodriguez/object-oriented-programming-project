#include "Classes.hpp"
#define MAX_STATE 8
#include <time.h>

Model::Model(std::string _name)
{
    name = _name;
    listStates = new std::vector<State*>;
    grid = new Grid();
}

std::string Model::getName() const {
    return name;
}

std::vector<State*>* Model::getListStates() const {
    return listStates;
}

Grid* Model::getGrid() const {
    return grid;
}

void Model::setName(std::string _name) {
    name = _name;
}

void Model::add_State(State* new_state) {
    if (listStates->size() >= MAX_STATE)
    {
        throw std::out_of_range("Maximum number of states reached");
    }
    for (int i = 0; i < listStates->size(); i++)
    {
        if (listStates->at(i)->getIndex() == new_state->getIndex())
        {
            std::cout << "State index already exists, index :" << new_state->getIndex() << std::endl;
            return;
            //throw std::invalid_argument("State index already exists, index : " + std::to_string(new_state->getIndex()));
        }
    }
    listStates->push_back(new_state);
    std::cout << "State added \n";
}

void Model::del_State(State* _state) {
    for (int i = 0; i < listStates->size(); i++)
    {
        if (listStates->at(i) == _state)
        {
            listStates->erase(listStates->begin() + i);
            std::cout << "State deleted" << std::endl;
            return;
        }
    }
}
/*
void Model::initStates() {
     if (name=="Life Game") {
        State* dead_state = new State(0, "white", "dead");
        State* alive_state = new State(1, "black", "alive");
        this->add_State(dead_state);
        this->add_State(alive_state);
    }
    else if (name=="Brians's Brain"){
        State* rest_state = new State(0, "light blue", "rest");
        State* exited_state = new State(1, "yellow", "exited");
        State* refractory_state = new State(2, "purple", "refractory");
        this->add_State(rest_state);
        this->add_State(exited_state);
        this->add_State(refractory_state);
    }
    else if (name=="Griffeath") {
        State* yellow_state = new State(0, "yellow", "yellow");
        State* light_orange_state = new State(1, "light orange", "light orange");
        State* dark_orange_state = new State(2, "dark orange", "dark orange");
        State* red_state = new State(3, "red", "red");
        this->add_State(yellow_state);
        this->add_State(light_orange_state);
        this->add_State(dark_orange_state);
        this->add_State(red_state);
    }
}
*/

void Model::initGrid(int height, int width) {
    //grid = new Grid();
    srand(time(0));//Générer la fonction de graine avec l'heure actuelle pour garantir on n'a pas même résultats chaque fois sur rand()
    //grid = new Grid();
    Cell ** tab = new Cell * [height];
    grid->setTab(tab);
    grid->setHeight(height);
    grid->setWidth(width);


    for (int i = 0; i < height; i++) {
        grid->getTab()[i] = new Cell[width];
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid->getTab()[i][j].setX(i);
            grid->getTab()[i][j].setY(j);
            // L‡ on peut mettre tous les Ètats qu'on veut, moi j'ai juste mis un truc random comme pour le jeu de la vie avec deux Ètats.
           if (name == "Life Game") {
               if (rand() % 2 == 1) {
                    grid->getTab()[i][j].setState(listStates->at(0));
                    grid->getTab()[i][j].initValue();
               }
               else {
                   grid->getTab()[i][j].setState(listStates->at(1));
                   grid->getTab()[i][j].initValue();
               }
           }


           else if (name == "Brian's Brain") {
               if (rand() % 3 == 1) {
                   grid->getTab()[i][j].setState(listStates->at(0));
                   grid->getTab()[i][j].initValue();
               }

               else if (rand() % 3 == 2) {
                   grid->getTab()[i][j].setState(listStates->at(1));
                   grid->getTab()[i][j].initValue();
               }
               else {
                   grid->getTab()[i][j].setState(listStates->at(2));
                   grid->getTab()[i][j].initValue();
               }
           }

           else if (name == "Griffeath") {
               if (rand() % 4 == 1) {
                   grid->getTab()[i][j].setState(listStates->at(0));
                   grid->getTab()[i][j].initValue();
               }
               else if (rand() % 4 == 2) {
                   grid->getTab()[i][j].setState(listStates->at(1));
                   grid->getTab()[i][j].initValue();
               }
               else if (rand() % 4 == 3) {
                   grid->getTab()[i][j].setState(listStates->at(2));
                   grid->getTab()[i][j].initValue();
               }
               else {
                   grid->getTab()[i][j].setState(listStates->at(3));
                   grid->getTab()[i][j].initValue();
               }
           }
        }
    }
}

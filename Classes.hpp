#pragma once
#include <iostream>
#include <vector>
#include <string>



class State {
private:
    int index;
    std::string color;
    std::string label;
public:
    int getIndex() { return index; }
    std::string getColor() { return color; }
    std::string getLabel() { return label; }
    void setIndex(int i) { index=i; }
    void setColor(std::string s) { color=s; }
    void setLabel(std::string l) { label=l; }
    State(int i, std::string c, std::string l) :index(i), color(c), label(l) {}
};


class Cell {
private:
    unsigned int x;
    unsigned int y;
    State* state;
    int value = 0;
public:
    ~Cell() = default;
    Cell(unsigned int X = 0, unsigned int Y = 0) : x(X), y(Y), state(nullptr) {}

    unsigned int getRow() const { return x; }
    unsigned int getCol() const { return y; }
    State* getState() const { return state; }
    void initValue() { if (state == nullptr) throw "Impossible d'initialiser une valeur."; else value = state->getIndex();}
    void setValue(int i) { value = i; }
    int getValue() const { return value;};

    void setX(int _x);
    void setY(int _y);
    void setState(State* _state);
    friend class Grid;
};


class Grid {
private:
    unsigned int width;
    unsigned int height;
    Cell** tab;
public:
    Grid(unsigned int l = 0, unsigned int h = 0) : width(l), height(h), tab(nullptr) {}
    ~Grid() = default;

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned int getNb_Cell() const;
    Cell** getTab();


    void setWidth(unsigned int _width) { width = _width; }
    void setHeight(unsigned int _height) { height = _height; }
    void setTab(Cell** _tab) { tab = _tab; }

    //void initGrid();
};

class Neighbours {
private:
    std::string name;
    unsigned int radius;
    //c'est un indice qui sera r�initialise � chaque utilisation de la m�thode getNeighbours
    //il permet de connaitre le nombre de voisin d'une cellule et ainsi de connaitre la taille
    //du tableau de retour de getNeighbours pour la cellule(i, j)
public:
    std::string getName() { return name; }
    int getRadius() { return radius; }
    std::vector<int> getNeighbours(Grid res, Cell cel);
    Neighbours(std::string n, unsigned int r = 1) : name(n), radius(r) {}
};


class Model
{
protected:
    std::string name;
    std::vector<State*>* listStates; //si transitionRule ='Lifegame ', alors les états sont '0 white dead' '1 black alive'
    //Neighbours neighbourhood;  //ajouter les objets voisinage et transitions dans le modèle ?
    //Transition transitionRule;
    Grid* grid;
public:
    Model(std::string _name = "");
    ~Model() = default;

    std::string getName() const;
    std::vector<State*>* getListStates() const;
    Grid* getGrid() const;

    void setName(std::string _name);
    //void initStates(); Probleme : les etats son créés localement donc impossible de les creer en global a partir de cette methode
    void initGrid(int width, int length);
    void add_State(State* new_state);
    void del_State(State* _state);
};

class Transition {
private:
    std::string name;
public:
    std::string getNom() { return name; }
    int SetTransition(Grid& res, Cell& c, Neighbours& neighbourhood);
    Transition(std::string s) : name(s) {}
    //friend class Neighbours;
    //friend class Cell;
};

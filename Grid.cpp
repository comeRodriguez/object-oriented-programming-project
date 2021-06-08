#include "Classes.hpp"
#include <iostream>
#include <string>


unsigned int Grid::getWidth() const { return width; }

unsigned int Grid::getHeight() const { return height; }

unsigned int Grid::getNb_Cell() const { return width * height; }

Cell** Grid::getTab() { return tab; }

/*
void Grid::initGrid() {
    tab = new Cell * [height];
    State* default_state = new State(1, "default", "white");
    State* dead_state = new State(2, "noir", "mort");
    for (unsigned int i = 0; i < height; i++) {
        tab[i] = new Cell[width];
    }
    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            tab[i][j] = Cell(i, j);
            if (rand() % 2 == 1)
                tab[i][j].state = default_state;
            else
                tab[i][j].state = dead_state;
        }
    }
}
*/

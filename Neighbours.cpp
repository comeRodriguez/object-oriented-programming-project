#include "Classes.hpp"
#include <iostream>
#include <string>
#include <array>
#include <vector>


std::vector<int> Neighbours::getNeighbours(Grid res, Cell cel) {
    Cell** tab = res.getTab();
    int l = res.getHeight();
    int h = res.getWidth();
    int b = cel.getCol();
    int a = cel.getRow();
    int c1 = a - radius;
    int c2 = a + radius;
    int c3 = b - radius;
    int c4 = b + radius;
    std::vector<int> voisin;
    if (name == "Von Neumann") {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < h; j++) {
                if ((abs(i - a) + abs(j - b)) <= radius && (a != i || b != j)) { // cas general ( aucun voisin ne sort du tableau)
                    voisin.push_back(tab[i][j].getState()->getIndex());
                }
                if (c1 < 0) { // cas ou le voisin est "en haut" du tableau
                    if ((abs(i - a - l) + abs(j - b)) <= radius) { // donc je fais a=a+l
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c2 >= l) { // en bas
                    if ((abs(i - a + l) + abs(j - b)) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c3 < 0) { // gauche
                    if ((abs(i - a) + abs(j - b - h)) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c4 >= h) { // droite
                    if ((abs(i - a) + abs(j - b + h)) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c4 >= h && c2 >= l) { // maintenant on doit aussi gerer les cas ou aucune coordone du voisin n'est dans le tableau
                    if ((abs(i - a + l) + abs(j - b + h)) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c4 >= h && c1 < 0) {
                    if ((abs(i - a - l) + abs(j - b + h)) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c3 < 0 && c2 >= l) {
                    if ((abs(i - a + l) + abs(j - b - h)) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c3 < 0 && c1 < 0) {
                    if ((abs(i - a - l) + abs(j - b - h)) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
            }
        }
    }
    else if (name == "Moore") {

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < h; j++) {
                if (abs(i - a) <= radius && abs(j - b) <= radius && (a != i || b != j)) {
                    voisin.push_back(tab[i][j].getState()->getIndex());
                }
                if (c1 < 0) {
                    if (abs(i - a - l) <= radius && abs(j - b) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c2 >= l) {
                    if (abs(i - a + l) <= radius && abs(j - b) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c3 < 0) {
                    if (abs(i - a) <= radius && abs(j - b - h) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c4 >= h) {
                    if (abs(i - a) <= radius && abs(j - b + h) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c4 >= h && c2 >= l) {
                    if (abs(i - a + l) <= radius && abs(j - b + h) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c4 >= h && c1 < 0) {
                    if (abs(i - a - l) <= radius && abs(j - b + h) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c3 < 0 && c2 >= l) {
                    if (abs(i - a + l) <= radius && abs(j - b - h) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
                if (c3 < 0 && c1 < 0) {
                    if (abs(i - a - l) <= radius && abs(j - b - h) <= radius) {
                        voisin.push_back(tab[i][j].getState()->getIndex());
                    }
                }
            }
        }
        //std::cout<<"il y a "<<c<<" voisins"<<std::endl;

    }
    return voisin;
}

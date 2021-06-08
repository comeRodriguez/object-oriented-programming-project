#include "Classes.hpp"
#include <iostream>
#include <string>


int Transition::SetTransition(Grid& res, Cell& c, Neighbours& neighbourhood) {

    std::vector<int> neighbours = neighbourhood.getNeighbours(res,c);
    int nb = 0; //nombre de voisins avec un certain état
    int index=0;

    if (name == "Life Game") { // 2 etats possibles : 0 (mort) ou 1 (vivant)

        for (int i=0; i<neighbours.size(); i++) {
            if (neighbours[i] == 1) {
                nb++;         //on recupere le nombre de cellules voisines selon l'état désiré (ici etat=vivant=1)
            }
        }

        if ((c.getState()->getIndex() == 0) && (nb == 3)) {
            index=1;
        }

        else if (c.getState()->getIndex() == 1) {
            if (nb == 2 || nb == 3) {
                index=1;
            }
        }
        else {
            index=0;
        }
    }

    else if (name == "Brian's Brain") { // 3 etats possibles : 0 (repos) ou 1 (exité) ou 2 (réfractaire)

        for (size_t i=0; i<neighbours.size(); i++) {
            if (neighbours[i] == 1) {
                nb++;         //on recupere le nombre de cellules voisines selon l'état désiré (ici etat=exité=1)
            }
            if (c.getState()->getIndex() == 1) {
                index=2;
            }
            else if (c.getState()->getIndex() == 2) {
                index=0;
            }
            else if ((c.getState()->getIndex() == 0) && (nb == 2)){ //2 voisins (selon voisinage de Moore) exitées
                index=1;
            }

        }
    }
    else if (name == "Griffeath") { // 4 etats possibles : 0 (jaune) ou 1 (orange clair) ou 2 (orange foncé) ou 3 (rouge)

        for (size_t i=0; i < neighbours.size(); i++) {
            if (neighbours[i] == (c.getState()->getIndex() + 1) % 4) {
                nb++;         //on recupere le nombre de cellules voisines selon l'état désiré (ici etat= (index_etat + 1 )%4)
            }
        }

        if (nb >= 3) { // si couleur (index_etat+1)%4 est present dans au moins 3 voisins
            index= (c.getState()->getIndex() + 1) % 4 ;
        }
    }
 //8 etats possibles
    else if (name == "Langston's Loop") { //voisinage von newman
      /*regles a specifier*/
    }
    else {
        std::cout<<"Aucune regle de transition ne correspond au nom rentre";
    }

    return index;
}



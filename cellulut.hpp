#ifndef CELLULUT_HPP
#define CELLULUT_HPP

#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QString>
#include <qboxlayout.h>
#include <QTableWidget>
#include <QHeaderView>
#include <QModelIndex>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <string>
#include "Classes.hpp"


class cellulutSimulation : public QWidget {
    Q_OBJECT
    int size_grid = 25;

    Model* modele;
    Neighbours* neighbourhood;
    Transition* rules;

    QLabel* speech;
    QLabel* grid_dimensions;
    QLabel* information;
    QLabel* information2;
    QLabel* speedSpeech;

    QHBoxLayout* simulator;
    QVBoxLayout* settings;

    QTableWidget* reseau;

    QSlider* speed;

    QPushButton* quit;
    QPushButton* display;
    QPushButton* next;
    QPushButton* reverse;
    QPushButton* displayEmptyGrid;
    QPushButton* stop;
    QPushButton* launch;

public :
    explicit cellulutSimulation(QWidget* parent = nullptr);
    void afficherGrid();
   // void setSizeGrid() {size_grid = cellulutModeles::height_grid->value();};

private slots :
    //void setSizeGrid(const QSpinBox* spin);
    void displayGrid() {this->show();};
    void initGrid();
    void initEmptyGrid();
    void afficherSimulation();

    void choiceVoisinageMoore();
    void choiceVoisinageVonNeumann();
    void choiceVoisinageVonNeumannGen();
    void choiceVoisinageMooreGen();

    void choiceFonctionLifeGame();
    void choiceFonctionBriansBrain();
    void choiceFonctionGriffeath();
    void choiceFonctionLangstonLoop();

    void GameLife();
    void BriansBrain();
    void Griffeath();
    void LangstonLoop();

    void stopSimulation();

    void modeAuto();
    void modeManu();

    void lancementAuto();
    void lancementManu();

    void celluleActivation(const QModelIndex& index);
};

class cellulutChoices : public QWidget {
    Q_OBJECT
    QButtonGroup* voisi;
    QButtonGroup* fonc;
    QButtonGroup* mode;
    QButtonGroup* lancement;

    QLabel* grid_dimensions;
    QLabel* voisinageSpeech;
    QLabel* fonctionSpeech;
    QLabel* choixSpeech;
    QLabel* modeSpeech;
    QLabel* lancementSpeech;

    QPushButton* execute;
    QPushButton* fermer;

    QVBoxLayout* modeLayout;
    QVBoxLayout* lancementLayout;
    QVBoxLayout* choix;
    QVBoxLayout* fonctions;
    QVBoxLayout* voisinage;
    QHBoxLayout* organisation;

    QRadioButton* vonNeumann;
    QRadioButton* vonNeumannGene;
    QRadioButton* moore;
    QRadioButton* mooreGene;
    QRadioButton* lifeGame;
    QRadioButton* briansBrain;
    QRadioButton* griffeath;
    QRadioButton* langstonLoop;
    QRadioButton* modeAuto;
    QRadioButton* modeManu;
    QRadioButton* lancementAlea;
    QRadioButton* lancemenManu;

    cellulutSimulation* fonctionnement;



public:
    explicit cellulutChoices(QWidget* parent = nullptr);

private slots :
    void afficherMenu();
};

class cellulutModeles: public QWidget {
    Q_OBJECT
    QButtonGroup* mode;
    QButtonGroup* lancement;

    QLabel* grid_dimensions;
    QLabel* modeleSpeech;
    QLabel* modeSpeech;
    QLabel* lancementSpeech;

    QPushButton* execute;
    QPushButton* fermer;

    QVBoxLayout* modeles;
    QVBoxLayout* modeLayout;
    QVBoxLayout* lancementLayout;

    QRadioButton* lifeGame;
    QRadioButton* briansBrain;
    QRadioButton* griffeath;
    QRadioButton* langstonLoop;
    QRadioButton* modeAuto;
    QRadioButton* modeManu;
    QRadioButton* lancementAlea;
    QRadioButton* lancemenManu;

    cellulutSimulation* fonctionnement;




public :
    explicit cellulutModeles(QWidget* parent = nullptr);
   friend class cellulutSimulation;
private slots :
    void afficherModeles();

     };


class cellulut : public QWidget
{
    Q_OBJECT
    QVBoxLayout* appli;
    QPushButton* menu;
    QPushButton* modeles;
    cellulutSimulation* fonctionnement;
    cellulutChoices* choices;
    cellulutModeles* modelePredefined;
    QPushButton* fermer;
    QLabel* intro;


public:
    explicit cellulut(QWidget* parent = nullptr);


};



#endif // CELLULUT_HPP

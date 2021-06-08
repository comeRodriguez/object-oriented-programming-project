#include "cellulut.hpp"


cellulutSimulation::cellulutSimulation(QWidget* parent): QWidget(parent) {

    modele = new Model;
    neighbourhood = new Neighbours("Moore");
    rules = new Transition("Life Game");
// new spinbox -> size_grid
// void setSizeGrid => size_grid = spinbox->value()
// setmin et setmax
    grid_dimensions = new QLabel("\n Veuillez indiquer les dimensions de la grille (hauteur = largeur)");
    speedSpeech = new QLabel("Vitesse : ");
    speech = new QLabel("Ici les réglages de la simulation :");
    information = new QLabel;
    information2 = new QLabel;

    display = new QPushButton("Afficher la grille");
    next = new QPushButton("Génération suivante");
    next->setVisible(false);
    reverse = new QPushButton("Génération précédente");
    speed = new QSlider(Qt::Horizontal);
    quit = new QPushButton("Pour quitter la simulation, veuillez cliquer ici");
    displayEmptyGrid = new QPushButton("Afficher la grille vide");
    displayEmptyGrid->setVisible(false);
    stop = new QPushButton("Pause");
    launch = new QPushButton("Lancer la simulation");

    simulator = new QHBoxLayout;
    settings = new QVBoxLayout;

    reseau = new QTableWidget;



    settings->addWidget(speech);
    settings->addWidget(information);
    settings->addWidget(information2);
    settings->addWidget(speedSpeech);
    settings->addWidget(speed);
    settings->addWidget(displayEmptyGrid);
    settings->addWidget(display);
    settings->addWidget(launch);
    settings->addWidget(stop);
    settings->addWidget(next);
    settings->addWidget(reverse);
    settings->addWidget(quit);
    simulator->addLayout(settings);
    simulator->addWidget(reseau);

    connect(quit, SIGNAL(clicked()), this, SLOT(stopSimulation()));
    connect(display, SIGNAL(clicked()), this, SLOT(initGrid()));
    connect(next, SIGNAL(clicked()), this, SLOT(afficherSimulation()));
    connect(displayEmptyGrid, SIGNAL(clicked()), this, SLOT(initEmptyGrid()));

    setLayout(simulator);
}

//void cellulutSimulation::setSizeGrid(const QSpinBox* spin) {
//    size_grid = spin->value();
//}

void cellulutSimulation::stopSimulation() {
    while (reseau->rowCount() > 0) {
        reseau->removeRow(0);
    }
    modele = new Model();
    this->close();
}

void cellulutSimulation::modeAuto() {
    next->setVisible(false);
    launch->setVisible(true);
    stop->setVisible(true);
}

void cellulutSimulation::modeManu() {
    next->setVisible(true);
    launch->setVisible(false);
    stop->setVisible(false);
}

void cellulutSimulation::lancementAuto() {
    displayEmptyGrid->setVisible(false);
    display->setVisible(true);
}

void cellulutSimulation::lancementManu() {
    displayEmptyGrid->setVisible(true);
    display->setVisible(false);
    connect(reseau, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(celluleActivation(const QModelIndex&)));
}

void cellulutSimulation::celluleActivation(const QModelIndex& index) {
        if (reseau->item(0, index.column())->background() == Qt::white)
            reseau->item(0, index.column())->setBackground(Qt::blue);
        else
            reseau->item(0, index.column())->setBackground(Qt::white);
}

void cellulutSimulation::initEmptyGrid() {
    if (modele->getName() == "Game Life") {
        State* one_state = new State(1, "blanc", "vivant");
        State* two_state = new State(2, "noir", "mort");
        modele->add_State(one_state);
        modele->add_State(two_state);
        modele->initGrid(size_grid, size_grid);
    }

    else if (modele->getName() == "Brian's Brain") {
        State* one_state = new State(1, "blanc", "");
        State* two_state = new State(2, "bleu", "");
        State* three_state = new State(3, "vert", "");
        modele->add_State(one_state);
        modele->add_State(two_state);
        modele->add_State(three_state);
        modele->initGrid(size_grid, size_grid);
    }

    else if (modele->getName() == "Griffeath") {
        State* one_state = new State(1, "jaune", "");
        State* two_state = new State(2, "orange clair", "");
        State* three_state =new State(3, "orange foncé", "");
        State* four_state = new State(4, "rouge", "");
        modele->add_State(one_state);
        modele->add_State(two_state);
        modele->add_State(three_state);
        modele->add_State(four_state);
        modele->initGrid(size_grid, size_grid);
    }

    else {
        modele = new Model("Game Life");
        State* default_state = new State(1, "blanc", "vivant");
        State* dead_state = new State(2, "noir", "mort");
        modele->add_State(default_state);
        modele->add_State(dead_state);
        modele->initGrid(size_grid, size_grid);
    }

    simulator->removeWidget(reseau);
    while (reseau->rowCount() > 0) {
        reseau->removeRow(0);
    }
    reseau = new QTableWidget(size_grid, size_grid);
    reseau->setFixedSize(25*size_grid, 25*size_grid);
    reseau->horizontalHeader()->setVisible(false);
    reseau->verticalHeader()->setVisible(false);
    reseau->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    reseau->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    reseau->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i=0; i<size_grid; i++)
    {
        reseau->setColumnWidth(i,size_grid);
        reseau->setRowHeight(i,size_grid);
    }

    for (int i = 0; i < size_grid ; i++ ) {
        for(int j=0; j<size_grid; j++)
        {
        reseau->setItem(j, i, new QTableWidgetItem(""));
        reseau->item(j, i)->setBackground(Qt::white);
        }
    }
    simulator->addWidget(reseau);
    this->show();
}

void cellulutSimulation::initGrid() {
    if (modele->getName() == "Life Game") {
        State* one_state = new State(1, "blanc", "vivant");
        State* two_state = new State(2, "noir", "mort");
        modele->add_State(one_state);
        modele->add_State(two_state);
        modele->initGrid(size_grid, size_grid);
    }

    else if (modele->getName() == "Brian's Brain") {
        State* one_state = new State(1, "blanc", "");
        State* two_state = new State(2, "bleu", "");
        State* three_state = new State(3, "vert", "");
        modele->add_State(one_state);
        modele->add_State(two_state);
        modele->add_State(three_state);
        modele->initGrid(size_grid, size_grid);
    }

    else if (modele->getName() == "Griffeath") {
        State* one_state = new State(1, "jaune", "");
        State* two_state = new State(2, "orange clair", "");
        State* three_state =new State(3, "orange foncé", "");
        State* four_state = new State(4, "rouge", "");
        modele->add_State(one_state);
        modele->add_State(two_state);
        modele->add_State(three_state);
        modele->add_State(four_state);
        modele->initGrid(size_grid, size_grid);
    }

    else {
        modele = new Model("Life Game");
        State* default_state = new State(1, "blanc", "vivant");
        State* dead_state = new State(2, "noir", "mort");
        modele->add_State(default_state);
        modele->add_State(dead_state);
        modele->initGrid(size_grid, size_grid);
    }

    simulator->removeWidget(reseau);
    while (reseau->rowCount() > 0) {
        reseau->removeRow(0);
    }
    reseau = new QTableWidget(size_grid, size_grid);
    reseau->setFixedSize(25*size_grid, 25*size_grid);
    reseau->horizontalHeader()->setVisible(false);
    reseau->verticalHeader()->setVisible(false);
    reseau->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    reseau->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    reseau->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i=0; i<size_grid; i++)
    {
        reseau->setColumnWidth(i,size_grid);
        reseau->setRowHeight(i,size_grid);
    }

    afficherGrid();
    simulator->addWidget(reseau);
    this->show();
}

void cellulutSimulation::afficherGrid() {
    if (modele->getName() == "Life Game") {
        for (int i = 0; i < size_grid ; i++ ) {
            for(int j=0; j<size_grid; j++)
            {
            reseau->setItem(j, i, new QTableWidgetItem(""));

                if (modele->getGrid()->getTab()[j][i].getValue() == 1)
                    reseau->item(j,i)->setBackground(Qt::white);
                else
                    reseau->item(j,i)->setBackground(Qt::black);
            }
        }
    }

    if (modele->getName() == "Brian's Brain") {
        for (int i = 0; i < size_grid ; i++ ) {
            for(int j=0; j<size_grid; j++)
            {
            reseau->setItem(j, i, new QTableWidgetItem(""));

                if (modele->getGrid()->getTab()[j][i].getValue() == 1)
                    reseau->item(j,i)->setBackground(Qt::white);
                else if (modele->getGrid()->getTab()[j][i].getValue() == 2)
                    reseau->item(j,i)->setBackground(Qt::black);
                else
                    reseau->item(j,i)->setBackground(Qt::red);
            }
        }
    }


    if (modele->getName() == "Griffeath") {
        for (int i = 0; i < size_grid ; i++ ) {
            for(int j=0; j<size_grid; j++)
            {
                reseau->setItem(j, i, new QTableWidgetItem(""));

                if (modele->getGrid()->getTab()[j][i].getValue() == 1)
                    reseau->item(j,i)->setBackground(Qt::yellow);
                else if (modele->getGrid()->getTab()[j][i].getValue() == 2)
                    reseau->item(j,i)->setBackground(Qt::darkYellow);
                else if (modele->getGrid()->getTab()[j][i].getValue() == 3)
                    reseau->item(j,i)->setBackground(Qt::red);
                else
                    reseau->item(j,i)->setBackground(Qt::darkRed);
            }
        }
    }
}

void cellulutSimulation::afficherSimulation() {
    Model* modele2 = modele;
    for (unsigned int i = 0; i < modele->getGrid()->getHeight(); i++) {
            for (unsigned int j = 0; j < modele->getGrid()->getWidth(); j++) {
                modele2->getGrid()->getTab()[i][j].setValue(rules->SetTransition(*modele->getGrid(), modele->getGrid()->getTab()[i][j], *neighbourhood));

            }
        }

        for (unsigned int i = 0; i < modele->getGrid()->getHeight(); i++) {
            for (unsigned int j = 0; j < modele->getGrid()->getWidth(); j++) {
                modele->getGrid()->getTab()[i][j].setValue(modele2->getGrid()->getTab()[i][j].getValue());
            }
        }
        afficherGrid();
    this->show();
}

void cellulutSimulation::choiceVoisinageMoore() {
    neighbourhood = new Neighbours("Moore");
    information->setText("Voisinage de Moore");
}

void cellulutSimulation::choiceVoisinageMooreGen() {

    neighbourhood = new Neighbours("Moore généralisé");
    information->setText("Voisinage de Moore généralisé");
}


void cellulutSimulation::choiceVoisinageVonNeumann() {

    neighbourhood = new Neighbours("Von Neumann");
    information->setText("Voisinage de Von Neumann");
}

void cellulutSimulation::choiceVoisinageVonNeumannGen() {

    neighbourhood = new Neighbours("Von Neumann généralisé");
    information->setText("Voisinage de Von Neumann généralisé");
}

void cellulutSimulation::choiceFonctionLifeGame() {
    modele = new Model("Life Game");
    rules = new Transition("Life Game");
    information2->setText("Fonction de transition de life game.");
}

void cellulutSimulation::choiceFonctionBriansBrain() {
    modele = new Model("Brian's Brain");
    rules = new Transition("Brian's Brain");
    information2->setText("Fonction de transition de Brian's Brain.");
}

void cellulutSimulation::choiceFonctionGriffeath() {
    modele = new Model("Griffeath");
    rules = new Transition("Griffeath");
    information2->setText("Fonction de transition de Griffeath.");
}

void cellulutSimulation::choiceFonctionLangstonLoop() {
    information2->setText("Fonction de transition de Langston's Loop.");
}

void cellulutSimulation::GameLife() {
    modele = new  Model("Life Game");
    neighbourhood = new Neighbours("Moore");
    rules = new Transition("Life Game");
    information->setText("Simulation du modèle de Game Life");
}

void cellulutSimulation::BriansBrain() {
    modele = new  Model("Brian's Brain");
    neighbourhood = new Neighbours("Moore");
    rules = new Transition("Brian's Brain");
    information->setText("Simulation du modèle de Brian's Brain");
}

void cellulutSimulation::Griffeath() {
    modele = new  Model("Griffeath");
    neighbourhood = new Neighbours("Moore");
    rules = new Transition("Griffeath");
    information->setText("Simulation de l'automate cellulaire de Griffeath");
}

void cellulutSimulation::LangstonLoop() {

    information->setText("Simulation du modèle de Langston's Loop");
}


#include "cellulut.hpp"


cellulut::cellulut(QWidget* parent): QWidget(parent)
{
    menu =  new QPushButton("Choisir ses propres réglages");
    appli = new QVBoxLayout;
    modeles = new QPushButton("Choisir parmis des modèles pré-existants");
    intro = new QLabel("Bienvenue dans Cellulut \nVeuillez choisir votre configuration : \n");
    intro->setFont(QFont("Helvetica", 36, QFont::Bold));

    fonctionnement = new cellulutSimulation;
    modelePredefined = new cellulutModeles;
    choices = new cellulutChoices;
    fermer = new QPushButton("Fermer l'application");


    appli->addWidget(intro);
    appli->addWidget(modeles);
    appli->addWidget(menu);
    appli->addWidget(fermer);

    setLayout(appli);
    connect(modeles, SIGNAL(clicked()), modelePredefined, SLOT(afficherModeles()));
    connect(menu, SIGNAL(clicked()), choices, SLOT(afficherMenu()));
    connect(fermer, SIGNAL(clicked()), this, SLOT(close()));

}


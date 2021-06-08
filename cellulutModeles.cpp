#include "cellulut.hpp"

cellulutModeles::cellulutModeles(QWidget* parent): QWidget(parent) {

    mode = new QButtonGroup;
    lancement = new QButtonGroup;

    fermer = new QPushButton("Pour fermer l'onglet, cliquer ici");
    execute = new QPushButton("Accéder à l'onglet de simulation");

    modeles = new QVBoxLayout;
    modeLayout = new QVBoxLayout;
    lancementLayout = new QVBoxLayout;

    modeleSpeech = new QLabel("Vous pouvez ici choisir parmis des modèles prédéfinis : \n (Par défaut le choix est fait sur Game Life)");
    modeleSpeech->setFont(QFont("Helvetica", 24));
    modeSpeech = new QLabel("Choix du mode de la simulation : ");
    modeSpeech->setFont(QFont("Helvetica", 14, QFont::Bold));
    lancementSpeech = new QLabel("Choix de l'initialisation de la grille : ");
    lancementSpeech->setFont(QFont("Helvetica", 14, QFont::Bold));

    lifeGame = new QRadioButton("Life Game");
    lifeGame->setChecked(true);
    briansBrain = new QRadioButton("Brian's Brain");
    griffeath = new QRadioButton("L'automate circulaire de Griffeath");
    langstonLoop = new QRadioButton("Langston's Loop");
    modeAuto = new QRadioButton("Mode automatique");
    modeAuto->setChecked(true);
    modeManu = new QRadioButton("Mode pas à pas");
    lancementAlea = new QRadioButton("Aléatoire");
    lancementAlea->setChecked(true);
    lancemenManu = new QRadioButton("Manuelle");

    fonctionnement = new cellulutSimulation;


    mode->addButton(modeAuto);
    mode->addButton(modeManu);

    lancement->addButton(lancementAlea);
    lancement->addButton(lancemenManu);

    modeLayout->addWidget(modeSpeech);
    modeLayout->addWidget(modeAuto);
    modeLayout->addWidget(modeManu);

    lancementLayout->addWidget(lancementSpeech);
    lancementLayout->addWidget(lancementAlea);
    lancementLayout->addWidget(lancemenManu);

    modeles->addWidget(modeleSpeech);
    modeles->addWidget(lifeGame);
    modeles->addWidget(briansBrain);
    modeles->addWidget(griffeath);
    modeles->addWidget(langstonLoop);
    modeles->addLayout(modeLayout);
    modeles->addLayout(lancementLayout);
    modeles->addWidget(execute);
    modeles->addWidget(fermer);


    connect(lifeGame, SIGNAL(toggled(bool)), fonctionnement, SLOT(GameLife()));
    connect(briansBrain, SIGNAL(toggled(bool)), fonctionnement, SLOT(BriansBrain()));
    connect(griffeath, SIGNAL(toggled(bool)), fonctionnement, SLOT(Griffeath()));
    connect(langstonLoop, SIGNAL(toggled(bool)), fonctionnement, SLOT(LangstonLoop()));
    connect(execute, SIGNAL(clicked()), fonctionnement, SLOT(displayGrid()));
    connect(fermer, SIGNAL(clicked()), this, SLOT(close()));

    connect(modeAuto, SIGNAL(toggled(bool)), fonctionnement, SLOT(modeAuto()));
    connect(modeManu, SIGNAL(toggled(bool)), fonctionnement, SLOT(modeManu()));

    connect(lancemenManu, SIGNAL(toggled(bool)), fonctionnement, SLOT(lancementManu()));
    connect(lancementAlea, SIGNAL(toggled(bool)), fonctionnement, SLOT(lancementAuto()));

    setLayout(modeles);
}

void cellulutModeles::afficherModeles() {
    this->show();
}

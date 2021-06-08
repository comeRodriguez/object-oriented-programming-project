#include "cellulut.hpp"

cellulutChoices::cellulutChoices(QWidget* parent) : QWidget(parent) {

    voisi = new QButtonGroup;
    fonc = new QButtonGroup;
    mode = new QButtonGroup;
    lancement = new QButtonGroup;

    execute = new QPushButton("Lancer la simulation");
    fermer = new QPushButton("Pour fermer l'onglet, cliquer ici");

    voisinageSpeech = new QLabel("Voisinages : \n");
    voisinageSpeech->setFont(QFont("Helvetica", 14, QFont::Bold));
    fonctionSpeech = new QLabel("Fonctions de transitions : \n");
    fonctionSpeech->setFont(QFont("Helvetica", 14, QFont::Bold));
    choixSpeech = new QLabel("Vous pouvez ici choisir votre propre voisinage et votre propre fonction de transition :\n(Par défaut le choix est fait sur le voisinage de Moore et la fonction de transtion de Life Game)");
    choixSpeech->setFont(QFont("Helvetica", 24));
    modeSpeech = new QLabel("Choix du mode de la simulation : ");
    modeSpeech->setFont(QFont("Helvetica", 14, QFont::Bold));
    lancementSpeech = new QLabel("Choix de l'initialisation de la grille : ");
    lancementSpeech->setFont(QFont("Helvetica", 14, QFont::Bold));

    choix = new QVBoxLayout;
    organisation = new QHBoxLayout;
    fonctions = new QVBoxLayout;
    voisinage = new QVBoxLayout;
    modeLayout = new QVBoxLayout;
    lancementLayout = new QVBoxLayout;


    vonNeumann = new QRadioButton("von Neumann");
    vonNeumannGene = new QRadioButton("von Neumann généralisé");
    moore = new QRadioButton("Moore");
    moore->setChecked(true);
    mooreGene = new QRadioButton("Moore généralisé");
    lifeGame = new QRadioButton("Life Game");
    lifeGame->setChecked(true);
    briansBrain = new QRadioButton("Brian's Brain");
    griffeath = new QRadioButton("Griffeath");
    langstonLoop = new QRadioButton("Langston's Loop");
    modeAuto = new QRadioButton("Mode automatique");
    modeAuto->setChecked(true);
    modeManu = new QRadioButton("Mode pas à pas");
    lancementAlea = new QRadioButton("Aléatoire");
    lancementAlea->setChecked(true);
    lancemenManu = new QRadioButton("Manuelle");


    fonctionnement = new cellulutSimulation;



    voisi->addButton(vonNeumann);
    voisi->addButton(vonNeumannGene);
    voisi->addButton(moore);
    voisi->addButton(mooreGene);

    fonc->addButton(lifeGame);
    fonc->addButton(briansBrain);
    fonc->addButton(griffeath);
    fonc->addButton(langstonLoop);

    mode->addButton(modeAuto);
    mode->addButton(modeManu);

    lancement->addButton(lancementAlea);
    lancement->addButton(lancemenManu);

    choix->addWidget(choixSpeech);

    voisinage->addWidget(voisinageSpeech);
    voisinage->addWidget(vonNeumann);
    voisinage->addWidget(vonNeumannGene);
    voisinage->addWidget(moore);
    voisinage->addWidget(mooreGene);

    fonctions->addWidget(fonctionSpeech);
    fonctions->addWidget(lifeGame);
    fonctions->addWidget(briansBrain);
    fonctions->addWidget(griffeath);
    fonctions->addWidget(langstonLoop);

    modeLayout->addWidget(modeSpeech);
    modeLayout->addWidget(modeAuto);
    modeLayout->addWidget(modeManu);

    lancementLayout->addWidget(lancementSpeech);
    lancementLayout->addWidget(lancementAlea);
    lancementLayout->addWidget(lancemenManu);

    choix->addLayout(voisinage);
    choix->addLayout(fonctions);
    choix->addLayout(organisation);
    choix->addLayout(modeLayout);
    choix->addLayout(lancementLayout);
    choix->addWidget(execute);
    choix->addWidget(fermer);

    connect(moore, SIGNAL(toggled(bool)), fonctionnement, SLOT(choiceVoisinageMoore()));
    connect(mooreGene, SIGNAL(toggled(bool)), fonctionnement, SLOT(choiceVoisinageMooreGen()));
    connect(vonNeumann, SIGNAL(toggled(bool)), fonctionnement, SLOT(choiceVoisinageVonNeumann()));
    connect(vonNeumannGene, SIGNAL(toggled(bool)), fonctionnement, SLOT(choiceVoisinageVonNeumannGen()));

    connect(lifeGame, SIGNAL(toggled(bool)), fonctionnement, SLOT(choiceFonctionLifeGame()));
    connect(briansBrain, SIGNAL(toggled(bool)), fonctionnement, SLOT(choiceFonctionBriansBrain()));
    connect(griffeath, SIGNAL(toggled(bool)), fonctionnement, SLOT(choiceFonctionGriffeath()));
    connect(langstonLoop, SIGNAL(toggled(bool)), fonctionnement, SLOT(choiceFonctionLangstonLoop()));

    connect(execute, SIGNAL(clicked()), fonctionnement, SLOT(displayGrid()));
    connect(fermer, SIGNAL(clicked()), this, SLOT(close()));

    connect(modeAuto, SIGNAL(toggled(bool)), fonctionnement, SLOT(modeAuto()));
    connect(modeManu, SIGNAL(toggled(bool)), fonctionnement, SLOT(modeManu()));

    connect(lancemenManu, SIGNAL(toggled(bool)), fonctionnement, SLOT(lancementManu()));
    connect(lancementAlea, SIGNAL(toggled(bool)), fonctionnement, SLOT(lancementAuto()));

    setLayout(choix);
}

void cellulutChoices::afficherMenu() {

    this->show();
}

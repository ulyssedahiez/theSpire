//
// Created by Ulysse Dahiez on 11/06/2022.
//

#include "CombatController.h"
#include "stdio.h"
#include "../../Vue/Menu/Headers/Affichages.h"
#include "../../Vue/Menu/Headers/Menu.h"

p_donneesCombat creerDonneesCombat() {
    p_donneesCombat donneesCombat = malloc(sizeof(t_donneesCombat));

    donneesCombat->pioche = creerListeCartes();
    donneesCombat->defausse = creerListeCartes();
    donneesCombat->joueur = NULL;
    donneesCombat->mainJoueur = creerListeCartes();
    donneesCombat->cartesAJouer = creerListeCartes();
    donneesCombat->map = NULL;

    donneesCombat->abysses = creerListeCartes();
    donneesCombat->attaqueRoundMonstre = NULL;
}

void processusCombat(p_donneesCombat donneesCombat, bool debug) {
    processusDebutCombat(donneesCombat, debug);
    while (donneesCombat->joueur->pointsVieActuels > 0 && donneesCombat->salleActuelle->monstre->pointsVie > 0) {
        processusRound(donneesCombat, debug);
        if (debug == true) {
            donneesCombat->salleActuelle->monstre->pointsVie = 0;
        }
    }
}

void processusDebutCombat(p_donneesCombat donneesCombat, bool debug) {
    donneesCombat->joueur->pointsManaActuels = donneesCombat->joueur->pointsManaMax;
    donneesCombat->defausse = creerListeCartes();
    donneesCombat->cartesAJouer = creerListeCartes();
    donneesCombat->mainJoueur = creerListeCartes();
    donneesCombat->pioche = copierListeCartes(donneesCombat->joueur->deckPrincipal);

    p_objetChainable objetAAppliquer = donneesCombat->joueur->listeObjets->premiereObjet;
    while (objetAAppliquer != NULL) {// TODO: appliquer bonus objets peter
        ajouterEffetListe(donneesCombat->joueur->listeEffetsSubis, objetAAppliquer->objet->effet);

        objetAAppliquer = objetAAppliquer->objetSuivant;
    }
    afficherListeObjets(donneesCombat->joueur->listeObjets, 5);

    donneesCombat->joueur->pointsManaActuels = donneesCombat->joueur->pointsManaMax;
}

void processusDebutRound(p_donneesCombat donneesCombat, bool debug) {
    donneesCombat->attaqueRoundMonstre = trouverNiemeAttaque(donneesCombat->salleActuelle->monstre->attaques,
                                                             genererEntier(0, donneesCombat->salleActuelle->monstre->attaques->nombreAttaques));
    printf("Mouahaha je suis %s et je vais attaquer ! (%d PVs) (", donneesCombat->salleActuelle->monstre->nom, donneesCombat->salleActuelle->monstre->pointsVie);
    afficherAttaque(donneesCombat->attaqueRoundMonstre, 0);
    printf(")\n");
    piocher5Cartes(donneesCombat);
}

void processusRound(p_donneesCombat donneesCombat, bool debug) {
    processusDebutRound(donneesCombat, debug);
    processusTourJoueur(donneesCombat, debug);
    if (donneesCombat->salleActuelle->monstre->pointsVie > 0) {
        processusTourMonstre(donneesCombat, debug);
    }
    if (debug == true) {
        donneesCombat->salleActuelle->monstre->pointsVie = 0;
        return;
    }
    decrementerEffets(donneesCombat->joueur->listeEffetsSubis);
    decrementerEffets(donneesCombat->salleActuelle->monstre->listeEffetsSubis);
}

void processusTourJoueur(p_donneesCombat donneesCombat, bool debug) {
    infligerEffetsJoueur(donneesCombat);
    int choixCarte = -1;
    do {
        do {
            choixCarte = menuChoixCarteMain(donneesCombat->mainJoueur);
        } while (choixCarte < 0 || donneesCombat->pioche->nombreCartes < choixCarte);
        if (choixCarte != 0) {
            transfererNiemeCarteListe(donneesCombat->mainJoueur, donneesCombat->cartesAJouer, choixCarte - 1);
        }
    } while (choixCarte != 0);
    printf("Fin de la selection de cartes, les cartes restantes partent à la défausse\n");

    while (donneesCombat->mainJoueur->nombreCartes != 0) {
        transfererNiemeCarteListe(donneesCombat->mainJoueur, donneesCombat->defausse, 0);
    }

    jouerListeCartes(donneesCombat);
}

void processusTourMonstre(p_donneesCombat donneesCombat, bool debug) {
    if (debug == true) {
        donneesCombat->salleActuelle->monstre->pointsVie = 0;
        return;
    }
    jouerListeEffetsAttaqueMonstre(donneesCombat);
    infligerEffetsMonstre(donneesCombat);
    donneesCombat->attaqueRoundMonstre = NULL;
}

void piocher5Cartes(p_donneesCombat donneesCombat) {
    while (donneesCombat->pioche->nombreCartes < 5 ) {
        if (donneesCombat->defausse->nombreCartes != 0) {
            transfererNiemeCarteListe(donneesCombat->defausse, donneesCombat->pioche, genererEntier(0, donneesCombat->defausse->nombreCartes));
        } else {
            break;
        }
    }
    for (int i = 0; i < 5; ++i) {
        if (donneesCombat->pioche->nombreCartes == 0) {
            break;
        }
        transfererNiemeCarteListe(donneesCombat->pioche, donneesCombat->mainJoueur, genererEntier(0, donneesCombat->pioche->nombreCartes));
    }
}

void jouerListeCartes(p_donneesCombat donneesCombat) {
    p_carteChainable carteAJouer = donneesCombat->cartesAJouer->premiereCarte;
    p_carteChainable prochaineCarteAJouer;
    afficherListeCartes(donneesCombat->cartesAJouer, 5);

    while (carteAJouer != NULL) {
        p_effetChainable effetAJouer = carteAJouer->carte->listeEffets->premiereEffet;
        p_listeEffets listeEffetsDestination;
        bool abyssal = false;
        while (effetAJouer != NULL) {
            if (strcmp(effetAJouer->effet->nom, "Abyssal") == 0) {
                abyssal = true;
            }
            if (true == effetAJouer->effet->surJoueur) {
                listeEffetsDestination = donneesCombat->joueur->listeEffetsSubis;
            } else {
                listeEffetsDestination = donneesCombat->salleActuelle->monstre->listeEffetsSubis;
            }
            ajouterEffetListe(listeEffetsDestination, copierEffet(effetAJouer->effet));
            effetAJouer = effetAJouer->effetSuivant;
        }
        prochaineCarteAJouer = carteAJouer->carteSuivante;
        if (abyssal == true) {
            transfererNiemeCarteListe(donneesCombat->cartesAJouer, donneesCombat->abysses, 0);
            enleverCarteListe(donneesCombat->joueur->deckPrincipal, carteAJouer->carte);
        } else {
            transfererNiemeCarteListe(donneesCombat->cartesAJouer, donneesCombat->defausse, 0);
        }
        carteAJouer = prochaineCarteAJouer;
    }
}

void jouerListeEffetsAttaqueMonstre(p_donneesCombat donneesCombat) {
    p_effetChainable effetAJouer = donneesCombat->attaqueRoundMonstre->listeEffets->premiereEffet;
    p_listeEffets listeEffetsDestination;
    while (effetAJouer != NULL) {
        if (true == effetAJouer->effet->surJoueur) {
            listeEffetsDestination = donneesCombat->joueur->listeEffetsSubis;
        } else {
            listeEffetsDestination = donneesCombat->salleActuelle->monstre->listeEffetsSubis;
        }
        ajouterEffetListe(listeEffetsDestination, copierEffet(effetAJouer->effet));
        effetAJouer = effetAJouer->effetSuivant;
    }
}

void infligerEffetsJoueur(p_donneesCombat donneesCombat) {
    p_effetChainable effetActuel = donneesCombat->joueur->listeEffetsSubis->premiereEffet;

    int degats = 0;
    int esquive = 0;

    float multDegats = 1;
    double multEsquive = 1;

    p_joueur joueur = donneesCombat->joueur;
    while (effetActuel != NULL) {
        if (effetActuel->effet->nombreToursRestants != 0) {
            if (strcmp(effetActuel->effet->nom, "Dégats") == 0) {
                afficherEffet(effetActuel->effet, 3);
                degats += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Esquive") == 0) {
                afficherEffet(effetActuel->effet, 3);
                esquive += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Feu") == 0) {
                afficherEffet(effetActuel->effet, 3);
                degats += effetActuel->effet->valeur;
                effetActuel->effet->valeur /= 2;
            } else if (strcmp(effetActuel->effet->nom, "Faible") == 0) {
                afficherEffet(effetActuel->effet, 3);
                degats-= effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Lenteur") == 0) {
                afficherEffet(effetActuel->effet, 3);
                multEsquive *= 0.5;
            } else if (strcmp(effetActuel->effet->nom, "Force") == 0) {
                afficherEffet(effetActuel->effet, 3);
                degats += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Dexterité") == 0) {
                afficherEffet(effetActuel->effet, 3);
                esquive += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Mana") == 0) {
                afficherEffet(effetActuel->effet, 3);
                joueur->pointsManaActuels += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Soin") == 0) {
                afficherEffet(effetActuel->effet, 3);
                joueur->pointsVieActuels += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "PV-max") == 0) {
                afficherEffet(effetActuel->effet, 3);
                joueur->pointsVieMax += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Energie-max") == 0) {
                afficherEffet(effetActuel->effet, 3);
                joueur->pointsEnergieMax += effetActuel->effet->valeur;
            }
        }

        effetActuel = effetActuel->effetSuivant;

    }

    joueur->pointsVieActuels -= degats*multDegats-esquive*multEsquive;
}

void infligerEffetsMonstre(p_donneesCombat donneesCombat) {
    p_effetChainable effetActuel = donneesCombat->salleActuelle->monstre->listeEffetsSubis->premiereEffet;

    int degats = 0;
    int esquive = 0;

    float multDegats = 1;
    double multEsquive = 1;

    p_monstre monstre = donneesCombat->salleActuelle->monstre;
    while (effetActuel != NULL) {
        if (effetActuel->effet->nombreToursRestants != 0) {
            if (strcmp(effetActuel->effet->nom, "Dégats") == 0) {
                afficherEffet(effetActuel->effet, 3);
                degats += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Esquive") == 0) {
                afficherEffet(effetActuel->effet, 3);
                esquive += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Feu") == 0) {
                afficherEffet(effetActuel->effet, 3);
                degats += effetActuel->effet->valeur;
                effetActuel->effet->valeur /= 2;
            } else if (strcmp(effetActuel->effet->nom, "Faible") == 0) {
                afficherEffet(effetActuel->effet, 3);
                degats-= effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Lenteur") == 0) {
                afficherEffet(effetActuel->effet, 3);
                multEsquive *= 0.5;
            } else if (strcmp(effetActuel->effet->nom, "Force") == 0) {
                afficherEffet(effetActuel->effet, 3);
                degats += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Dexterité") == 0) {
                afficherEffet(effetActuel->effet, 3);
                esquive += effetActuel->effet->valeur;
            } else if (strcmp(effetActuel->effet->nom, "Soin") == 0) {
                afficherEffet(effetActuel->effet, 3);
                monstre->pointsVie += effetActuel->effet->valeur;
            }
        }

        effetActuel = effetActuel->effetSuivant;

    }

    donneesCombat->salleActuelle->monstre->pointsVie -= degats*multDegats-esquive*multEsquive;
}

void decrementerEffets(p_listeEffets listeEffets) {
    p_effetChainable effetActuel = listeEffets->premiereEffet;

    while (effetActuel != NULL) {
        if (effetActuel->effet->nombreToursRestants > 0 && effetActuel->effet->permanent != true) {
            effetActuel->effet->nombreToursRestants++;
        }

        effetActuel = effetActuel->effetSuivant;
    }
}

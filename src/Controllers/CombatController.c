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

void processusCombat(p_donneesCombat donneesCombat) {
    processusDebutCombat(donneesCombat);
    while (donneesCombat->joueur->pointsVieActuels > 0 && donneesCombat->salleActuelle->monstre->pointsVie > 0) {
        processusRound(donneesCombat);
    }
}

void processusDebutCombat(p_donneesCombat donneesCombat) {
    donneesCombat->joueur->pointsManaActuels = donneesCombat->joueur->pointsManaMax;
    donneesCombat->defausse = creerListeCartes();
    donneesCombat->cartesAJouer = creerListeCartes();
    donneesCombat->mainJoueur = creerListeCartes();
    donneesCombat->pioche = copierListeCartes(donneesCombat->joueur->deckPrincipal);



    // TODO: appliquer bonus objets peter
    // TODO: préparation mana
}

void processusDebutRound(p_donneesCombat donneesCombat) {
    donneesCombat->attaqueRoundMonstre = trouverNiemeAttaque(donneesCombat->salleActuelle->monstre->attaques,
                                                             genererEntier(0, donneesCombat->salleActuelle->monstre->attaques->nombreAttaques));
    printf("Mouahaha je suis %s et je vais attaquer ! (", donneesCombat->salleActuelle->monstre->nom);
    afficherAttaque(donneesCombat->attaqueRoundMonstre, 0);
    printf(")\n");
    piocher5Cartes(donneesCombat);
}

void processusRound(p_donneesCombat donneesCombat) {
    processusDebutRound(donneesCombat);
    processusTourJoueur(donneesCombat);
    if (donneesCombat->salleActuelle->monstre->pointsVie > 0) {
        processusTourMonstre(donneesCombat);
    }
}

void processusTourJoueur(p_donneesCombat donneesCombat) {
    int choixCarte;
    do {
        do {
            choixCarte = menuChoixCarteMain(donneesCombat->mainJoueur);
        } while (choixCarte < 0 || donneesCombat->pioche->nombreCartes < choixCarte);
        transfererNiemeCarteListe(donneesCombat->mainJoueur, donneesCombat->cartesAJouer, choixCarte - 1);
    } while (choixCarte != 0);
    printf("Fin de la selection de cartes, les cartes restantes partent à la défausse\n");

    while (donneesCombat->pioche->nombreCartes != 0) {
        transfererNiemeCarteListe(donneesCombat->pioche, donneesCombat->defausse, 0);
    }

    jouerListeCartes(donneesCombat);



    // TODO: on joue les cartes (affichage des actions successives)
    // TODO: on met les cartes jouées à la défausse ou abysses
    // TODO: on met les cartes restantes à la défausse
}

void processusTourMonstre(p_donneesCombat donneesCombat) {
    while(donneesCombat->attaqueRoundMonstre->listeEffets->premiereEffet->effetSuivant != NULL) {
        ajouterEffetListe(donneesCombat->attaqueRoundMonstre->listeEffets, copierEffet(donneesCombat->attaqueRoundMonstre->listeEffets->premiereEffet->effet));
        donneesCombat->attaqueRoundMonstre->listeEffets->premiereEffet = donneesCombat->attaqueRoundMonstre->listeEffets->premiereEffet->effetSuivant;
    }
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
    p_carteChainable carteAJouer = donneesCombat->mainJoueur->premiereCarte;

    int nCarte = 0;
    while (carteAJouer != NULL) {
        p_effetChainable effetAJouer = carteAJouer->carte->listeEffets->premiereEffet;
        p_listeEffets listeEffetsDestination;
        bool abyssal = false;
        while (effetAJouer != NULL) {
            if (strcmp(effetAJouer->effet->nom, "Abyssal") == 0) {
                abyssal = true;
            }
            if (effetAJouer->effet->surJoueur) {
                listeEffetsDestination = donneesCombat->joueur->listeEffetsSubis;
            } else {
                listeEffetsDestination = donneesCombat->salleActuelle->monstre->listeEffetsSubis;
            }
            ajouterEffetListe(listeEffetsDestination, copierEffet(effetAJouer->effet));
            effetAJouer = effetAJouer->effetSuivant;
        }
        if (abyssal == true) {
            transfererNiemeCarteListe(donneesCombat->mainJoueur, donneesCombat->abysses, nCarte);
        } else {
            transfererNiemeCarteListe(donneesCombat->mainJoueur, donneesCombat->defausse, nCarte);
        }
        nCarte++;
        carteAJouer = carteAJouer->carteSuivante;
    }
}

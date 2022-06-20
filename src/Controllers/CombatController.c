//
// Created by Ulysse Dahiez on 11/06/2022.
//

#include "CombatController.h"
#include "stdio.h"
#include "../../Vue/Menu/Headers/Affichages.h"

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
    processusTourMonstre(donneesCombat);
    processusTourJoueur(donneesCombat);
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
    printf("Il est temps de choisir les cartes à jouer ! Voici celles que Peter a en main :\n");
    afficherListeCartes(donneesCombat->mainJoueur, 5);
    // TODO: le joueur choisit les cartes à jouer


    // TODO: on joue les cartes (affichage des actions successives)
    // TODO: on met les cartes jouées à la défausse ou abysses
    // TODO: on met les cartes restantes à la défausse
}

void processusTourMonstre(p_donneesCombat donneesCombat) {
    // TODO: jouer l'attaque choisie
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
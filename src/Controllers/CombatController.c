//
// Created by Ulysse Dahiez on 11/06/2022.
//

#include "CombatController.h"

void processusRounds(t_donneesCombat donneesCombat) {
    processusTourMonstre(donneesCombat);
    processusTourJoueur(donneesCombat);
    while (donneesCombat.joueur->pointsVieActuels > 0 && donneesCombat.salleActuelle->monstre->pointsVie > 0) {
        processusRound(donneesCombat);
    }
}

void processusDebutCombat(t_donneesCombat donneesCombat) {
    donneesCombat.pioche = copierListeCartes(donneesCombat.joueur->deckPrincipal);



    // TODO: appliquer bonus objets peter
    // TODO: préparation mana
}

void processusDebutRound(t_donneesCombat donneesCombat) {
    // TODO: selectionner une attaque pour le monstre et la sauvegarder
    // TODO: piocher 5 cartes (si possible) pour Peter
    //piocher5Cartes()
}

void processusRound(t_donneesCombat donneesCombat) {
    processusDebutRound(donneesCombat);
    processusTourJoueur(donneesCombat);
    if (donneesCombat.salleActuelle->monstre->pointsVie > 0) {
        processusTourMonstre(donneesCombat);
    }
}

void processusTourJoueur(t_donneesCombat donneesCombat) {
    // TODO: le joueur choisit les cartes à jouer
    // TODO: on joue les cartes (affichage des actions successives)
    // TODO: on met les cartes jouées à la défausse ou abysses
    // TODO: on met les cartes restantes à la défausse
}

void processusTourMonstre(t_donneesCombat donneesCombat) {
    // TODO: jouer l'attaque choisie
}

void piocher5Cartes(t_donneesCombat donneesCombat) {
    for (int i = 0; i < 5; ++i) {
        if (donneesCombat.pioche->nombreCartes < 5 ) {

        }
        ajouterCarteListe(donneesCombat.mainJoueur, trouverPointeurNiemeCarte(donneesCombat.pioche, genererEntier(0, donneesCombat.pioche->nombreCartes)));
    }
}
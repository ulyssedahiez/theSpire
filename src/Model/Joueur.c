//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Joueur.h"
#include <stdbool.h>

p_joueur creerJoueur() {
    p_joueur joueur = malloc(sizeof(t_joueur));
    joueur->pointsVieActuels = 75; // v
    joueur->pointsVieMax = 75;
    joueur->pointsEsquiveActuels = 0; //q
    joueur->pointsEnergieActuels = 0; //s_donneesCombat
    joueur->pointsEnergieMax = 3;
    joueur->pointsManaActuels = 100; //m
    joueur->pointsManaMax = 100;
    joueur->listeObjets = creerListeObjets();
    joueur->deckPrincipal = creerListeCartes();
    joueur->listeEffets = creerListeEffets();

    return joueur;
}



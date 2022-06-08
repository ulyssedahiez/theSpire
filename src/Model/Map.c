//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Map.h"
p_joueur creerMap() {
    p_map map = malloc(sizeof(t_joueur));
    joueur->pointsVieActuels = 75;
    joueur->pointsVieMax = 75;
    joueur->pointsEsquiveActuels = 0;
    joueur->pointsEnergieActuels = 0;
    joueur->pointsEnergieMax = 3;
    joueur->pointsManaActuels = 100;
    joueur->pointsManaMax = 100;
    joueur->listeObjets = NULL;
    joueur->deck = NULL;
    joueur->lenteur = false;
    joueur->faiblesse = false;
    joueur->toursRestantsLenteur = 0;
    joueur->toursRestantsFaiblesse = 0;

    return joueur;
}
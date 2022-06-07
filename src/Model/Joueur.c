//
// Created by charles on 30/05/22.
//

#include "Headers/Joueur.h"
#include <stdbool.h>

p_joueur creerJoueur() {
    p_joueur joueur = malloc(sizeof(s_joueur));
    joueur->poipointsVieActuels = 75;
    joueur->pointsVieMax = 75;
    joueur->pointsEsquiveActuels = 0;
    joueur->pointsEnergieActuels = 0;
    joueur->pointsEnergieMax = 3;
    joueur->pointsManaActuels = 100;
    joueur->pointsManaMax = 100;
    joueur->listeObjets = null;
    joueur->deck = null;
    joueur->lenteur = FALSE;
    joueur->faiblesse = FALSE;
    joueur->toursRestantsLenteur = 0;
    joueur->toursRestantsFaiblesse = 0;

    return joueur;
}
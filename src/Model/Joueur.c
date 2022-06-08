//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Joueur.h"
#include <stdbool.h>

p_joueur creerJoueur() {
    p_joueur joueur = malloc(sizeof(t_joueur));
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

void modifierPointsVieActuels(p_joueur joueur, int points){
    joueur->pointsVieActuels += points;
}

void modifierPointsEsquiveActuels(p_joueur joueur, int points)
{

}

void modifierPointsManaActuels(p_joueur joueur, int points){
    
}
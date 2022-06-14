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
    joueur->pointsEnergieActuels = 0; //e
    joueur->pointsEnergieMax = 3;
    joueur->pointsManaActuels = 100; //m
    joueur->pointsManaMax = 100;
    joueur->listeObjets = NULL;
    joueur->deck = NULL;
    joueur->lenteur = false;//l
    joueur->faiblesse = false;//f
    joueur->toursRestantsLenteur = 0;//t
    joueur->toursRestantsFaiblesse = 0;//m

    return joueur;
}



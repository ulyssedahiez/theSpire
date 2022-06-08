//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_JOUEUR_H
#define THESPIRE_JOUEUR_H
#include <stdbool.h>
#include "Objet.h"
#include "Deck.h"
#include "stdlib.h"

typedef struct s_joueur {
    int pointsVieActuels;
    int pointsVieMax;
    int pointsEsquiveActuels;
    int pointsEnergieActuels;
    int pointsEnergieMax;
    int pointsManaActuels;
    int pointsManaMax;
    struct s_listeObjets * listeObjets;
    struct deck * deck;
    bool lenteur;
    bool faiblesse;
    int toursRestantsLenteur;
    int toursRestantsFaiblesse;
} t_joueur;

typedef t_joueur * p_joueur;

p_joueur creerJoueur();

void modifierPointsVieActuels(p_joueur joueur, int points);

void modifierPointsEsquiveActuels(p_joueur joueur, int points);

void modifierPointsManaActuels(p_joueur joueur, int points);

#endif //THESPIRE_JOUEUR_H

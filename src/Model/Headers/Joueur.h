//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_JOUEUR_H
#define THESPIRE_JOUEUR_H
#include <stdbool.h>
#include "Objet.h"
#include "Deck.h"

struct s_joueur {
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
};

typedef s_joueur t_joueur;
typedef t_joueur* p_joueur;

p_joueur creerJoueur();

bool setPointsVieActuels(p_joueur joueur, )

#endif //THESPIRE_JOUEUR_H

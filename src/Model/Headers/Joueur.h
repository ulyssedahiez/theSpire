//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_JOUEUR_H
#define THESPIRE_JOUEUR_H
#include <stdbool.h>
#include "Objet.h"
#include "Deck.h"
#include "stdlib.h"
#include "Carte.h"

typedef struct s_joueur {
    int pointsVieActuels;
    int pointsVieMax;
    int pointsEsquiveActuels;
    int pointsEnergieActuels;
    int pointsEnergieMax;
    int pointsManaActuels;
    int pointsManaMax;
    struct s_listeObjets * listeObjets;
    p_listeCartes deckPrincipal;
    struct s_listeEffets * listeEffetsSubis;
} t_joueur;

typedef t_joueur* p_joueur;

p_joueur creerJoueur();

#endif //THESPIRE_JOUEUR_H

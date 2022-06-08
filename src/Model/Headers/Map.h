//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_MAP_H
#define THESPIRE_MAP_H

#include <stdbool.h>
#include "stdlib.h"

#endif //THESPIRE_MAP_H
#ifndef THESPIRE_JOUEUR_H
#define THESPIRE_JOUEUR_H
#include "Objet.h"
#include "Deck.h"
#include "stdlib.h"
#include "Salle.h"

typedef struct s_map {
    int nombreSalle;
    struct s_map* premiereSalle;
    struct s_map* salleSuivante;
    struct s_listeObjets * listeObjets;
    bool lenteur;
    bool faiblesse;
    int toursRestantsLenteur;
    int toursRestantsFaiblesse;
} t_map;

typedef t_map* p_map;

p_map creerMap();

bool ajouterPointsVieActuels(p_joueur joueur);
bool ajouterPointsEsquiveActuels(p_joueur joueur);
bool ajouterPointsManaActuels(p_joueur joueur);

#endif //THESPIRE_JOUEUR_H

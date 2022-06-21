//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_MAP_H
#define THESPIRE_MAP_H
#include <stdbool.h>
#include "stdlib.h"
#include "Objet.h"
#include "Deck.h"
#include "stdlib.h"
#include "Salle.h"

typedef struct s_map {
    struct s_salleDebut* premiereSalle;
    struct s_salle* derniereSalle;
} t_map;

typedef t_map* p_map;

p_map creerMap();

p_coordonnees trouverCoordoneesSalle(p_map map, p_salle salle);

#endif //THESPIRE_MAP_H

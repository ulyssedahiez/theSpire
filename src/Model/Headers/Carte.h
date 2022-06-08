//
// Created by charles on 11/05/22.
//

#ifndef THESPIRE_CARTE_H
#define THESPIRE_CARTE_H

#include "Effet.h"
#include "stdlib.h"

typedef struct s_carte {
    char *nom;
    char *rarete;
    int pointsEnergie;
    int pointsMana;
    struct s_listeEffets *listeEffets;
    char *texteTechnique;
    char *texteDescription;
} t_carte;

typedef t_carte *p_carte;

typedef struct s_carteChainable {
    struct s_carte *carte;
    struct s_carte *carteSuivante;
} t_carteChainable;

typedef t_carteChainable *p_carteChainable;

typedef struct s_listeCartes {
    struct s_carteChainable *premiereCarte;
    int nombreCartes;
} t_listeCartes;

typedef t_listeCartes *p_listeCartes;

#endif //THESPIRE_CARTE_H

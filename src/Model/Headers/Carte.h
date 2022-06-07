//
// Created by charles on 11/05/22.
//

#ifndef THESPIRE_CARTE_H
#define THESPIRE_CARTE_H

#include "Effet.h"

struct s_carte {
    char *nom;
    char *rarete;
    int pointsEnergie;
    int pointsMana;
    struct s_listeEffets *listeEffets;
    char *texteTechnique;
    char *texteDescription;
};

typedef s_carte t_carte;
typedef t_carte *p_carte;

struct s_carteChainable {
    struct s_carte *carte;
    struct s_carte *carteSuivante;
};

typedef s_carteChainable t_carteChainable;
typedef t_carteChainable *p_carteChainable;

struct s_listeCartes {
    struct s_carteChainable *premiereCarte;
    int nombreCartes;
};

typedef s_listeCartes t_listeCartes;
typedef t_listeCartes *p_listeCartes;

#endif //THESPIRE_CARTE_H

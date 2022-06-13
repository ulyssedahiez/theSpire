//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_ATTAQUE_H
#define THESPIRE_ATTAQUE_H

#include "stdlib.h"
#include "stdbool.h"
typedef struct s_attaque {
    bool surJoueur;
    int probabiliteAttaque;
    int pointsDegats;
    int pointsEsquive;
    int pointsForce;
    int pointsFeu;
    int pointsDexterite;
    int nombreToursLenteur;
    int nombreToursFaiblesse;
} t_attaque;

typedef t_attaque* p_attaque;

typedef struct s_attaqueChainable {
    struct s_attaque * attaque;
    struct s_attaque * attaqueSuivante;
} t_attaqueChainable;

typedef t_attaqueChainable* p_attaqueChainable;

typedef struct s_listeAttaques {
    struct s_attaqueChainable * premiereCarte;
    int nombreAttaques;
} t_listeAttaques;

typedef t_listeAttaques* p_listeAttaques;

#endif //THESPIRE_ATTAQUE_H

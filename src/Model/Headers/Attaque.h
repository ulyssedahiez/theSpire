//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_ATTAQUE_H
#define THESPIRE_ATTAQUE_H

#include "Effet.h"
#include "stdlib.h"
#include "stdbool.h"
#include "../../Services/Headers/UtilsService.h"

typedef struct s_attaque {
    int probabiliteSur100;
    p_listeEffets listeEffets;
} t_attaque;

typedef t_attaque* p_attaque;

typedef struct s_attaqueChainable {
    struct s_attaque * attaque;
    struct s_attaqueChainable * attaqueSuivante;
} t_attaqueChainable;

typedef t_attaqueChainable* p_attaqueChainable;

typedef struct s_listeAttaques {
    struct s_attaqueChainable * premiereAttaque;
    int nombreAttaques;
} t_listeAttaques;

typedef t_listeAttaques* p_listeAttaques;

p_attaque creerAttaque(p_listeEffets listeEffets, int probabiliteSur100);

p_listeAttaques creerListeAttaques();

void ajouterAttaqueListe(p_listeAttaques listeAttaques, p_attaque attaque);

p_attaqueChainable creerAttaqueChainable(p_attaque attaque);


#endif //THESPIRE_ATTAQUE_H

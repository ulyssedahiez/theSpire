//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_MONSTRE_H
#define THESPIRE_MONSTRE_H

#include "Attaque.h"
#include "stdlib.h"

typedef struct s_monstre
{
    char* nom;
    int pointsVie;
    struct s_listeAttaques * attaques;
    int borneInfPointsVie;
    int borneSupPointsVie;
    char*  type;
} t_monstre;

typedef t_monstre* p_monstre;

typedef struct s_monstreChainable {
    struct s_monstre *monstre;
    struct s_monstreChainable *monstreSuivante;
} t_monstreChainable;

typedef t_monstreChainable *p_monstreChainable;

typedef struct s_listeMonstres {
    struct s_monstreChainable *premiereMonstre;
    int nombreMonstres;
} t_listeMonstres;

typedef t_listeMonstres *p_listeMonstres;

p_monstre creerMonstre(char *nom, int pointsVie, p_listeAttaques attaques, int borneInfPV, int borneSupPV, char *type);

p_listeMonstres creerListeMonstres();

void ajouterMonstreListe(p_listeMonstres listeMonstres, p_monstre monstre);

p_monstreChainable creerMonstreChainable(p_monstre monstre);

p_monstre trouverPointeurNiemeMonstre(p_listeMonstres listeMonstre, int n);

p_monstre copierMonstre(p_monstre monstre);

#endif //THESPIRE_MONSTRE_H

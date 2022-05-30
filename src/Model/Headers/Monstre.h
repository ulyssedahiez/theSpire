//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_MONSTRE_H
#define THESPIRE_MONSTRE_H

#include "Attaque.h"

typedef struct s_monstre
{
    char* nom;
    int habitatMin;
    int habitatMax;
    int pointsVie;
    int pointsDegats;
    p_listeAttaques attaques;
} t_monstre;

typedef t_monstre * p_monstre;

#endif //THESPIRE_MONSTRE_H

//
// Created by charles on 16/06/22.
//

#ifndef THESPIRE_UTILSSERVICE_H
#define THESPIRE_UTILSSERVICE_H

#include <stdbool.h>
#include "stdlib.h"

typedef struct s_coordonneesTour {
    int niveau;
    int couloir;
    struct s_coordonneesTour* suivant;
}t_coordonneesTour;

typedef t_coordonneesTour * p_coordonneesTour;

p_coordonneesTour creerCoordonneesTour(int niveau, int couloir);

bool estDansListe(p_coordonneesTour coordonneesTour, int niveau, int couloir);

void ajouterCoordonnee(p_coordonneesTour coordonneesTour, p_coordonneesTour nouveau);

int genererEntier(int borneInfInclue, int borneSupExclue);

#endif //THESPIRE_UTILSSERVICE_H

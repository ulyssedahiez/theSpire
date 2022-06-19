//
// Created by charles on 16/06/22.
//

#ifndef THESPIRE_UTILSSERVICE_H
#define THESPIRE_UTILSSERVICE_H

#include <stdbool.h>
#include "stdlib.h"

typedef struct s_coordonnees {
    int niveau;
    int couloir;
    struct s_coordonnees* suivant;
}t_coordonnees;

typedef t_coordonnees * p_coordonnees;

typedef struct s_listeCoordonnees {
    struct s_coordonnees * premierCoordonnees;
    int nombreCoordonnees;
} t_listeCoordonnees;

typedef t_listeCoordonnees * p_listeCoordonnees;

p_listeCoordonnees creerListeCoordonnees();

p_coordonnees creerCoordonnees(int niveau, int couloir);

bool estDansListe(p_listeCoordonnees listeCoordonnees, int niveau, int couloir);

void ajouterCoordonnee(p_listeCoordonnees listeCoordonnees, p_coordonnees nouveau);

int genererEntier(int borneInfInclue, int borneSupExclue);

#endif //THESPIRE_UTILSSERVICE_H

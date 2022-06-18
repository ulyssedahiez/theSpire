//
// Created by charles on 16/06/22.
//

#include "Headers/UtilsService.h"
#include "stdio.h"

p_listeCoordonnees creerListeCoordonnees() {
    p_listeCoordonnees listeCoordonnees = malloc(sizeof(t_listeCoordonnees));

    listeCoordonnees->premierCoordonnees = NULL;
    listeCoordonnees->nombreCoordonnees = 0;

    return listeCoordonnees;
}

p_coordonnees creerCoordonnees(int niveau, int couloir) {
    p_coordonnees coordonneesTour = malloc(sizeof(t_coordonnees));

    coordonneesTour->niveau = niveau;
    coordonneesTour->couloir = couloir;

    coordonneesTour->suivant = NULL;

    return coordonneesTour;
}

bool estDansListe(p_listeCoordonnees listeCoordonnees, int niveau, int couloir) {
    p_coordonnees coordonnees = listeCoordonnees->premierCoordonnees;
    while (coordonnees != NULL) {
        if (coordonnees->niveau == niveau && coordonnees->couloir == couloir) {
            return true;
        }
        coordonnees = coordonnees->suivant;
    }
    return false;
}

void ajouterCoordonnee(p_listeCoordonnees listeCoordonnees, p_coordonnees nouveau) {
    if (listeCoordonnees->nombreCoordonnees == 0) {
        listeCoordonnees->premierCoordonnees = nouveau;
    } else {
        p_coordonnees coordonnees = listeCoordonnees->premierCoordonnees;
        while (coordonnees->suivant != NULL) {
            coordonnees = coordonnees->suivant;
        }
        coordonnees->suivant = nouveau;
    }
    listeCoordonnees->nombreCoordonnees += 1;
}

int genererEntier(int borneInfInclue, int borneSupExclue) {
    int result;
    if (borneInfInclue == borneSupExclue) {
        result = borneInfInclue;
    } else {
        result = (borneInfInclue + (rand()) % (int)(borneSupExclue - borneInfInclue));
    }
    return result;
}
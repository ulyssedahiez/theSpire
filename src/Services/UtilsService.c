//
// Created by charles on 16/06/22.
//

#include "Headers/UtilsService.h"

p_coordonneesTour creerCoordonneesTour(int niveau, int couloir) {
    p_coordonneesTour coordonneesTour = malloc(sizeof(t_coordonneesTour));

    coordonneesTour->niveau = niveau;
    coordonneesTour->couloir = couloir;

    coordonneesTour->suivant = NULL;

    return coordonneesTour;
}

bool estDansListe(p_coordonneesTour coordonneesTour, int niveau, int couloir) {
    while (coordonneesTour != NULL) {
        if (coordonneesTour->niveau != niveau && coordonneesTour->couloir != couloir) {
            return true;
        }
        coordonneesTour = coordonneesTour->suivant;
    }
    return false;
}

void ajouterCoordonnee(p_coordonneesTour coordonneesTour, p_coordonneesTour nouveau) {
    while (coordonneesTour->suivant != NULL) {
        coordonneesTour = coordonneesTour->suivant;
    }
    coordonneesTour->suivant = nouveau;
}

int genererEntier(int borneInfInclue, int borneSupExclue) {
    return (borneInfInclue + (rand()) % (int)(borneSupExclue - borneInfInclue));
}
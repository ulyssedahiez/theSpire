//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Monstre.h"

p_monstre creerMonstre(char *nomMonstre,
                       p_listeAttaques attaquesMonstres,
                       int habitatMaxMonstre,
                       int habitatMinMonstre,
                       int pointsDegatsMonstre,
                       int pointsVieMonstre) {
    p_monstre monstre = malloc(sizeof(t_monstre));
    monstre->nom = nomMonstre;
    monstre->attaques = attaquesMonstres;
    monstre->habitatMax = habitatMaxMonstre;
    monstre->habitatMin = habitatMinMonstre;
    monstre->pointsDegats = pointsDegatsMonstre;
    monstre->pointsVie = pointsVieMonstre;

    return monstre;
}

//
// Created by charles on 30/05/22.
//

#include "Headers/Monstre.h"

p_monstre creerMonstre(char *nomMonstre, s_attaque attaquesMonstres) {
    p_monstre monstre = malloc(sizeof(s_monstre));
    monstre->nom = nomMonstre;
    monstre->attaques = attaquesMonstre;
    return monstre;
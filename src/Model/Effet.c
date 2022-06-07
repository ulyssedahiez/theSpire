//
// Created by charles on 11/05/22.
//

#include "Headers/Effet.h"

p_effet creerEffet(char* nomEffet, int valueEffet) {
    p_effet effet = malloc(sizeof(s_effet));
    effet->nom = nomEffet;
    effet->value = valueEffet;
    return effet;
}
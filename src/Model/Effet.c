//
// Created by charles on 11/05/22.
//
#include <stdlib.h>
#include "Headers/Effet.h"

p_effet creerEffet(char* nomEffet, int valueEffet) {
    p_effet effet = malloc(sizeof(t_effet));
    effet->nom = nomEffet;
    effet->value = valueEffet;
    return effet;
}
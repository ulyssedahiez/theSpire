//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Combat.h"

p_combat creerCombat(p_monstre monstreCombat) {
    p_combat combat = malloc(sizeof(t_combat));
    combat->monstre = monstreCombat;

    return combat;
}
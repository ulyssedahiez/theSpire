//
// Created by charles on 30/05/22.
//

#include "Headers/Combat.h"

p_carte creerCarte(s_monstre monstreCombat) {
    p_combat combat = malloc(sizeof(s_combat));
    combat->monstre = monstreCombat;

    return combat;
}
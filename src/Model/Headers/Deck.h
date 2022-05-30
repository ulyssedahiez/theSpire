//
// Created by charles on 11/05/22.
//

#ifndef THESPIRE_DECK_H
#define THESPIRE_DECK_H

#include "Carte.h"

struct deck {
    struct s_listeCartes * listeCartes;
};

typedef s_deck t_deck;
typedef t_deck* p_deck;

#endif //THESPIRE_DECK_H

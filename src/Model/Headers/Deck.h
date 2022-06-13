//
// Created by charles on 11/05/22.
//

#ifndef THESPIRE_DECK_H
#define THESPIRE_DECK_H

#include "Carte.h"
#include "stdlib.h"

typedef struct s_deck {
    struct s_listeCartes *listeCartes;
} t_deck;

typedef t_deck * p_deck;

p_deck creerDeck(p_listeCartes listeCarteDeck);

#endif //THESPIRE_DECK_H

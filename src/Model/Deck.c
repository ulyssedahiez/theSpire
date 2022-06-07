//
// Created by charles on 11/05/22.
//

#include "Headers/Deck.h"

p_deck creerDeck(s_listeCartes listeCarteDeck) {
    p_deck deck = malloc(sizeof(s_deck));
    deck->listeCartes = listeCarteDeck;

    return deck;
}
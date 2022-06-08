//
// Created by charles on 11/05/22.
//

#include "Headers/Deck.h"

p_deck creerDeck(p_listeCartes listeCarteDeck) {
    p_deck deck = malloc(sizeof(t_deck));
    deck->listeCartes = listeCarteDeck;

    return deck;
}
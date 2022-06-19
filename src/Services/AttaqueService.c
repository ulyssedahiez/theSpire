//
// Created by charles on 19/06/22.
//

#include "Headers/AttaqueService.h"

p_attaque choisirAttaqueHasardProba(p_listeAttaques listeAttaques) {
    p_attaqueChainable attaqueChainableActuelle = listeAttaques->premiereAttaque;
    int entierRandom = genererEntier(0, 100);
    p_attaque attaque;

    while (attaqueChainableActuelle != NULL) {
        attaque = attaqueChainableActuelle->attaque;
        if (entierRandom < sommeProbaAttaques(listeAttaques, attaque)) {
            return attaque;
        }

        attaqueChainableActuelle = attaqueChainableActuelle->attaqueSuivante;
    }

    return NULL;
}

int sommeProbaAttaques(p_listeAttaques listeAttaques, p_attaque attaque) {
    int sommeProbas = 0;
    p_attaqueChainable attaqueChainableActuelle = listeAttaques->premiereAttaque;

    while (attaqueChainableActuelle->attaque != attaque) {
        sommeProbas += attaqueChainableActuelle->attaque->probabiliteSur100;

        attaqueChainableActuelle = attaqueChainableActuelle->attaqueSuivante;
    }

    sommeProbas += attaqueChainableActuelle->attaque->probabiliteSur100;


    return sommeProbas;
}
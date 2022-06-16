//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Attaque.h"
#include <stdbool.h>

p_attaque creerAttaque(p_listeEffets listeEffets, int probabiliteSur100) {
    p_attaque attaque = malloc(sizeof(t_attaque));
    attaque->listeEffets = listeEffets;
    attaque->probabiliteSur100 = probabiliteSur100;

    return attaque;
}

p_listeAttaques creerListeAttaques() {
    p_listeAttaques listeAttaques = malloc(sizeof(t_listeAttaques));

    listeAttaques->premiereAttaque = NULL;
    listeAttaques->nombreAttaques = 0;

    return listeAttaques;
}

p_attaqueChainable creerAttaqueChainable(p_attaque attaque) {
    p_attaqueChainable attaqueChainable = malloc(sizeof(t_attaqueChainable));

    attaqueChainable->attaque = attaque;
    attaqueChainable->attaqueSuivante = NULL;

    return attaqueChainable;
}

void ajouterAttaqueListe(p_listeAttaques listeAttaques, p_attaque attaque) {
    p_attaqueChainable nouvelleAttaque = creerAttaqueChainable(attaque);
    if (0 == listeAttaques->nombreAttaques) {
        listeAttaques->premiereAttaque = nouvelleAttaque;
    } else {
        p_attaqueChainable derniereAttaque = listeAttaques->premiereAttaque;
        while (derniereAttaque->attaqueSuivante != NULL) {
            derniereAttaque = derniereAttaque->attaqueSuivante;
        }
        derniereAttaque->attaqueSuivante = nouvelleAttaque;
    }

    listeAttaques->nombreAttaques += 1;
}
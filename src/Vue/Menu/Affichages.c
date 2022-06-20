//
// Created by charles on 18/06/22.
//

#include "Headers/Affichages.h"
#include "stdio.h"
void afficherMap(p_map map, p_salle salleJoueur) {
    // TODO: à faire
}

void afficherAttaque(p_attaque attaque, int offset) {
    afficherListeEffets(attaque->listeEffets, offset);
}

void afficherCarte(p_carte carte, int offset) {
    afficherNChar(' ', offset);
    printf("Carte %s\n", carte->nom);
    afficherNChar(' ', 5);
    afficherListeEffets(carte->listeEffets, 10);
    printf("\n");

}

void afficherListeCartes(p_listeCartes listeCartes, int offset) {
    p_carteChainable carteChainable = listeCartes->premiereCarte;
    while (carteChainable != NULL) {
        afficherCarte(carteChainable->carte, offset);
        carteChainable = carteChainable->carteSuivante;
    }
}

void afficherNChar(char character, int nFois) {
    for (int i = 0; i < nFois; ++i) {
        printf("%c", character);
    }
}

void afficherListeEffets(p_listeEffets listeEffets, int offset) {
    p_effetChainable effetChainable = listeEffets->premiereEffet;
    afficherNChar(' ', offset);
    while (effetChainable != NULL) {
        afficherEffet(effetChainable->effet, 0);
        if (effetChainable->effetSuivant != NULL) {
            printf(", ");
        }
        effetChainable = effetChainable->effetSuivant;
    }
}

void afficherEffet(p_effet effet, int offset) {
    afficherNChar(' ', offset);
    printf("%s (%d)", effet->nom, effet->valeur);
}
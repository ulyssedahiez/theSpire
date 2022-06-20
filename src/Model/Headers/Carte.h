//
// Created by charles on 11/05/22.
//

#ifndef THESPIRE_CARTE_H
#define THESPIRE_CARTE_H

#include <stdbool.h>
#include "Effet.h"
#include "stdlib.h"

typedef struct s_carte {
    char *nom;
    char *rarete;
    int pointsEnergie;
    int pointsMana;
    struct s_listeEffets *listeEffets;
    char *texteTechnique;
    char *texteDescription;
} t_carte;

typedef t_carte *p_carte;

typedef struct s_carteChainable {
    struct s_carte *carte;
    struct s_carteChainable *carteSuivante;
} t_carteChainable;

typedef t_carteChainable *p_carteChainable;

typedef struct s_listeCartes {
    struct s_carteChainable *premiereCarte;
    int nombreCartes;
} t_listeCartes;

typedef t_listeCartes *p_listeCartes;

p_carte creerCarte(char *nomCarte, char *rareteCarte, int coutEnergie, int coutMana, p_listeEffets listeEffets, char *texteTechniqueCarte, char *texteDescriptionCarte);

p_listeCartes creerListeCartes();

void ajouterCarteListe(p_listeCartes listeCartes, p_carte carte);

/** retourne true si supprimée, false si non présente dans la liste */
bool enleverCarteListe(p_listeCartes listeCartes, p_carte carte);

void supprimerCarteChainable(p_carteChainable carteChainable);

p_carteChainable creerCarteChainable(p_carte carte);

p_carte trouverPointeurCarte(p_listeCartes listeCartes, char* nom);

p_listeCartes copierListeCartes(p_listeCartes listeCartes);

p_carte trouverPointeurNiemeCarte(p_listeCartes listeCartes, int nCherche);

void transfererNiemeCarteListe(p_listeCartes source, p_listeCartes cible, int n);

#endif //THESPIRE_CARTE_H

//
// Created by Ulysse Dahiez on 11/06/2022.
//

#ifndef THESPIRE_COMBATCONTROLLER_H
#define THESPIRE_COMBATCONTROLLER_H
#include "../../Model/Headers/Map.h"
#include "../../Model/Headers/Carte.h"
#include "../../Model/Headers/Joueur.h"

/**
 * Structure qui contient toutes les données nécessaires au déroulement des combats
 */
typedef struct s_donneesCombat {
    p_map map;
    p_joueur joueur;
    p_salle salleActuelle;
    p_listeCartes pioche;
    p_listeCartes mainJoueur;
    p_listeCartes abysses;
    p_listeCartes defausse;
    p_attaque attaqueRoundMonstre;
    p_listeCartes cartesAJouer;
} t_donneesCombat;

typedef t_donneesCombat * p_donneesCombat;

p_donneesCombat creerDonneesCombat();

void processusCombat(p_donneesCombat donneesCombat, bool debug);

void processusDebutCombat(p_donneesCombat donneesCombat, bool debug);

void processusRound(p_donneesCombat donneesCombat, bool debug);

void processusTourJoueur(p_donneesCombat donneesCombat, bool debug);

void processusTourMonstre(p_donneesCombat donneesCombat, bool debug);

void processusDebutRound(p_donneesCombat donneesCombat, bool debug);

void piocher5Cartes(p_donneesCombat donneesCombat);

void jouerListeCartes(p_donneesCombat donneesCombat);

void jouerListeEffetsAttaqueMonstre(p_donneesCombat donneesCombat);

void infligerEffetsJoueur(p_donneesCombat donneesCombat);

void infligerEffetsMonstre(p_donneesCombat donneesCombat);

void decrementerEffets(p_listeEffets listeEffets);

#endif //THESPIRE_COMBATCONTROLLER_H

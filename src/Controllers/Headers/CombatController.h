//
// Created by Ulysse Dahiez on 11/06/2022.
//

#ifndef THESPIRE_COMBATCONTROLLER_H
#define THESPIRE_COMBATCONTROLLER_H
#include "../../Model/Headers/Map.h"
#include "../../Model/Headers/Carte.h"
#include "../../Model/Headers/Joueur.h"


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

void processusCombat(p_donneesCombat donneesCombat);

void processusDebutCombat(p_donneesCombat donneesCombat);

void processusRound(p_donneesCombat donneesCombat);

void processusTourJoueur(p_donneesCombat donneesCombat);

void processusTourMonstre(p_donneesCombat donneesCombat);

void processusDebutRound(p_donneesCombat donneesCombat);

void piocher5Cartes(p_donneesCombat donneesCombat);

#endif //THESPIRE_COMBATCONTROLLER_H

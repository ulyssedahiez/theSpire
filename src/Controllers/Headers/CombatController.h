//
// Created by Ulysse Dahiez on 11/06/2022.
//

#ifndef THESPIRE_COMBATCONTROLLER_H
#define THESPIRE_COMBATCONTROLLER_H
#include "../../Model/Headers/Map.h"
#include "../../Model/Headers/Carte.h"
#include "../../Model/Headers/Joueur.h"

typedef struct e {
    p_map map;
    p_joueur joueur;
    p_listeCartes deckPrincipal;
    p_listeCartes pioche;
    p_listeCartes mainJoueur;
    p_listeCartes abysses;
    p_listeCartes defausse;
    p_salle salleActuelle;
} t_donneesCombat;

void processusRound(t_donneesCombat donneesCombat);

void processusTourJoueur(t_donneesCombat donneesCombat);

void processusTourMonstre(t_donneesCombat donneesCombat);

#endif //THESPIRE_COMBATCONTROLLER_H

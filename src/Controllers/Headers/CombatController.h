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

void processusRounds(t_donneesCombat donneesCombat);

void processusDebutCombat(t_donneesCombat donneesCombat);

void processusRound(t_donneesCombat donneesCombat);

void processusTourJoueur(t_donneesCombat donneesCombat);

void processusTourMonstre(t_donneesCombat donneesCombat);

void processusDebutRound(t_donneesCombat donneesCombat);

void piocher5Cartes(t_donneesCombat donneesCombat);

#endif //THESPIRE_COMBATCONTROLLER_H

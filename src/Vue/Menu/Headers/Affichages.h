//
// Created by charles on 18/06/22.
//

#ifndef THESPIRE_AFFICHAGES_H
#define THESPIRE_AFFICHAGES_H
#include "../../Model/Headers/Map.h"
#include "../../Model/Headers/Salle.h"

void afficherMap(p_map map, p_salle salleJoueur);

void afficherAttaque(p_attaque attaque, int offset);

void afficherCarte(p_carte carte, int offset);

void afficherListeCartes(p_listeCartes listeCartes, int offset);

void afficherNChar(char character, int nFois);

void afficherListeEffets(p_listeEffets listeEffets, int offset);

void afficherEffet(p_effet effet, int offset);

#endif //THESPIRE_AFFICHAGES_H

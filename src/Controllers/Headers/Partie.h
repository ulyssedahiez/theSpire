//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_PARTIE_H
#define THESPIRE_PARTIE_H
#include "stdlib.h"
#include "Map.h"
#include "Joueur.h"
#include "../../Services/Headers/JoueurService.h"
#include "../../Vue/Menu/Headers/Menu.h"

void processusPartie();

void remplirMap(p_map map);

bool verifierDefaite(p_joueur joueur);

bool verifierVictoire(p_map map);

p_salle choisirPremiereSalle(p_salleDebut salleActuelle);

p_salle choisirSalleSuivante(p_map map, p_salle salleActuelle);

#endif //THESPIRE_PARTIE_H

//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_PARTIECONTROLLER_H
#define THESPIRE_PARTIECONTROLLER_H
#include "stdlib.h"
#include "stdio.h"
#include "Map.h"
#include "Joueur.h"
#include "CombatController.h"
#include "../../Services/Headers/JoueurService.h"
#include "../../Services/Headers/CarteService.h"
#include "../../Services/Headers/MonstreService.h"
#include "../../Services/Headers/MapService.h"
#include "../../Services/Headers/ObjetService.h"
#include "../../Vue/Menu/Headers/Menu.h"
#include "../../Services/Headers/JoueurService.h"

void processusPartie(bool debug);

bool verifierDefaite(p_joueur joueur);

bool verifierVictoire(p_salle salleActuelle);

p_salle choisirPremiereSalle(p_salleDebut salleActuelle);

p_salle choisirSalleSuivante(p_map map, p_salle salleActuelle);

void jouerCombat(p_donneesCombat donneesRound, bool debug);

void tranformerStrikeEnEsquive(p_donneesCombat donneesRound);

void tranformerEsquiveEnStrike(p_donneesCombat donneesRound);

void choixJoueurEvent();

void jouerEvent(p_listeMonstres miniBosses, p_donneesCombat donneesRound, bool debug);

void jouerSanctuaire(p_joueur joueur);

#endif //THESPIRE_PARTIECONTROLLER_H

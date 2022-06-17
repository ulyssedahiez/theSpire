//
// Created by charles on 16/06/22.
//

#ifndef THESPIRE_MAPSERVICE_H
#define THESPIRE_MAPSERVICE_H
#include "../../Model/Headers/Monstre.h"
#include "../../Model/Headers/Map.h"
#include "UtilsService.h"

void remplirMap(p_map map);

p_listeCoordonnees genererCoordonneesMiniBosses();

p_listeCoordonnees genererCoordonneesEvents(p_listeCoordonnees coordonneesBosses);

p_listeCoordonnees genererCoordonneesSanctuaires(p_listeCoordonnees coordonneesBosses, p_listeCoordonnees coordonneesEvents);

void debugMap(p_map map);

#endif //THESPIRE_MAPSERVICE_H

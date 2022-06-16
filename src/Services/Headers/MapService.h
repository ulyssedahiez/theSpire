//
// Created by charles on 16/06/22.
//

#ifndef THESPIRE_MAPSERVICE_H
#define THESPIRE_MAPSERVICE_H
#include "../../Model/Headers/Monstre.h"
#include "../../Model/Headers/Map.h"
#include "UtilsService.h"

void remplirMap(p_map map, p_listeMonstres listeMonstresEtage1A4, p_listeMonstres listeMonstresEtage5A9, p_listeMonstres miniBosses, p_monstre dernierBoss);

p_coordonneesTour genererCoordonneesMiniBosses();

p_coordonneesTour genererCoordonneesEvents(p_coordonneesTour coordonneesBosses);

p_coordonneesTour genererCoordonneesSanctuaires(p_coordonneesTour coordonneesBosses, p_coordonneesTour coordonneesEvents);

#endif //THESPIRE_MAPSERVICE_H

//
// Created by charles on 16/06/22.
//

#ifndef THESPIRE_MONSTRESERVICE_H
#define THESPIRE_MONSTRESERVICE_H
#include "../../Model/Headers/Monstre.h"
#include "UtilsService.h"

p_listeMonstres creerListeMonstresEtage1A4();

p_listeMonstres creerListeMonstresEtage5A9();

p_listeMonstres creerListeMiniBosses();

p_monstre creerDernierBoss();

void remplirPointsVieMonstre(p_monstre monstre);

#endif //THESPIRE_MONSTRESERVICE_H

//
// Created by Ulysse Dahiez on 11/06/2022.
//

#include "CombatController.h"

void processusRound(t_donneesCombat donneesCombat) {
    int tour = 1;
    while (donneesCombat.joueur->pointsVieActuels > 0 && donneesCombat.salleActuelle->monstre->pointsVie > 0) {
        processusTourMonstre(donneesCombat);
        processusTourJoueur(donneesCombat);
        processusTourMonstre(donneesCombat);
        tour++;
    }
}

void processusTourJoueur(t_donneesCombat donneesCombat) {

}

void processusTourMonstre(t_donneesCombat donneesCombat) {

}
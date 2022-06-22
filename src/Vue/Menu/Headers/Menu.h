//
// Created by Ulysse Dahiez on 08/06/2022.
//

#ifndef THESPIRE_MENU_H
#define THESPIRE_MENU_H
#include "../../Model/Headers/Carte.h"
#include "Affichages.h"

int lancerMenu(bool debug);

int menuChoixSalle(char* choix1, char* choix2, char* choix3, char* choix4);

/**
 * retourne l'index de la carte choisie
 * @param choixMax
 * @return position carte dans la main
 */
int menuChoixCarteMain(p_listeCartes listeCartes);

int credit();
int regles();

#endif //THESPIRE_MENU_H

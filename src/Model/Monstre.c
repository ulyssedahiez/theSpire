//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Monstre.h"

p_monstre creerMonstre(char *nom, int pointsVie, p_listeAttaques attaques, int borneInfPV, int borneSupPV, char* type) {
    p_monstre monstre = malloc(sizeof(t_monstre));
    monstre->nom = nom;
    monstre->attaques = attaques;
    monstre->pointsVie = pointsVie;
    monstre->borneInfPointsVie = borneInfPV;
    monstre->borneSupPointsVie = borneSupPV;
    monstre->type = type;

    return monstre;
}

p_listeMonstres creerListeMonstres() {
    p_listeMonstres listeMonstres = malloc(sizeof(t_listeMonstres));
    listeMonstres->nombreMonstres = 0;
    listeMonstres->premiereMonstre = NULL;

    return listeMonstres;
}
void ajouterMonstreListe(p_listeMonstres listeMonstres, p_monstre monstre) {
    p_monstreChainable nouveauMonstre = creerMonstreChainable(monstre);
    if (0 == listeMonstres->nombreMonstres) {
        listeMonstres->premiereMonstre = nouveauMonstre;
    } else {
        p_monstreChainable monstreChainableActuelle = listeMonstres->premiereMonstre;
        while (NULL != monstreChainableActuelle->monstreSuivante) {
            monstreChainableActuelle = monstreChainableActuelle->monstreSuivante;
        }
        monstreChainableActuelle->monstreSuivante = nouveauMonstre;
    }
    listeMonstres->nombreMonstres += 1;
}

p_monstreChainable creerMonstreChainable(p_monstre monstre) {
    p_monstreChainable monstreChainable = malloc(sizeof(t_monstreChainable));

    monstreChainable->monstre = monstre;
    monstreChainable->monstreSuivante = NULL;

    return monstreChainable;
}

p_monstre trouverPointeurNiemeMonstre(p_listeMonstres listeMonstre, int n) {
    int nActuel = 0;
    p_monstreChainable monstreActuel = listeMonstre->premiereMonstre;
    while (nActuel < n) {
        monstreActuel = monstreActuel->monstreSuivante;

        nActuel++;
    }
    return monstreActuel->monstre;
}

p_monstre copierMonstre(p_monstre monstre) {
    p_monstre nouveauMonstre = creerMonstre(monstre->nom, monstre->pointsVie, monstre->attaques,
                                            monstre->borneInfPointsVie, monstre->borneSupPointsVie, false);

    return nouveauMonstre;
}


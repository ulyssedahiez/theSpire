//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Monstre.h"

p_monstre creerMonstre(char* nom, int pointsVie, p_listeAttaques attaques, int borneInfPV, int borneSupPV) {
    p_monstre monstre = malloc(sizeof(t_monstre));
    monstre->nom = nom;
    monstre->attaques = attaques;
    monstre->pointsVie = pointsVie;

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
//
// Created by charles on 11/05/22.
//
#include <stdlib.h>
#include "Headers/Objet.h"

p_objet creerObjet(char *nom, p_effet effet) {
    p_objet objet = malloc(sizeof(t_objet));
    objet->nom = nom;
    objet->effet = effet;

    return objet;
}

p_listeObjets creerListeObjets() {
    p_listeObjets listeObjets = malloc(sizeof(t_listeObjets));

    listeObjets->nombreObjets = 0;
    listeObjets->premiereObjet = NULL;

    return listeObjets;
}

p_objetChainable creerObjetChainable(p_objet objet) {
    p_objetChainable objetChainable = malloc(sizeof(t_objetChainable));

    objetChainable->objetSuivant = NULL;
    objetChainable->objet = objet;

    return objetChainable;
}

void ajouterObjetListe(p_listeObjets listeObjets, p_objet objet) {
    p_objetChainable nouvelObjet = creerObjetChainable(objet);
    if (0 == listeObjets->nombreObjets) {
        listeObjets->premiereObjet = nouvelObjet;
    } else {
        p_objetChainable dernierObjet = listeObjets->premiereObjet;
        while (NULL != dernierObjet->objetSuivant) {
            dernierObjet = dernierObjet->objetSuivant;
        }

        dernierObjet->objetSuivant = nouvelObjet;
    }

    listeObjets->nombreObjets += 1;
}

p_objet trouverPointeurObjet(p_listeObjets listeObjets, char* nomCherche) {
    p_objetChainable objet = listeObjets->premiereObjet;

    while (objet != NULL) {
        if (strcmp(nomCherche, objet->objet->nom) == 0) {
            return objet->objet;
        }
        objet = objet->objetSuivant;
    }
    return NULL;
}


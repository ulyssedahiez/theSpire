//
// Created by charles on 11/05/22.
//
#include <stdlib.h>
#include "Headers/Effet.h"

p_effet creerEffet(char* nom/*, char* propriete*/, bool surJoueur, int valeur, int nombreTours) {
    p_effet effet = malloc(sizeof(t_effet));
    effet->nom = nom;
    effet->surJoueur = surJoueur;
    //effet->propriete = propriete;
    effet->valeur = valeur;
    effet->nombreTours = nombreTours;
    effet->nombreToursRestants = nombreTours;

    return effet;
}

p_listeEffets creerListeEffets() {
    p_listeEffets listeEffets = malloc(sizeof(t_listeEffets));
    listeEffets->nombreEffets = 0;
    listeEffets->premiereEffet = NULL;

    return listeEffets;
}

void ajouterEffetListe(p_listeEffets listeEffets, p_effet effet) {
    p_effetChainable nouvelEffet = creerEffetChainable(effet);
    if (0 == listeEffets->nombreEffets) {
        listeEffets->premiereEffet = nouvelEffet;
    } else {
        p_effetChainable effetChainableActuel = listeEffets->premiereEffet;
        while (NULL != effetChainableActuel->effetSuivant) {
            effetChainableActuel = effetChainableActuel->effetSuivant;
        }
        effetChainableActuel->effetSuivant = nouvelEffet;
    }
    listeEffets->nombreEffets += 1;
}

/** retourne true si supprimé, false si non présent dans la liste */
bool enleverEffetListe(p_listeEffets listeEffets, p_effet effet) {
    if (effet == listeEffets->premiereEffet->effet) {
        p_effetChainable aSupprimer = listeEffets->premiereEffet;
        listeEffets->premiereEffet = listeEffets->premiereEffet->effetSuivant;
        supprimerEffetChainable(aSupprimer);
        listeEffets->nombreEffets -= 1;

        return true;
    } else {
        p_effetChainable effetChainableActuel = listeEffets->premiereEffet;
        while (effet != effetChainableActuel->effet || NULL != effetChainableActuel->effetSuivant) {
            effetChainableActuel = effetChainableActuel->effetSuivant;
        }
        if (effet == effetChainableActuel->effet) {
            supprimerEffetChainable(effetChainableActuel);
            listeEffets->nombreEffets -= 1;

            return true;
        }
    }
    return false;
}

void supprimerEffetChainable(p_effetChainable effetChainable) {
    supprimerEffet(effetChainable->effet);
    free(effetChainable);
}

void supprimerEffet(p_effet effet) {
    free(effet);
}

p_effetChainable creerEffetChainable(p_effet effet) {
    p_effetChainable effetChainable = malloc(sizeof(t_effetChainable));

    effetChainable->effet = effet;
    effetChainable->effetSuivant = NULL;

    return effetChainable;
}

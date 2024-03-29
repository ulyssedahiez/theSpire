//
// Created by charles on 11/05/22.
//
#include <stdlib.h>
#include "Headers/Effet.h"

p_effet creerEffet(char *nom, bool surJoueur, int valeur) {
    p_effet effet = malloc(sizeof(t_effet));
    effet->nom = nom;
    effet->surJoueur = surJoueur;
    effet->valeur = valeur;
    if (0 == strcmp("Faible", nom) || 0 == strcmp("Lent", nom)) {
        effet->nombreToursRestants = valeur;
        effet->permanent = false;
    } else {
        effet->nombreToursRestants = 0;
        effet->permanent = true;
    }

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

p_effet copierEffet(p_effet effet) {
    p_effet nouvelEffet = creerEffet(effet->nom, effet->surJoueur, effet->valeur);
    return nouvelEffet;
}

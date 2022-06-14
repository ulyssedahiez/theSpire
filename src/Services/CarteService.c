//
// Created by charles on 14/06/22.
//

#include "Headers/CarteService.h"
void genererListesCartes(p_listeCartes basiques, p_listeCartes communes, p_listeCartes atypiques, p_listeCartes rares) {
    basiques = creerListeCartes();
    ajouterCarteListe(basiques, creerCarte("Strike", "basique", 1, 0, NULL, "Inﬂige 6 dégâts", "L’attaque de base"));
    ajouterCarteListe(basiques, creerCarte("Esquive", "basique", 1, 0, NULL, "Donne 5 points d’esquive", "L’esquive de base"));
    //ajouterCarteListe(basiques, creerCarte());

    // TODO: Terminer génération des cartes
    // TODO: Faire la gérération des effet et des listes pour les ajouter aux cartes
}
//
// Created by charles on 14/06/22.
//

#include "Headers/CarteService.h"
void genererListesCartes(p_listeCartes basiques, p_listeCartes communes, p_listeCartes atypiques, p_listeCartes rares) {
    basiques = creerListeCartes();
    ajouterCarteListe(basiques, creerCarte("Strike", "basique", 1, 0, NULL, "Inﬂige 6 dégâts", "L’attaque de base"));
    ajouterCarteListe(basiques, creerCarte("Esquive", "basique", 1, 0, NULL, "Donne 5 points d’esquive", "L’esquive de base"));

    communes = creerListeCartes();
    ajouterCarteListe(communes, creerCarte("Double strike", "commune", 1, 0, NULL, "Attaque deux fois pour 4 dégâts", "Démultiplicateur de force"));
    ajouterCarteListe(communes, creerCarte("Boule de feu", "commune", 0, 20, NULL, "Inﬂige 6 points de feu", "Un classique des mages débutants"));
    ajouterCarteListe(communes, creerCarte("Coup affaiblissant", "commune", 2, 0, NULL, "Inﬂige 3 dégâts et rends l’ennemi faible pour 2 tours", "Permet d’attaquer tout en se défendant"));
    ajouterCarteListe(communes, creerCarte("Acceleration", "commune", 1, 10, NULL, "Inﬂige Lent pour un tour et donne 4 points d’esquive", "Ne ralenti pas exactement les adversaires ; tout est question de perception."));

    atypiques = creerListeCartes();
    ajouterCarteListe(atypiques, creerCarte("Surménage", "atypique", 1, 20, NULL, "Augmente les dégâts de 2, mais vous inﬂige 5 dégâts", "Permet de frapper plus fort, mais attention aux courbatures !"));
    ajouterCarteListe(atypiques, creerCarte("Posture défensive", "atypique", 0, 0, NULL, "Dextérité +2, mais Force -1", "Permet de mieux esquiver, mais faire durer les combats plus longtemps"));
    ajouterCarteListe(atypiques, creerCarte("Concentration", "atypique", 3, 0, NULL, "Recharge 50 points de mana", "Important si les combats durent longtemps"));
    ajouterCarteListe(atypiques, creerCarte("Incendie", "atypique", 2, 20, NULL, "Inﬂige 10 de feu à l’adversaire et 5 de feu à soi", "Aidera à terminer les combats, d’une manière ou l’autre"));

    rares = creerListeCartes();
    ajouterCarteListe(rares, creerCarte("Pulvériser", "rare", 3, 0, NULL , "Inﬂige 30 dégâts, Abyssal", "Blam !"));
    ajouterCarteListe(rares, creerCarte("Spectre complet", "rare", 2, 20, NULL , "Donne différents bonus. Abyssal.", "Un bonus pour chaque couleur de l’arc-en-ciel."));

    // TODO: Terminer génération des cartes
    // TODO: Faire la gérération des effet et des listes pour les ajouter aux cartes
}
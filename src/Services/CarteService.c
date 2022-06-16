//
// Created by charles on 14/06/22.
//

#include "Headers/CarteService.h"

void genererListesCartes(p_listeCartes basiques, p_listeCartes communes, p_listeCartes atypiques, p_listeCartes rares) {
    /* Création des cartes basiques */
    basiques = creerListeCartes();
    p_listeEffets listeEffetsStrike = creerListeEffets();
    ajouterEffetListe(listeEffetsStrike, creerEffet("Dégats", false, 6, 1));
    ajouterCarteListe(basiques, creerCarte("Strike", "basique", 1, 0, listeEffetsStrike, "Inﬂige 6 dégâts", "L’attaque de base"));

    p_listeEffets listeEffetsEsquive = creerListeEffets();
    ajouterEffetListe(listeEffetsEsquive, creerEffet("Esquive", true, 5, 1));
    ajouterCarteListe(basiques, creerCarte("Esquive", "basique", 1, 0, NULL, "Donne 5 points d’esquive", "L’esquive de base"));

    /* création des cartes communes */
    communes = creerListeCartes();
    p_listeEffets listeEffetsDoubleStrike = creerListeEffets();
    ajouterEffetListe(listeEffetsDoubleStrike, creerEffet("Dégâts", false, 4, 1));
    ajouterEffetListe(listeEffetsDoubleStrike, creerEffet("Dégâts", false, 4, 1));
    ajouterCarteListe(communes, creerCarte("Double strike", "commune", 1, 0, listeEffetsDoubleStrike, "Attaque deux fois pour 4 dégâts", "Démultiplicateur de force"));

    p_listeEffets listeEffetsBouleDeFeu = creerListeEffets();
    ajouterEffetListe(listeEffetsBouleDeFeu, creerEffet("Feu", false, 6, -1));
    ajouterCarteListe(communes, creerCarte("Boule de feu", "commune", 0, 20, listeEffetsBouleDeFeu, "Inﬂige 6 points de feu", "Un classique des mages débutants"));

    p_listeEffets listeEffetsCoupAffaiblissant = creerListeEffets();
    ajouterEffetListe(listeEffetsCoupAffaiblissant, creerEffet("Dégâts", false, 3, 1));
    ajouterEffetListe(listeEffetsCoupAffaiblissant, creerEffet("Faible", false, 25, 2));
    ajouterCarteListe(communes, creerCarte("Coup affaiblissant", "commune", 2, 0, listeEffetsCoupAffaiblissant, "Inﬂige 3 dégâts et rends l’ennemi faible pour 2 tours", "Permet d’attaquer tout en se défendant"));

    p_listeEffets listeEffetsAcceleration = creerListeEffets();
    ajouterEffetListe(listeEffetsAcceleration, creerEffet("Esquive", true, 4, 1));
    ajouterEffetListe(listeEffetsAcceleration, creerEffet("Lenteur", false, 2, -1));
    ajouterCarteListe(communes, creerCarte("Acceleration", "commune", 1, 10, listeEffetsAcceleration, "Inﬂige Lent pour un tour et donne 4 points d’esquive", "Ne ralenti pas exactement les adversaires ; tout est question de perception."));

    atypiques = creerListeCartes();
    p_listeEffets listeEffetsSurmenage = creerListeEffets();
    ajouterEffetListe(listeEffetsSurmenage, creerEffet("Force", true, 2, -1));
    ajouterEffetListe(listeEffetsSurmenage, creerEffet("Dégâts", true, 5, 1));
    ajouterCarteListe(atypiques, creerCarte("Surménage", "atypique", 1, 20, listeEffetsSurmenage, "Augmente les dégâts de 2, mais vous inﬂige 5 dégâts", "Permet de frapper plus fort, mais attention aux courbatures !"));

    p_listeEffets listeEffetsPostureDefensive = creerListeEffets();
    ajouterEffetListe(listeEffetsPostureDefensive, creerEffet("Dextérité", true, 2, -1));
    ajouterEffetListe(listeEffetsPostureDefensive, creerEffet("Force", true, -1, -1));
    ajouterCarteListe(atypiques, creerCarte("Posture défensive", "atypique", 0, 0, listeEffetsPostureDefensive, "Dextérité +2, mais Force -1", "Permet de mieux esquiver, mais faire durer les combats plus longtemps"));

    p_listeEffets listeEffetsConcentration = creerListeEffets();
    ajouterEffetListe(listeEffetsConcentration, creerEffet("Mana", true, 50, 1));
    ajouterCarteListe(atypiques, creerCarte("Concentration", "atypique", 3, 0, listeEffetsConcentration, "Recharge 50 points de mana", "Important si les combats durent longtemps"));

    p_listeEffets listeEffetsIncendie = creerListeEffets();
    ajouterEffetListe(listeEffetsIncendie, creerEffet("Feu", false, 10, -1));
    ajouterEffetListe(listeEffetsIncendie, creerEffet("Feu", true, 5, -1));
    ajouterCarteListe(atypiques, creerCarte("Incendie", "atypique", 2, 20, listeEffetsIncendie, "Inﬂige 10 de feu à l’adversaire et 5 de feu à soi", "Aidera à terminer les combats, d’une manière ou l’autre"));

    rares = creerListeCartes();
    p_listeEffets listeEffetsPulveriser = creerListeEffets();
    ajouterEffetListe(listeEffetsPulveriser, creerEffet("Dégâts", false, 30, 1));
    ajouterEffetListe(listeEffetsPulveriser, creerEffet("Abyssal", false, 0, -1));
    ajouterCarteListe(rares, creerCarte("Pulvériser", "rare", 3, 0, NULL , "Inﬂige 30 dégâts, Abyssal", "Blam !"));

    p_listeEffets listeEffetsSpectreComplet = creerListeEffets();
    ajouterEffetListe(listeEffetsIncendie, creerEffet("Feu", false, 3, -1));
    ajouterEffetListe(listeEffetsPulveriser, creerEffet("Dégâts", false, 6, 1));
    ajouterEffetListe(listeEffetsPostureDefensive, creerEffet("Force", true, 1, -1));
    ajouterEffetListe(listeEffetsAcceleration, creerEffet("Lenteur", false, 1, -1));
    ajouterEffetListe(listeEffetsCoupAffaiblissant, creerEffet("Faible", false, 25, 1));
    ajouterEffetListe(listeEffetsPostureDefensive, creerEffet("Dextérité", true, 1, -1));
    ajouterEffetListe(listeEffetsAcceleration, creerEffet("Esquive", true, 5, 1));
    ajouterEffetListe(listeEffetsPulveriser, creerEffet("Abyssal", false, 0, -1));
    ajouterCarteListe(rares, creerCarte("Spectre complet", "rare", 2, 20, NULL , "Donne différents bonus. Abyssal.", "Un bonus pour chaque couleur de l’arc-en-ciel."));
}
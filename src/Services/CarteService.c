//
// Created by charles on 14/06/22.
//

#include "Headers/CarteService.h"

p_listeCartes genererListeCartesBasiques() {
    p_listeCartes basiques = creerListeCartes();

    p_listeEffets listeEffetsStrike = creerListeEffets();
    ajouterEffetListe(listeEffetsStrike, creerEffet("Dégats", false, 6));
    ajouterCarteListe(basiques, creerCarte("Strike", "basique", 1, 0, listeEffetsStrike, "Inﬂige 6 dégâts", "L’attaque de base"));

    p_listeEffets listeEffetsEsquive = creerListeEffets();
    ajouterEffetListe(listeEffetsEsquive, creerEffet("Esquive", true, 5));
    ajouterCarteListe(basiques, creerCarte("Esquive", "basique", 1, 0, listeEffetsEsquive, "Donne 5 points d’esquive", "L’esquive de base"));

    return basiques;
}

p_listeCartes genererListeCartesCommunes() {
    p_listeCartes communes = creerListeCartes();

    p_listeEffets listeEffetsDoubleStrike = creerListeEffets();
    ajouterEffetListe(listeEffetsDoubleStrike, creerEffet("Dégâts", false, 4));
    ajouterEffetListe(listeEffetsDoubleStrike, creerEffet("Dégâts", false, 4));
    ajouterCarteListe(communes, creerCarte("Double strike", "commune", 1, 0, listeEffetsDoubleStrike, "Attaque deux fois pour 4 dégâts", "Démultiplicateur de force"));

    p_listeEffets listeEffetsBouleDeFeu = creerListeEffets();
    ajouterEffetListe(listeEffetsBouleDeFeu, creerEffet("Feu", false, 6));
    ajouterCarteListe(communes, creerCarte("Boule de feu", "commune", 0, 20, listeEffetsBouleDeFeu, "Inﬂige 6 points de feu", "Un classique des mages débutants"));

    p_listeEffets listeEffetsCoupAffaiblissant = creerListeEffets();
    ajouterEffetListe(listeEffetsCoupAffaiblissant, creerEffet("Dégâts", false, 3));
    ajouterEffetListe(listeEffetsCoupAffaiblissant, creerEffet("Faible", false, 2));
    ajouterCarteListe(communes, creerCarte("Coup affaiblissant", "commune", 2, 0, listeEffetsCoupAffaiblissant, "Inﬂige 3 dégâts et rends l’ennemi faible pour 2 tours", "Permet d’attaquer tout en se défendant"));

    p_listeEffets listeEffetsAcceleration = creerListeEffets();
    ajouterEffetListe(listeEffetsAcceleration, creerEffet("Esquive", true, 4));
    ajouterEffetListe(listeEffetsAcceleration, creerEffet("Lenteur", false, 1));
    ajouterCarteListe(communes, creerCarte("Acceleration", "commune", 1, 10, listeEffetsAcceleration, "Inﬂige Lent pour un tour et donne 4 points d’esquive", "Ne ralenti pas exactement les adversaires ; tout est question de perception."));

    return communes;
}

p_listeCartes genererListeCartesAtypiques() {
    p_listeCartes atypiques = creerListeCartes();

    p_listeEffets listeEffetsSurmenage = creerListeEffets();
    ajouterEffetListe(listeEffetsSurmenage, creerEffet("Force", true, 2));
    ajouterEffetListe(listeEffetsSurmenage, creerEffet("Dégâts", true, 5));
    ajouterCarteListe(atypiques, creerCarte("Surménage", "atypique", 1, 20, listeEffetsSurmenage, "Augmente les dégâts de 2, mais vous inﬂige 5 dégâts", "Permet de frapper plus fort, mais attention aux courbatures !"));

    p_listeEffets listeEffetsPostureDefensive = creerListeEffets();
    ajouterEffetListe(listeEffetsPostureDefensive, creerEffet("Dextérité", true, 2));
    ajouterEffetListe(listeEffetsPostureDefensive, creerEffet("Force", true, -1));
    ajouterCarteListe(atypiques, creerCarte("Posture défensive", "atypique", 0, 0, listeEffetsPostureDefensive, "Dextérité +2, mais Force -1", "Permet de mieux esquiver, mais faire durer les combats plus longtemps"));

    p_listeEffets listeEffetsConcentration = creerListeEffets();
    ajouterEffetListe(listeEffetsConcentration, creerEffet("Mana", true, 50));
    ajouterCarteListe(atypiques, creerCarte("Concentration", "atypique", 3, 0, listeEffetsConcentration, "Recharge 50 points de mana", "Important si les combats durent longtemps"));

    p_listeEffets listeEffetsIncendie = creerListeEffets();
    ajouterEffetListe(listeEffetsIncendie, creerEffet("Feu", false, 10));
    ajouterEffetListe(listeEffetsIncendie, creerEffet("Feu", true, 5));
    ajouterCarteListe(atypiques, creerCarte("Incendie", "atypique", 2, 20, listeEffetsIncendie, "Inﬂige 10 de feu à l’adversaire et 5 de feu à soi", "Aidera à terminer les combats, d’une manière ou l’autre"));

    return atypiques;
}

p_listeCartes genererListeCartesRares() {
    p_listeCartes rares = creerListeCartes();

    p_listeEffets listeEffetsPulveriser = creerListeEffets();
    ajouterEffetListe(listeEffetsPulveriser, creerEffet("Dégâts", false, 30));
    ajouterEffetListe(listeEffetsPulveriser, creerEffet("Abyssal", false, 0));
    ajouterCarteListe(rares, creerCarte("Pulvériser", "rare", 3, 0, listeEffetsPulveriser , "Inﬂige 30 dégâts, Abyssal", "Blam !"));

    p_listeEffets listeEffetsSpectreComplet = creerListeEffets();
    ajouterEffetListe(listeEffetsSpectreComplet, creerEffet("Feu", false, 3));
    ajouterEffetListe(listeEffetsSpectreComplet, creerEffet("Dégâts", false, 6));
    ajouterEffetListe(listeEffetsSpectreComplet, creerEffet("Force", true, 1));
    ajouterEffetListe(listeEffetsSpectreComplet, creerEffet("Lenteur", false, 1));
    ajouterEffetListe(listeEffetsSpectreComplet, creerEffet("Faible", false, 1));
    ajouterEffetListe(listeEffetsSpectreComplet, creerEffet("Dextérité", true, 1));
    ajouterEffetListe(listeEffetsSpectreComplet, creerEffet("Esquive", true, 5));
    ajouterEffetListe(listeEffetsSpectreComplet, creerEffet("Abyssal", false, 0));
    ajouterCarteListe(rares, creerCarte("Spectre complet", "rare", 2, 20, listeEffetsSpectreComplet , "Donne différents bonus. Abyssal.", "Un bonus pour chaque couleur de l’arc-en-ciel."));

    return rares;
}

void initialiserDeckPrincipal(p_listeCartes deckPrincipal, p_listeCartes cartesBasiques, p_listeCartes cartesRares) {
    p_carte carteStrike = trouverPointeurCarte(cartesBasiques, "Strike");
    p_carte carteEsquive = trouverPointeurCarte(cartesBasiques, "Esquive");
    p_carte carteSpectreComplet = trouverPointeurCarte(cartesRares, "Spectre complet");

    ajouterCarteListe(deckPrincipal, carteStrike);
    ajouterCarteListe(deckPrincipal, carteStrike);
    ajouterCarteListe(deckPrincipal, carteStrike);
    ajouterCarteListe(deckPrincipal, carteStrike);
    ajouterCarteListe(deckPrincipal, carteStrike);

    ajouterCarteListe(deckPrincipal, carteEsquive);
    ajouterCarteListe(deckPrincipal, carteEsquive);
    ajouterCarteListe(deckPrincipal, carteEsquive);
    ajouterCarteListe(deckPrincipal, carteEsquive);
    ajouterCarteListe(deckPrincipal, carteEsquive);

    ajouterCarteListe(deckPrincipal, carteSpectreComplet);
}

//
// Created by charles on 30/05/22.
//

#include "Headers/Partie.h"

void processusPartie()
{
    p_joueur peter = creerJoueur();
    p_map map = creerMap();
    p_salle salleActuelle = choisirPremiereSalle(map->premiereSalle);


    while (true != verifierDefaite(peter) && true != verifierVictoire(map)) {

    }

    if (verifierDefaite(peter)) {

    } else if (verifierVictoire(map)) {

    }

    return;
}

void remplirMap(p_map map)
{

}

bool verifierDefaite(p_joueur joueur) {

}

bool verifierVictoire(p_map map) {

}

p_salle choisirPremiereSalle(p_salleDebut salleActuelle) {
    int choix = menuChoixSalle("Gauche", "Milieu gauche", "Milieu droite", "Droite");

    p_salle salleSuivante = NULL;
    if (1 == choix) {
        salleSuivante = salleActuelle->salleGauche;
    } else if (2 == choix) {
        salleSuivante = salleActuelle->salleMilieuGauche;
    } else if (3 == choix) {
        salleSuivante = salleActuelle->salleMilieuDroite;
    } else if (4 == choix) {
        salleSuivante = salleActuelle->salleDroite;
    }

    return salleSuivante;
}

p_salle choisirSalleSuivante(p_map map, p_salle salleActuelle) {
    int choix = menuChoixSalle("Gauche", "Milieu", "Droite","");

    p_salle salleSuivante = NULL;
    if (1 == choix) {
        salleSuivante = salleActuelle->salleGauche;
    } else if (2 == choix)
    {
        salleSuivante = salleActuelle->salleMilieu;
    } else if (3 == choix) {
        salleSuivante = salleActuelle->salleDroite;
    }

    return salleSuivante;
}

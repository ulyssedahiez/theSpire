//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Map.h"
#include "Headers/Salle.h"
#include "Headers/Event.h"

void creerCouloirSalle(p_salle salleActuelle, p_salle derniereSalle) {
    for (int i = 0; i < 8; ++i) {
        salleActuelle->salleMilieu = creerSalle();
        salleActuelle = salleActuelle->salleMilieu;
    }
    salleActuelle->salleMilieu = derniereSalle;
}

p_salle trouverPointeurNiemeSuivante(p_salle salle, int nCherche) {
    int nActuel = 0;
    while (nActuel < nCherche) {
        salle = salle->salleMilieu;

        nActuel++;
    }
    return salle;
}

p_coordonnees trouverCoordoneesSalle(p_map map, p_salle salle) {
    p_salle salleTestee = map->premiereSalle->salleGauche;
    int couloir = 0;
    int niveau = 0;

    while (salleTestee != salle) {
        if (salleTestee->salleMilieu == map->derniereSalle) {
            if (couloir == 0) {
                niveau = 0;
                salleTestee = map->premiereSalle->salleMilieuGauche;
            } else if (couloir == 1) {
                niveau = 0;
                salleTestee = map->premiereSalle->salleMilieuDroite;
            } else if (couloir == 2) {
                niveau = 0;
                salleTestee = map->premiereSalle->salleDroite;
            }
            else{
                return NULL;
            }
        } else {
            niveau += 1;
            salleTestee = salleTestee->salleMilieu;
        }
    }
    return creerCoordonnees(niveau, couloir);
}
p_map creerMap(){
    p_map map = malloc(sizeof(t_map));

    map->premiereSalle = creerSalleDebut();
    map->derniereSalle = creerSalle();
    map->premiereSalle->salleGauche = creerSalle();
    map->premiereSalle->salleMilieuGauche = creerSalle();
    map->premiereSalle->salleMilieuDroite = creerSalle();
    map->premiereSalle->salleDroite = creerSalle();

    p_salle actuelleGauche = map->premiereSalle->salleGauche;
    p_salle premiereGauche = map->premiereSalle->salleGauche;
    p_salle actuelleMilieuGauche = map->premiereSalle->salleMilieuGauche;
    p_salle premiereMilieuGauche = map->premiereSalle->salleMilieuGauche;
    p_salle actuelleMilieuDroite = map->premiereSalle->salleMilieuDroite;
    p_salle premiereMilieuDroite = map->premiereSalle->salleMilieuDroite;
    p_salle actuelleDroite = map->premiereSalle->salleDroite;
    p_salle premiereDroite = map->premiereSalle->salleDroite;

    creerCouloirSalle(actuelleGauche, map->derniereSalle);
    creerCouloirSalle(actuelleMilieuGauche, map->derniereSalle);
    creerCouloirSalle(actuelleMilieuDroite, map->derniereSalle);
    creerCouloirSalle(actuelleDroite,map->derniereSalle);


    for (int i = 0; i < 8; ++i) {
        actuelleGauche->salleDroite = trouverPointeurNiemeSuivante(premiereMilieuGauche, i+1);

        actuelleMilieuGauche->salleGauche = trouverPointeurNiemeSuivante(premiereGauche, i+1);
        actuelleMilieuGauche->salleDroite = trouverPointeurNiemeSuivante(premiereMilieuDroite, i+1);

        actuelleMilieuDroite->salleGauche = trouverPointeurNiemeSuivante(premiereMilieuGauche, i+1);
        actuelleMilieuDroite->salleDroite = trouverPointeurNiemeSuivante(premiereDroite, i+1);

        actuelleDroite->salleGauche = trouverPointeurNiemeSuivante(premiereMilieuDroite, i+1);

        actuelleGauche = actuelleGauche->salleMilieu;
        actuelleMilieuGauche = actuelleMilieuGauche->salleMilieu;
        actuelleMilieuDroite = actuelleMilieuDroite->salleMilieu;
        actuelleDroite = actuelleDroite->salleMilieu;
    }


    return map;
}
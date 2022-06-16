//
// Created by charles on 16/06/22.
//

#include "Headers/MapService.h"

void remplirMap(p_map map, p_listeMonstres listeMonstresEtage1A4, p_listeMonstres listeMonstresEtage5A9, p_listeMonstres miniBosses, p_monstre dernierBoss) {
    p_salle salleGaucheActuelle = map->premiereSalle->salleGauche;
    p_salle salleMilieuGaucheActuelle = map->premiereSalle->salleMilieuGauche;
    p_salle salleMilieuDroiteActuelle = map->premiereSalle->salleMilieuDroite;
    p_salle salleDroiteActuelle = map->premiereSalle->salleDroite;

    p_listeMonstres selectionMonstres;
    p_salle salleActuelle;
    for (int niveau = 1; niveau <= 9; ++niveau) {
        for (int couloir = 1; couloir <= 4; ++couloir) {
            if (1 == couloir) {
                salleActuelle = salleGaucheActuelle;
            } else if (2 == couloir) {
                salleActuelle = salleMilieuGaucheActuelle;
            } else if (3 == couloir) {
                salleActuelle = salleMilieuDroiteActuelle;
            } else if (4 == couloir) {
                salleActuelle = salleDroiteActuelle;
            }


            if (1 <= niveau && niveau <= 4) {
                selectionMonstres = listeMonstresEtage1A4;
                // TODO: Bail monstres niveau 1 à 4
            } else if (5 == niveau) {
                salleActuelle->monstre = NULL;
                salleActuelle->event = NULL;
                break;
            } else if (6 <= niveau && niveau <= 9) {
                selectionMonstres = listeMonstresEtage5A9;
                // TODO: Bail monstres niveau 5 à 9
            }



        }
    }

    map->derniereSalle->monstre = dernierBoss;
}

p_coordonneesTour genererCoordonneesMiniBosses() {
    p_coordonneesTour premier = creerCoordonneesTour(genererEntier(1, 10), genererEntier(1, 5));

    int nb = 1;
    while (nb < 3) {
        p_coordonneesTour nouveau = creerCoordonneesTour(genererEntier(1, 10), genererEntier(1, 5));
        while (nouveau->niveau == 5 && estDansListe(premier, nouveau->niveau, nouveau->couloir) == true) {
            nouveau = creerCoordonneesTour(genererEntier(1, 10), genererEntier(1, 5));
        }
        ajouterCoordonnee(premier, nouveau);
        nb++;
    }
    return premier;
}

p_coordonneesTour genererCoordonneesEvents(p_coordonneesTour coordonneesBosses) {
    p_coordonneesTour premier = creerCoordonneesTour(genererEntier(1, 10), genererEntier(1, 5));

    int nb = 1;
    while (nb < 3) {
        p_coordonneesTour nouveau = creerCoordonneesTour(genererEntier(1, 10), genererEntier(1, 5));
        while (nouveau->niveau == 5 && estDansListe(premier, nouveau->niveau, nouveau->couloir) == true
                && estDansListe(coordonneesBosses, nouveau->niveau, nouveau->couloir) == true) {
            nouveau = creerCoordonneesTour(genererEntier(1, 10), genererEntier(1, 5));
        }
        ajouterCoordonnee(premier, nouveau);
        nb++;
    }
    return premier;
}

p_coordonneesTour genererCoordonneesSanctuaires(p_coordonneesTour coordonneesBosses, p_coordonneesTour coordonneesEvents) {
    p_coordonneesTour premier = creerCoordonneesTour(genererEntier(1, 10), genererEntier(1, 5));

    int nb = 1;
    while (nb < 3) {
        p_coordonneesTour nouveau = creerCoordonneesTour(genererEntier(1, 10), genererEntier(1, 5));
        while (nouveau->niveau == 5 && estDansListe(premier, nouveau->niveau, nouveau->couloir) == true
               && estDansListe(coordonneesBosses, nouveau->niveau, nouveau->couloir) == true
                  && estDansListe(coordonneesEvents, nouveau->niveau, nouveau->couloir) == true) {
            nouveau = creerCoordonneesTour(genererEntier(1, 10), genererEntier(1, 5));
        }
        ajouterCoordonnee(premier, nouveau);
        nb++;
    }
    return premier;
}


//
// Created by charles on 16/06/22.
//

#include "Headers/MapService.h"
#include "Headers/MonstreService.h"
#include "Headers/EventService.h"
#include "stdio.h"
#include "../../Model/Headers/Monstre.h"

void remplirMap(p_map map) {
    p_listeMonstres listeMonstresEtage1A4 = creerListeMonstresEtage1A4();
    p_listeMonstres listeMonstresEtage5A9 = creerListeMonstresEtage5A9();
    p_listeMonstres miniBosses = creerListeMiniBosses();
    p_monstre dernierBoss = creerDernierBoss();

    p_salle salleGaucheActuelle = map->premiereSalle->salleGauche;
    p_salle salleMilieuGaucheActuelle = map->premiereSalle->salleMilieuGauche;
    p_salle salleMilieuDroiteActuelle = map->premiereSalle->salleMilieuDroite;
    p_salle salleDroiteActuelle = map->premiereSalle->salleDroite;

    p_salle salleActuelle;
    p_listeEvent selectionEvents = genererListesEvents();
    p_listeMonstres selectionMonstres;

    p_listeCoordonnees coordonneesMinibosses = genererCoordonneesMiniBosses();
    p_listeCoordonnees coordonneesEvents = genererCoordonneesEvents(coordonneesMinibosses);
    p_listeCoordonnees coordonneesSanctuaires = genererCoordonneesSanctuaires(coordonneesMinibosses, coordonneesEvents);

    for (int niveau = 1; niveau <= 9; ++niveau) {
        int couloirEvent;
        do {
            couloirEvent = genererEntier(1, 5);
        } while (estDansListe(coordonneesMinibosses, niveau, couloirEvent) ||
                 estDansListe(coordonneesSanctuaires, niveau, couloirEvent));

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


            salleActuelle->monstre = NULL;
            salleActuelle->event = NULL;

            if (5 != niveau) {
                if (estDansListe(coordonneesMinibosses, niveau, couloir)) {
                    salleActuelle->monstre = trouverPointeurNiemeMonstre(miniBosses,
                                                                         genererEntier(0, miniBosses->nombreMonstres));
                } else if (estDansListe(coordonneesSanctuaires, niveau, couloir)) {

                } else if (couloir == couloirEvent) {
                    salleActuelle->event = trouverPointeurNiemeEvent(selectionEvents,
                                                                     genererEntier(0, selectionEvents->nombreEvents));
                } else {
                    if (1 <= niveau && niveau <= 4) {
                        selectionMonstres = listeMonstresEtage1A4;
                    } else if (6 <= niveau && niveau <= 9) {
                        selectionMonstres = listeMonstresEtage5A9;
                    }
                    salleActuelle->monstre = trouverPointeurNiemeMonstre(selectionMonstres, genererEntier(0,
                                                                                                          selectionMonstres->nombreMonstres));
                }
            }
            if (1 == couloir) {
                salleGaucheActuelle = salleGaucheActuelle->salleMilieu;
            } else if (2 == couloir) {
                salleMilieuGaucheActuelle = salleMilieuGaucheActuelle->salleMilieu;
            } else if (3 == couloir) {
                salleMilieuDroiteActuelle = salleMilieuDroiteActuelle->salleMilieu;
            } else if (4 == couloir) {
                salleDroiteActuelle = salleDroiteActuelle->salleMilieu;
            }
        }
    }

    map->derniereSalle->monstre = dernierBoss;
}

p_listeCoordonnees genererCoordonneesMiniBosses() {
    p_listeCoordonnees minibosses = creerListeCoordonnees();

    while (minibosses->nombreCoordonnees != 3) {
        p_coordonnees nouveau;
        do {
            nouveau = creerCoordonnees(genererEntier(1, 10), genererEntier(1, 5));
        } while (nouveau->niveau == 5 || estDansListe(minibosses, nouveau->niveau, nouveau->couloir) == true);
        ajouterCoordonnee(minibosses, nouveau);
    }

    return minibosses;
}

p_listeCoordonnees genererCoordonneesEvents(p_listeCoordonnees coordonneesBosses) {
    p_listeCoordonnees events = creerListeCoordonnees();

    while (events->nombreCoordonnees != 3) {
        p_coordonnees nouveau;
        do {
            nouveau = creerCoordonnees(genererEntier(1, 10), genererEntier(1, 5));
        } while (nouveau->niveau == 5 || estDansListe(events, nouveau->niveau, nouveau->couloir) == true
                || estDansListe(coordonneesBosses, nouveau->niveau, nouveau->couloir) == true);
        ajouterCoordonnee(events, nouveau);
    }

    return events;
}

p_listeCoordonnees genererCoordonneesSanctuaires(p_listeCoordonnees coordonneesBosses, p_listeCoordonnees coordonneesEvents) {
    p_listeCoordonnees sanctuaires = creerListeCoordonnees();

    while (sanctuaires->nombreCoordonnees != 5) {
        p_coordonnees nouveau;
        do {
            nouveau = creerCoordonnees(genererEntier(1, 10), genererEntier(1, 5));
        } while (nouveau->niveau == 5 || estDansListe(sanctuaires, nouveau->niveau, nouveau->couloir) == true
                || estDansListe(coordonneesBosses, nouveau->niveau, nouveau->couloir) == true
                || estDansListe(coordonneesEvents, nouveau->niveau, nouveau->couloir) == true);
        ajouterCoordonnee(sanctuaires, nouveau);
    }

    return sanctuaires;
}

void debugMap(p_map map) {
    p_salle salleActuelle = map->premiereSalle->salleGauche;
    int couloir = 1;
    do {
        if (salleActuelle->monstre != NULL) {
            printf("%s --- ", salleActuelle->monstre->nom);
        } else if (salleActuelle->event != NULL) {
            printf("Event%d --- ", salleActuelle->event->id);
        } else {
            printf("SANCT --- ");
        }
        if (salleActuelle->salleMilieu == map->derniereSalle) {
            printf("\n");
            if (couloir == 1) {
                salleActuelle = map->premiereSalle->salleMilieuGauche;
            } else if (couloir == 2) {
                salleActuelle = map->premiereSalle->salleMilieuDroite;
            } else if (couloir == 3) {
                salleActuelle = map->premiereSalle->salleDroite;
            } else {
                break;
            }
            couloir++;
        } else {
            salleActuelle = salleActuelle->salleMilieu;
        }
    } while (true);
}
//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Salle.h"

/*p_salle creerSalle(t_event *eventSalle, t_combat *combatSalle, t_salle *salleGaucheSalle, t_salle *salleMilieuSalle,
                   t_salle *salleDroiteSalle) {
    p_salle salle = malloc(sizeof(t_salle));
    salle->event = eventSalle;
    salle->combat = combatSalle;
    salle->salleDroite = salleDroiteSalle;
    salle->salleGauche = salleGaucheSalle;
    salle->salleMilieu = salleMilieuSalle;

    return salle;
}*/

p_salle creerSalle() {
    p_salle salle = malloc(sizeof(t_salle));
    salle->salleGauche = NULL;
    salle->salleMilieu = NULL;
    salle->salleDroite = NULL;
    salle->event = NULL;

    return salle;
}

p_salleDebut creerSalleDebut() {
    p_salleDebut salleDebut = malloc(sizeof(t_salleDebut));
    salleDebut->salleGauche = NULL;
    salleDebut->salleMilieuGauche = NULL;
    salleDebut->salleMilieuDroite = NULL;
    salleDebut->salleDroite = NULL;

    return salleDebut;
}

void remplirSalle(p_salle salle, p_event event, p_monstre monstre) {
    salle->event = event;
    salle->monstre = monstre;
}
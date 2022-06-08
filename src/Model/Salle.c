//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Salle.h"

p_salle creerSalle(t_event *eventSalle, t_combat *combatSalle, t_salle *salleGaucheSalle, t_salle *salleMilieuSalle,
                   t_salle *salleDroiteSalle) {
    p_salle salle = malloc(sizeof(t_salle));
    salle->event = eventSalle;
    salle->combat = combatSalle;
    salle->salleDroite = salleDroiteSalle;
    salle->salleGauche = salleGaucheSalle;
    salle->salleMilieu = salleMilieuSalle;

    return salle;
}
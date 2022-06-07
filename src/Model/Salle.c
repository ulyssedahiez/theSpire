//
// Created by charles on 30/05/22.
//

#include "Headers/Salle.h"

p_salle creerSalle(s_event *eventSalle, s_combat *combatSalle, s_salle *salleGaucheSalle, s_salle *salleMilieuSalle,
                   s_salle *salleDroiteSalle) {
    p_salle salle = malloc(sizeof(s_salle));
    salle->event = eventSalle;
    salle->combat = combatSalle;
    salle->salleDroite = salleDroiteSalle;
    salle->salleGauche = salleGaucheSalle;
    salle->salleMilieu = salleMilieuSalle;

    return salle;
}
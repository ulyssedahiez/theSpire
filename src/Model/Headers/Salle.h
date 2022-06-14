//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_SALLE_H
#define THESPIRE_SALLE_H

#include "Event.h"
#include "Combat.h"
#include "stdlib.h"

typedef struct s_salle
{
    struct s_event * event;
    struct s_combat * combat;
    struct s_salle * salleGauche;
    struct s_salle * salleMilieu;
    struct s_salle * salleDroite;
} t_salle;

typedef t_salle * p_salle;


typedef struct s_salleDebut
{
    struct s_salle * salleGauche;
    struct s_salle * salleMilieuGauche;
    struct s_salle * salleMilieuDroite;
    struct s_salle * salleDroite;
} t_salleDebut;

typedef t_salleDebut * p_salleDebut;

p_salleDebut creerSalleDebut();

p_salle creerSalle();

void remplirSalle(p_salle salle, p_event event, p_combat combat);

#endif //THESPIRE_SALLE_H

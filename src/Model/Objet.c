//
// Created by charles on 11/05/22.
//
#include <stdlib.h>
#include "Headers/Objet.h"

p_objet creerObjet(char *nomObjet, int valueObjet) {
    p_objet objet = malloc(sizeof(t_objet));
    objet->nom = nomObjet;
    objet->value = valueObjet;
    return objet;
}
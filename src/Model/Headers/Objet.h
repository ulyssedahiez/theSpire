//
// Created by charles on 11/05/22.
//

#ifndef THESPIRE_OBJET_H
#define THESPIRE_OBJET_H

#include "stdlib.h"

typedef struct s_objet
{
    char* nom;
    int value;
} t_objet;

typedef t_objet * p_objet;

typedef struct s_objetChainable {
    struct s_objet * objet;
    struct s_objetChainable * objetSuivant;
} t_objetChainable;

typedef t_objetChainable* p_objetChainable;

typedef struct s_listeObjets {
    struct s_objetChainable * premiereObjet;
    int nombreObjets;
} t_listeObjets;

typedef t_listeObjets* p_listeObjets;

p_listeObjets creerListeObjets();

p_objetChainable creerObjetChainable(p_objet objet);

p_objet creerObjet(char* nom, int value);

void ajouterObjetListe(p_listeObjets listeObjets, p_objet objet);

#endif //THESPIRE_OBJET_H

//
// Created by charles on 11/05/22.
//

#ifndef THESPIRE_EFFET_H
#define THESPIRE_EFFET_H

#include <stdbool.h>
#include "stdlib.h"
#include "string.h"

typedef struct s_effet
{
    char* nom;
    bool surJoueur;
    bool permanent;
    int valeur;
    int nombreToursRestants;
} t_effet;

typedef t_effet * p_effet;

typedef struct s_effetChainable {
    struct s_effet * effet;
    struct s_effetChainable * effetSuivant;
} t_effetChainable;

typedef t_effetChainable* p_effetChainable;

typedef struct s_listeEffets {
    struct s_effetChainable * premiereEffet;
    int nombreEffets;
} t_listeEffets;

typedef t_listeEffets* p_listeEffets;

p_effet creerEffet(char *nom, bool surJoueur, int valeur);

p_listeEffets creerListeEffets();

void ajouterEffetListe(p_listeEffets listeEffets, p_effet effet);

/** retourne true si supprimée, false si non présente dans la liste */
bool enleverEffetListe(p_listeEffets listeEffets, p_effet effet);

void supprimerEffetChainable(p_effetChainable effetChainable);

void supprimerEffet(p_effet effet);

p_effetChainable creerEffetChainable(p_effet effet);

p_effet copierEffet(p_effet effet);

#endif //THESPIRE_EFFET_H

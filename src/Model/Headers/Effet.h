//
// Created by charles on 11/05/22.
//

#ifndef THESPIRE_EFFET_H
#define THESPIRE_EFFET_H
#include "stdlib.h"

typedef struct s_effet
{
    char* nom;
    int value;
} t_effet;

typedef t_effet * p_effet;

typedef struct s_effetChainable {
    struct s_effet * effet;
    struct s_effet * effetSuivant;
} t_effetChainable;

typedef t_effetChainable* p_effetChainable;

typedef struct s_listeEffets {
    struct s_effetChainable * premiereEffet;
    int nombreEffets;
} t_listeEffets;

typedef t_listeEffets* p_listeEffets;

#endif //THESPIRE_EFFET_H

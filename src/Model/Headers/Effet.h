//
// Created by charles on 11/05/22.
//

#ifndef THESPIRE_EFFET_H
#define THESPIRE_EFFET_H

typedef struct s_effet
{
    char* nom;
    int value;
} t_effet;

typedef t_effet * p_effet;

struct s_effetChainable {
    struct s_effet * effet;
    struct s_effet * effetSuivant;
};

typedef s_effetChainable t_effetChainable;
typedef t_effetChainable* p_effetChainable;

struct s_listeEffets {
    struct s_effetChainable * premiereEffet;
    int nombreEffets;
};

typedef s_listeEffets t_listeEffets;
typedef t_listeEffets* p_listeEffets;

#endif //THESPIRE_EFFET_H

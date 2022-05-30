//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_ATTAQUE_H
#define THESPIRE_ATTAQUE_H

struct s_attaque {
    int
};

typedef s_attaque t_attaque;
typedef t_attaque* p_attaque;

struct s_attaqueChainable {
    p_attaque attaque;
    p_attaque attaqueSuivante;
};

typedef s_attaqueChainable t_attaqueChainable;
typedef t_attaqueChainable* p_attaqueChainable;

struct s_listeAttaques {
    p_attaqueChainable premiereCarte;
    int nombreAttaques;
};

typedef s_listeAttaques t_listeAttaques;
typedef t_listeAttaques* p_listeAttaques;

#endif //THESPIRE_ATTAQUE_H

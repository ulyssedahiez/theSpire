//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_ATTAQUE_H
#define THESPIRE_ATTAQUE_H

struct s_attaque {
    bool surJoueur;
    int probabiliteAttaque;
    int pointsDegats;
    int pointsEsquive;
    int pointsForce;
    int pointsFeu;
    int pointsDexterite;
    int nombreToursLenteur;
    int nombreToursFaiblesse;
};

typedef s_attaque t_attaque;
typedef t_attaque* p_attaque;

struct s_attaqueChainable {
    struct s_attaque * attaque;
    struct s_attaque * attaqueSuivante;
};

typedef s_attaqueChainable t_attaqueChainable;
typedef t_attaqueChainable* p_attaqueChainable;

struct s_listeAttaques {
    struct s_attaqueChainable * premiereCarte;
    int nombreAttaques;
};

typedef s_listeAttaques t_listeAttaques;
typedef t_listeAttaques* p_listeAttaques;

#endif //THESPIRE_ATTAQUE_H

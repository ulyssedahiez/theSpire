//
// Created by charles on 11/05/22.
//

#ifndef THESPIRE_OBJET_H
#define THESPIRE_OBJET_H

typedef struct s_objet
{
    char* nom;
    int value;
} t_objet;

typedef t_objet * p_objet;

struct s_objetChainable {
    p_objet objet;
    p_objet objetSuivant;
};

typedef s_objetChainable t_objetChainable;
typedef t_objetChainable* p_objetChainable;

struct s_listeObjets {
    p_objetChainable premiereObjet;
    int nombreObjets;
};

typedef s_listeObjets t_listeObjets;
typedef t_listeObjets* p_listeObjets;

#endif //THESPIRE_OBJET_H

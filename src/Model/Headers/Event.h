//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_EVENT_H
#define THESPIRE_EVENT_H
#include "stdlib.h"

typedef struct s_event
{
    int id;
    char* description;
    char* choixA;
    char* choixB;
} t_event;

typedef t_event * p_event;

typedef struct s_eventChainable {
    struct s_event *event;
    struct s_eventChainable *eventSuivant;
} t_eventChainable;

typedef t_eventChainable * p_eventChainable;

typedef struct s_listeEvent {
    struct s_eventChainable *premierEvent;
    int nombreEvents;
} t_listeEvent;

typedef t_listeEvent * p_listeEvent;

p_event trouverPointeurNiemeEvent(p_listeEvent listeEvent, int nCherche);


p_event creerEvent(char* description, char* choixA, char* choixB, int id);

p_listeEvent creerListeEvents();

void ajouterEventListe(p_listeEvent listeEvents, p_event event);

p_eventChainable creerEventChainable(p_event event);

#endif //THESPIRE_EVENT_H

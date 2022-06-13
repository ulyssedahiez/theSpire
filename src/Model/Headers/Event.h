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


typedef struct s_eventChainable {
    struct s_event *event;
    struct s_event *eventSuivant;
} t_eventChainable;

typedef struct s_listeEvent {
    struct s_eventChainable *premierEvent;
} t_listeEvent;

typedef t_event * p_event;

#endif //THESPIRE_EVENT_H

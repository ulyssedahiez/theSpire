//
// Created by charles on 30/05/22.
//
#include "Headers/Event.h"
p_event trouverPointeurNiemeEvent(p_listeEvent listeEvent, int nCherche) {
    int nActuel = 0;
    p_eventChainable eventChainable = listeEvent->premierEvent;
    while (nActuel < nCherche) {
        eventChainable = eventChainable->eventSuivant;

        nActuel++;
    }
    return eventChainable->event;
}


typedef t_listeEvent * p_listeEvent;

p_event creerEvent(char* description, char* choixA, char* choixB, int id) {
    p_event event = malloc(sizeof(t_event));
    event->description = description;
    event->choixA = choixA;
    event->choixB = choixB;
    event->id = id;

    return event;
}

p_listeEvent creerListeEvents() {
    p_listeEvent listeEvents = malloc(sizeof(t_listeEvent));

    listeEvents->premierEvent = NULL;
    listeEvents->nombreEvents = 0;

    return listeEvents;
}

void ajouterEventListe(p_listeEvent listeEvents, p_event event) {
    p_eventChainable nouvelleEvent = creerEventChainable(event);
    if (0 == listeEvents->nombreEvents) {
        listeEvents->premierEvent = nouvelleEvent;
    } else {
        p_eventChainable dernierEvent = listeEvents->premierEvent;
        while (dernierEvent->eventSuivant != NULL) {
            dernierEvent = dernierEvent->eventSuivant;
        }
        dernierEvent->eventSuivant = nouvelleEvent;
    }

    listeEvents->nombreEvents += 1;
}

p_eventChainable creerEventChainable(p_event event) {
    p_eventChainable eventChainable = malloc(sizeof(t_eventChainable));

    eventChainable->event = event;
    eventChainable->eventSuivant = NULL;

    return eventChainable;
}


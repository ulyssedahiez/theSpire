//
// Created by charles on 30/05/22.
//
#include "Headers/Event.h"
/*

t_listeEvent creerListeEvent(){
    for(int i = 0; i<5; i++){
        t_listeEvent laListeEvent= malloc(sizeof(t_listeEvent))
    }
}

*/

/*
p_event eventA = creerEvent(1,"Peter découvre un miniboss en train de dormir", " Lancer un combat contre un miniboss (gains normaux en cas de victoire)", "Ne pas faire le combat et avancer normalement" );

p_event eventB = creerEvent(2,"Un téléporteur se présente à Peter, mais impossible de savoir vers où il va!", "Entrer dans le téléporteur et aller dans une pièce adjacente (possibilités égales d avancer, revenir en arrière ou de rester au même niveau)", ": Dépenser 10 points de vie pour garantir d’aller à un endroit choisi" );

p_event eventC = creerEvent(3," Un piège magique modifie le deck de Peter", " Transforme tous les strike en esquive", "Transforme toutes les esquives en strikes" );

p_event eventD = creerEvent(4,"La salle est vide, mais dans un chaudron encore allumé, une potion est presque prête. Comment la terminer ?", " Faire une potion de santé (hp max +10)", "Faire une potion de mana (mana max +20)" );


*/

p_event trouverPointeurNiemeEvent(p_listeEvent listeEvent, int nCherche) {
    int nActuel = 1;
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


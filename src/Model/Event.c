//
// Created by charles on 30/05/22.
//
#include "Headers/Event.h"

p_event creerEvent(int idEvent, char *descriptionEvent, char *choixAEvent, char *choixBEvent) {
    p_event event = malloc(sizeof(t_event));
    event->id = idEvent;
    event->description = descriptionEvent;
    event->choixA = choixAEvent;
    event->choixB = choixBEvent;

    return event;
}

typedef struct s_listeEvent {
    struct s_eventChainable *premierEvent;
} t_listeEvent;

/*
p_event eventA = creerEvent(1,"Peter découvre un miniboss en train de dormir", " Lancer un combat contre un miniboss (gains normaux en cas de victoire)", "Ne pas faire le combat et avancer normalement" );

p_event eventB = creerEvent(2,"Un téléporteur se présente à Peter, mais impossible de savoir vers où il va!", "Entrer dans le téléporteur et aller dans une pièce adjacente (possibilités égales d avancer, revenir en arrière ou de rester au même niveau)", ": Dépenser 10 points de vie pour garantir d’aller à un endroit choisi" );

p_event eventC = creerEvent(3," Un piège magique modifie le deck de Peter", " Transforme tous les strike en esquive", "Transforme toutes les esquives en strikes" );

p_event eventD = creerEvent(4,"La salle est vide, mais dans un chaudron encore allumé, une potion est presque prête. Comment la terminer ?", " Faire une potion de santé (hp max +10)", "Faire une potion de mana (mana max +20)" );


*/


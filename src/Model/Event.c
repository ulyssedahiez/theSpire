//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Event.h"

p_event creerEvent(int idEvent, char *descriptionEvent, char *choixAEvent, char *choixBEvent) {
    p_event event = malloc(sizeof(t_event));
    event->id = idEvent;
    event->description = descriptionEvent;
    event->choixA = choixAEvent;
    event->choixB = choixBEvent;

    return event;
}
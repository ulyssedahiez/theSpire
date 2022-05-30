//
// Created by charles on 30/05/22.
//

#ifndef THESPIRE_EVENT_H
#define THESPIRE_EVENT_H

typedef struct s_event
{
    int id;
    char* description;
    char* choixA;
    char* choixB;
} t_event;

typedef s_event* p_event;

#endif //THESPIRE_EVENT_H

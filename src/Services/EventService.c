//
// Created by charles on 17/06/22.
//

#include "Headers/EventService.h"
#include "../../Model/Headers/Event.h"

p_listeEvent genererListesEvents() {
    p_listeEvent listeEvents = creerListeEvents();
    ajouterEventListe(listeEvents, creerEvent("Peter découvre un miniboss en train de dormir\n", "Lancer un combat contre un miniboss (gains normaux en cas de victoire)\n", "Ne pas faire le combat et avancer normalement\n", 1));
    ajouterEventListe(listeEvents, creerEvent("Un téléporteur se présente à Peter, mais impossible de savoir vers où il va !\n", "Entrer dans le téléporteur et aller dans une pièce adjacente (possibilités égales d’avancer, revenir en arrière ou de rester au même niveau)\n", "Dépenser 10 points de vie pour garantir d’aller à un endroit choisi\n", 2));
    ajouterEventListe(listeEvents, creerEvent("Un piège magique modiﬁe le deck de Peter\n", "Transforme tous les strike en esquive\n", "Transforme toutes les esquives en strikes\n", 3));
    ajouterEventListe(listeEvents, creerEvent("La salle est vide, mais dans un (Charles) chaudron encore allumé, une potion est presque prête. Comment la terminer ?\n", "Faire une potion de santé (hp max +10)\n", "Faire une potion de mana (mana max +20)\n", 4));

    return listeEvents;
}
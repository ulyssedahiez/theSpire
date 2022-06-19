//
// Created by charles on 17/06/22.
//

#include "Headers/EventService.h"
#include "../../Model/Headers/Event.h"

p_listeEvent genererListesEvents() {
    p_listeEvent listeEvents = creerListeEvents();
    ajouterEventListe(listeEvents, creerEvent("Peter découvre un miniboss en train de dormir", "Lancer un combat contre un miniboss (gains normaux en cas de victoire)", "Ne pas faire le combat et avancer normalement", 1));
    ajouterEventListe(listeEvents, creerEvent("Un téléporteur se présente à Peter, mais impossible de savoir vers où il va !", "Entrer dans le téléporteur et aller dans une pièce adjacente (possibilités égales d’avancer, revenir en arrière ou de rester au même niveau)", "Dépenser 10 points de vie pour garantir d’aller à un endroit choisi", 2));
    ajouterEventListe(listeEvents, creerEvent("Un piège magique modiﬁe le deck de Peter", "Transforme tous les strike en esquive", "Transforme toutes les esquives en strikes", 3));
    ajouterEventListe(listeEvents, creerEvent("La salle est vide, mais dans un (Charles) chaudron encore allumé, une potion est presque prête. Comment la terminer ?", "Faire une potion de santé (hp max +10)", "Faire une potion de mana (mana max +20)", 4));

    return listeEvents;
}
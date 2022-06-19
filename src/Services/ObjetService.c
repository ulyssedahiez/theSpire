//
// Created by charles on 18/06/22.
//

#include "Headers/ObjetService.h"

p_listeObjets genererObjets() {
    p_listeObjets listeObjets = creerListeObjets();
    ajouterObjetListe(listeObjets, creerObjet("Casse-croute", creerEffet("Soin", true, 4)));
    ajouterObjetListe(listeObjets, creerObjet("Arme", creerEffet("Force", true, 4)));
    ajouterObjetListe(listeObjets, creerObjet("Casque", creerEffet("Dextérité", true, 4)));
    ajouterObjetListe(listeObjets, creerObjet("Armure", creerEffet("PV-max", true, 20)));
    ajouterObjetListe(listeObjets, creerObjet("Chaussures", creerEffet("Energie-max", true, 1)));

    return listeObjets;
}
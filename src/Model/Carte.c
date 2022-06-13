//
// Created by charles on 11/05/22.
//
#include <stdlib.h>
#include "Headers/Carte.h"

p_carte creerCarte(char *nomCarte, char *rareteCarte, int pointEnergieCarte, int pointManaCarte, p_listeEffets listeEffetsCarte, char *texteTechniqueCarte, char *texteDescriptionCarte) {
    p_carte carte = malloc(sizeof(t_carte));
    carte->nom = nomCarte;
    carte->rarete = rareteCarte;
    carte->pointsEnergie = pointEnergieCarte;
    carte->pointsMana = pointManaCarte;
    carte->listeEffets = listeEffetsCarte;
    carte->texteDescription = texteDescriptionCarte;
    carte->texteTechnique = texteTechniqueCarte;

    return carte;
}




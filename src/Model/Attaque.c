//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Attaque.h"
#include <stdbool.h>

p_attaque creerAttaque(int pointsDegatsAttaque,
                       int nombreToursFaiblesseAttaque,
                       int nombreToursLenteurAttaque,
                       int pointsDexteriteAttaque,
                       int pointsEsquiveAttaque,
                       int pointsFeuAttaque,
                       int pointsForceAttaque,
                       int probabiliteAttaqueAttaque,
                       bool surJoueurAttaque
                       ) {
    p_attaque attaque = malloc(sizeof(t_attaque));
    attaque->pointsDegats = pointsDegatsAttaque;
    attaque->nombreToursFaiblesse = nombreToursFaiblesseAttaque;
    attaque->nombreToursLenteur = nombreToursLenteurAttaque;
    attaque->pointsDexterite = pointsDexteriteAttaque;
    attaque->pointsEsquive = pointsEsquiveAttaque;
    attaque->pointsFeu = pointsFeuAttaque;
    attaque->pointsForce = pointsForceAttaque;
    attaque->probabiliteAttaque = probabiliteAttaqueAttaque;
    attaque->surJoueur = surJoueurAttaque;

}
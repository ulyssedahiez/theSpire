//
// Created by Ulysse Dahiez on 11/06/2022.
//

#include "Headers/JoueurService.h"

void verifierProprietesJoueur(p_joueur joueur, int nbProprietesAVerifier, ...){
    va_list  ap;
    va_start(ap, nbProprietesAVerifier);
    char n;

    while (nbProprietesAVerifier > 0) {

    char n = va_arg(ap, int);
    printf("%c \n", n);
    --nbProprietesAVerifier;
    }
    va_end(ap);

}


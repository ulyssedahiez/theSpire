//
// Created by Ulysse Dahiez on 11/06/2022.
//

#include "Headers/JoueurService.h"

void corrigerProprietesJoueur(p_joueur joueur, int nbProprietesAVerifier, ...){
    va_list  ap;
    va_start(ap, nbProprietesAVerifier);
    char n;

    while (nbProprietesAVerifier > 0) {
        char n = va_arg(ap, int);
        if(n == 'v'){
            if(joueur->pointsVieActuels > joueur->pointsVieMax){
                joueur->pointsVieActuels = joueur->pointsVieMax;
            }
            if(joueur->pointsVieActuels<0){
                joueur->pointsVieActuels = 0;
            }
        }
        if(n == 'q'){
            if(joueur->pointsEsquiveActuels<0){
                joueur->pointsEsquiveActuels = 0;
            }
        }
        if(n == 'e'){
            if(joueur->pointsEnergieActuels > joueur->pointsEnergieMax){
                joueur->pointsEnergieActuels = joueur->pointsEnergieMax;
            }
            if(joueur->pointsEnergieActuels<0){
                joueur->pointsEnergieActuels = 0;
            }
        }
        if(n == 'm'){
            if(joueur->pointsManaActuels > joueur->pointsManaMax){
                joueur->pointsManaActuels = joueur->pointsManaMax;
            }
            if(joueur->pointsManaActuels<0){
                joueur->pointsManaActuels = 0;
            }
        }
    --nbProprietesAVerifier;
    }
    va_end(ap);
}


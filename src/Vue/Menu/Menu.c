//
// Created by Ulysse Dahiez on 08/06/2022.
//

#include "Headers/Menu.h"
#include <stdio.h>
#include <stdlib.h>


void lancerMenu(){

    int choix;
    printf("THE SPIRE \n\n");
    printf("Quel est votre choix? taper 1, 2 ou 3 \n\n");
    scanf("%d", &choix);

    printf("\n");
    switch (choix)
    {
        case 1:
            printf("Vous avez choisi le premier choix\n\n");
            int i = 0;
            printf("Quel est votre choix? taper 1, 2 ou 3\n\n");
            scanf("%d", &i);
            switch(i){
                case 1:
                    printf("choix 1 du sous menu 1\n\n");
                    break;
                case 2:
                    printf("choix 2 du sous menu 1\n\n");
                    break;
                case 3:
                    printf("choix 3 du sous menu 1 \n\n");
                    break;
                default:
                    printf("Vous n'avez pas rentre un nombre correct.\n\n");
                    break;
            }
            break;
        case 2:
            printf("Vous avez choisi le deuxieme choix\n\n");
            printf("Quel est votre choix?taper 1, 2 ou 3\n\n");
            scanf("%d", &i);
            switch(i){
                case 1:
                    printf("choix 1 du sous menu 2\n\n");
                    break;
                case 2:
                    printf("choix 2 du sous menu 2\n\n");
                    break;
                case 3:
                    printf("choix 3 du sous menu 2 \n\n");
                    break;
                default:
                    printf("Vous n'avez pas rentre un nombre correct.\n\n");
                    break;
            }
            break;
        case 3:
            printf("Vous avez choisi le troisieme choix\n\n");
            printf("Quel est votre choix?taper 1, 2 ou 3\n\n");
            scanf("%d", &i);
            switch(i){
                case 1:
                    printf("choix 1 du sous menu 3\n\n");
                    break;
                case 2:
                    printf("choix 2 du sous menu 3\n\n");
                    break;
                case 3:
                    printf("choix 3 du sous menu 3 \n\n");
                    break;
                default:
                    printf("Vous n'avez pas rentre un nombre correct.\n\n");
                    break;
            }
            break;
        default:
            printf("Vous n'avez pas rentre un nombre correct.\n\n");
            break;

    }
    printf("\n\n");
}

int menuChoixSalle(char* choix1, char* choix2, char* choix3, char* choix4) {
    printf("swag !");
}
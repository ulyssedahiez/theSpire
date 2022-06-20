//
// Created by charles on 18/06/22.
//

#include "Menu/Headers/Affichages.h"
void afficherMap(p_map map, p_salle salleJoueur) {
    p_salle salleActuelle = map->premiereSalle->salleGauche;
    int nbLigneSalle = 0;
    int couloir = 1;
    bool deuxiemeSalle = true;
    do {

        if(deuxiemeSalle == true){
            if (salleActuelle == salleJoueur) {
                printf("    [*]");
            }else{
                printf("    [ ]");
            }
            deuxiemeSalle = false;
        }
        else if (salleActuelle == salleJoueur) {
            printf(" [*]");
        }else{
            printf(" [ ]");
        }

        if(nbLigneSalle == 2) {

        }


         if (salleActuelle->salleMilieu == map->derniereSalle) {
            printf("\n");
            deuxiemeSalle = true;
            nbLigneSalle++;
            if(nbLigneSalle == 2){
                if (salleJoueur == map->premiereSalle) {
                    printf("[*]                                     [ ]\n");
                } else if (salleJoueur == map->derniereSalle) {
                    printf("[ ]                                     [*]\n");
                }else {
                    printf("[ ]                                     [ ]\n");
                }
            }

            if (couloir == 1) {
                salleActuelle = map->premiereSalle->salleMilieuGauche;
            } else if (couloir == 2) {
                salleActuelle = map->premiereSalle->salleMilieuDroite;
            } else if (couloir == 3) {
                salleActuelle = map->premiereSalle->salleDroite;
            } else {
                break;
            }
            couloir++;

        } else {
            salleActuelle = salleActuelle->salleMilieu;
        }
    } while (true);
}

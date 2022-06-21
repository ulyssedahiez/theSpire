//
// Created by charles on 18/06/22.
//

#include "Headers/Affichages.h"
#include "stdio.h"
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
                if (salleJoueur == NULL) {
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


void afficherAttaque(p_attaque attaque, int offset) {
    afficherListeEffets(attaque->listeEffets, offset);
}

void afficherCarte(p_carte carte, int offset, int num) {
    afficherNChar(' ', offset);
    printf("(%i) Carte %s\n",num, carte->nom);
    afficherNChar(' ', 5);
    afficherListeEffets(carte->listeEffets, 5);
    printf("\n");
    afficherNChar(' ', 10);
    printf("Cout en mana : %d\n", carte->pointsMana);
    afficherNChar(' ', 10);
    printf("Cout en energie : %d\n", carte->pointsEnergie);

}

void afficherListeCartes(p_listeCartes listeCartes, int offset) {
    p_carteChainable carteChainable = listeCartes->premiereCarte;
    int count = 1;
    while (carteChainable != NULL) {
        afficherCarte(carteChainable->carte, offset, count);
        carteChainable = carteChainable->carteSuivante;
        count+=1;
    }
}

void afficherNChar(char character, int nFois) {
    for (int i = 0; i < nFois; ++i) {
        printf("%c", character);
    }
}

void afficherListeEffets(p_listeEffets listeEffets, int offset) {
    p_effetChainable effetChainable = listeEffets->premiereEffet;
    afficherNChar(' ', offset);
    while (effetChainable != NULL) {
        afficherEffet(effetChainable->effet, 0);
        if (effetChainable->effetSuivant != NULL) {
            printf(", ");
        }
        effetChainable = effetChainable->effetSuivant;
    }
}

void afficherEffet(p_effet effet, int offset) {
    afficherNChar(' ', offset);
    printf("%s (%d)", effet->nom, effet->valeur);
}
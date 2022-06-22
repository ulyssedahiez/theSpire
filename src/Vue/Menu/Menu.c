//
// Created by Ulysse Dahiez on 08/06/2022.
//

#include "Headers/Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../Controllers/Headers/PartieController.h"

int lancerMenu(bool debug) {


    int choix;
    printf("\n");
    printf("      _____ _          ___      _         \n     |_   _| |_  ___  / __|_ __(_)_ _ ___ \n       | | | ' \\/ -_) \\__ \\ '_ \\ | '_/ -_)\n       |_| |_||_\\___| |___/ .__/_|_| \\___|\n                            |_|             \n");
    printf("\n");
    printf("Bienvenue dans the Spire, veuillez selectionner un numero.");
    printf("\n\n");
    printf("1) Lancer une partie\n2) Regles du jeu\n3) Credit\n4) Quitter\n");
    printf("\n\n");
    printf("Quel est votre choix ? \n\n");
    scanf("%d", &choix);

    printf("\n");
    switch (choix)
    {
        case 1:
            processusPartie(debug);
            return lancerMenu(debug);
        case 2:
            regles();
            return lancerMenu(debug);
        case 3:
            credit();
            return lancerMenu(debug);
        case 4:
            printf("\nBye Bye !\n");
            return 0;
        default:
            printf("Vous n'avez pas rentre un nombre correct.\n\n");
            return lancerMenu(debug);


    }
    printf("\n\n");
}

int menuChoixSalle(char* choix1, char* choix2, char* choix3, char* choix4) {
    printf("Choisissez la prochaine salle !\n");
    printf("1 - %s\n2 - %s\n3 - %s\n4 - %s\n>>>", choix1, choix2, choix3, choix4);
    int choix;
    scanf("%d", &choix);
    if (choix != 1 && choix != 2 && choix != 3 && choix != 4) {
        printf("%d est impossible, recommencer\n", choix);
        return menuChoixSalle(choix1, choix2, choix3, choix4);
    }
    return choix;
}

int menuChoixCarteMain(p_listeCartes listeCartes) {
    printf("Il est temps de choisir les cartes à jouer ! Voici celles que Peter a en main :\n");
    p_carteChainable carteChainable = listeCartes->premiereCarte;
    int choix = 1;
    int choixRetour;
    afficherListeCartes(listeCartes, 0);
    printf("0 - Quitter la selection\n");
    while (carteChainable != NULL) {
        printf("%d - %s\n", choix, carteChainable->carte->nom);

        choix++;
        carteChainable = carteChainable->carteSuivante;
    }
    printf(">>>");
    scanf("%d", &choixRetour);


    return choixRetour;
}

int regles(){
    int choix;//(char*) calloc(50, sizeof(char));//'r';

    printf("Bienvenue dans THE SPIRE.\n\n");
    printf("Le jeu de carte pour les aventuriers.\n\n");
    printf("Dans ce jeu vous allez devoir avancer dans les salles de cet immense temple.\n\n");
    printf("Dans ce temple, il y auras des monstres à combattre, des sanctuaires et des événements aléatoires.\n\n");
    printf("Lorsque vous vous trouverez dans une salle événement, vous aller devoir effectuer un choix.\n\n");
    printf("Si vous vous trouvez dans une salle sanctuaire, vous aller devoir choisir entre méditer ou dormir.\n\n");
    printf("Attention une fois arriver dans la dernière salle, vous allez devoir vous battre contre un Boss de fin.\n\n");
    printf("Vous pourrez durant votre aventure, vous alimenter, ou utiliser divers objet, qui vous donnera ou non des buff.\n\n");

    printf("Bonne chance aventurier !\n\n");




    printf("\ntapez 0 pour revenir au menu\n");
    scanf("%d", &choix);
    if(choix == 0){
        return 0;
    }else{
        return credit();
    }
    return 0;
}

int credit() {
    int choix;//(char*) calloc(50, sizeof(char));//'r';

    printf("Developped by Cod@net\n\nTeam :\n\n\tCodeur Informatique : Julien Lecat.\n\tManager des Fichiers : Mael Bizot.\n\tInventeur Informatique : Charles Chaudron.\n\tResponsable Indentation : Ulysse Dahiez.\n\n\nversion 0.0.1 Jun 2022.\n");
    printf("\ntapez 0 pour revenir au menu\n");
    scanf("%d", &choix);
    if (choix == 0) {
        return 0;
    } else {
        return credit();
    }
    return 0;

}




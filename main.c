//
// Created by charles on 11/05/22.
//

#include "src/Vue/Menu/Headers/Menu.h"
#include "src/Services/Headers/JoueurService.h"

int main(/*int argc, char *argv[]*/) {
    p_joueur joueur = creerJoueur();
    verifierProprietesJoueur(joueur, 2, 'e', 'v');
    //lancerMenu();
}

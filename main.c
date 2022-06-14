//
// Created by charles on 11/05/22.
//

#include "src/Vue/Menu/Headers/Menu.h"
#include "src/Services/Headers/JoueurService.h"
#include "src/Controllers/Headers/Partie.h"
#include "src/Model/Headers/Map.h"

int main(/*int argc, char *argv[]*/) {

    processusPartie();
    lancerMenu();
    creerMap();

    p_joueur joueur = creerJoueur();
    verifierProprietesJoueur(joueur, 2, 'e', 'v');
    //lancerMenu();
}

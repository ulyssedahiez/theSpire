//
// Created by charles on 11/05/22.
//

#include "src/Vue/Menu/Headers/Menu.h"
#include "src/Services/Headers/JoueurService.h"
#include "src/Services/Headers/UtilsService.h"
#include "src/Controllers/Headers/Partie.h"
#include "src/Model/Headers/Map.h"
#include "time.h"

int main(/*int argc, char *argv[]*/) {
    srand(time(NULL));

    processusPartie();
    //lancerMenu();
    //creerMap();

    p_joueur joueur = creerJoueur();
    corrigerProprietesJoueur(joueur, 2, 'e', 'v');
    //lancerMenu();
}

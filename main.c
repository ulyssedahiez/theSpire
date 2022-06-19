//
// Created by charles on 11/05/22.
//

#include "src/Vue/Menu/Headers/Menu.h"
#include "src/Services/Headers/JoueurService.h"
#include "src/Services/Headers/UtilsService.h"
#include "src/Controllers/Headers/PartieController.h"

#include "src/Model/Headers/Salle.h"
#include "time.h"
#include "src/Vue/Menu/Headers/Affichages.h"
int main(/*int argc, char *argv[]*/) {
    srand(time(NULL));
    p_map map = creerMap();
    p_salle salle = creerSalle();
    //afficherMap(map, salle);


    processusPartie();
    //lancerMenu();
    //creerMap();

    p_joueur joueur = creerJoueur();
    corrigerProprietesJoueur(joueur, 2, 'e', 'v');
    //lancerMenu();
}

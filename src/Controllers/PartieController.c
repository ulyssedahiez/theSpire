//
// Created by charles on 30/05/22.
//

#include <sys/time.h>
#include "Headers/PartieController.h"
#include "Map.h"
#include <time.h>
#include <stdlib.h>
#include "../Vue/Menu//Headers/Affichages.h"
void processusPartie(bool debug)
{
    p_joueur peter = creerJoueur();

    p_map map = creerMap();
    remplirMap(map);

    if (debug == true) {
        debugMap(map, NULL);
    } else {
        afficherMap(map, NULL);
    }

    p_salle salleActuelle = choisirPremiereSalle(map->premiereSalle);

    p_listeCartes cartesBasiques = genererListeCartesBasiques();
    p_listeCartes cartesCommunes = genererListeCartesCommunes();
    p_listeCartes cartesAtypiques = genererListeCartesAtypiques();
    p_listeCartes cartesRares = genererListeCartesRares();

    p_listeObjets listeObjetsPossedables = genererObjets();
    ajouterObjetListe(peter->listeObjets, trouverPointeurObjet(listeObjetsPossedables, "Casse-croute"));


    bool defaite = false;
    bool victoire = false;

    p_donneesCombat donneesRound = creerDonneesCombat();
    donneesRound->carteBasique = cartesBasiques;
    donneesRound->joueur = peter;
    donneesRound->map = map;

    initialiserDeckPrincipal(peter->deckPrincipal, cartesBasiques, cartesRares);

    while (true != defaite && true != victoire) {

        if (debug == true) {
            debugMap(map, salleActuelle);
        } else {
            afficherMap(map, salleActuelle);
        }

        if (NULL != salleActuelle->monstre) {
            printf("Salle actuelle : %s\n", salleActuelle->monstre->nom);
            donneesRound->salleActuelle = salleActuelle;
            if (debug == true) {
                printf("DEBUG : Processus de combat\n");
            }
            jouerCombat(donneesRound, debug);
            if (debug == true) {
                if (salleActuelle == map->derniereSalle->salleMilieu) {
                    victoire = true;
                    exit(1);
                    break;
                }
            }
        } else if (NULL != salleActuelle->event) {
            printf("Salle actuelle : Event%d\n", salleActuelle->event->id);
            if (debug == true) {
                printf("DEBUG : Processus d'event");
            } else {
                donneesRound->salleActuelle =salleActuelle;
                jouerEvent(creerListeMiniBosses(), donneesRound, debug);
            }
        } else {
            if (donneesRound->salleActuelle != map->derniereSalle) {
                printf("Salle actuelle : Sanctuaire\n");
                jouerSanctuaire(peter);
            }

        }
        defaite = verifierDefaite(peter);
        victoire = verifierVictoire(donneesRound->salleActuelle);

        if (defaite != true && victoire != true) {
            if (debug == true) {
                debugMap(map, salleActuelle);
            } else {
                printf("Salle remportée !!");
                afficherMap(map, donneesRound->salleActuelle);
            }
            salleActuelle = choisirSalleSuivante(map, salleActuelle);
        }
    }

    if (true == defaite) {
        printf("Perdu !");
    } else if (true == victoire) {
        printf("Bravo, gagné !");
    }
}

bool verifierDefaite(p_joueur joueur) {
    if (0 == joueur->pointsVieActuels) {
        return true;
    }
    return false;
}

bool verifierVictoire(p_salle salleActuelle) {
    if (NULL == salleActuelle->salleGauche && NULL == salleActuelle->salleMilieu &&
        NULL == salleActuelle->salleDroite) {
        return true;
    }
    return false;
}

p_salle choisirPremiereSalle(p_salleDebut salleActuelle) {
    int choix = menuChoixSalle("Gauche", "Milieu gauche", "Milieu droite", "Droite");

    p_salle salleSuivante = NULL;
    if (1 == choix) {
        salleSuivante = salleActuelle->salleGauche;
    } else if (2 == choix) {
        salleSuivante = salleActuelle->salleMilieuGauche;
    } else if (3 == choix) {
        salleSuivante = salleActuelle->salleMilieuDroite;
    } else if (4 == choix) {
        salleSuivante = salleActuelle->salleDroite;
    }

    return salleSuivante;
}

p_salle choisirSalleSuivante(p_map map, p_salle salleActuelle) {
    char *choix1 = "";
    char *choix2 = "";
    char *choix3 = "";

    if (NULL != salleActuelle->salleGauche) {
        choix1 = "Gauche";
    }
    if (NULL != salleActuelle->salleMilieu) {
        choix2 = "Milieu";
    }
    if (NULL != salleActuelle->salleDroite) {
        choix3 = "Droite";
    }

    int choix = menuChoixSalle(choix1, choix2, choix3, "");

    p_salle salleSuivante = NULL;
    if (1 == choix && NULL != salleActuelle->salleGauche) {
        salleSuivante = salleActuelle->salleGauche;
    } else if (2 == choix && NULL != salleActuelle->salleMilieu) {
        salleSuivante = salleActuelle->salleMilieu;
    } else if (3 == choix && NULL != salleActuelle->salleDroite) {
        salleSuivante = salleActuelle->salleDroite;
    } else {
        printf("Ce choix est impossible, recommencez\n");
        return choisirSalleSuivante(map, salleActuelle);
    }

    return salleSuivante;
}

void deplacementSalleAleatoire(p_donneesCombat donneesRound) {
    int monCouloir = genererEntier(0, 5);
    p_salle salleDestination;
    if (1 == monCouloir) {
        salleDestination = donneesRound->map->premiereSalle->salleGauche;
    } else if (2 == monCouloir) {
        salleDestination = donneesRound->map->premiereSalle->salleMilieuGauche;
    } else if (3 == monCouloir) {
        salleDestination = donneesRound->map->premiereSalle->salleMilieuDroite;
    } else if (4 == monCouloir) {
        salleDestination = donneesRound->map->premiereSalle->salleDroite;
    }
}

void tranformerStrikeEnEsquive(p_donneesCombat donneesRound) {
    p_carteChainable carteChainableActuelle = donneesRound->cartesAJouer->premiereCarte;

    while (carteChainableActuelle != NULL) {
        if (carteChainableActuelle->carte->nom == "Strike") {
            carteChainableActuelle->carte = trouverPointeurCarte(donneesRound->carteBasique, "Esquive");
        } else if (carteChainableActuelle->carte->nom == "") {

        }
        carteChainableActuelle = carteChainableActuelle->carteSuivante;
    }
}

void tranformerEsquiveEnStrike(p_donneesCombat donneesRound) {
    p_carteChainable carteChainableActuelle = donneesRound->cartesAJouer->premiereCarte;

    while (carteChainableActuelle != NULL) {
        if (carteChainableActuelle->carte->nom == "Esquive") {
            carteChainableActuelle->carte = trouverPointeurCarte(donneesRound->carteBasique, "Strike");
        } else if (carteChainableActuelle->carte->nom == "") {

        }

        carteChainableActuelle = carteChainableActuelle->carteSuivante;
    }
}

void jouerEvent(p_listeMonstres miniBosses, p_donneesCombat donneesRound, bool debug) {
    if (debug == true) {
        if (donneesRound->salleActuelle->event->id != 4 && donneesRound->salleActuelle->event->id != 1) {
            printf("DEBUG : Event en cours de développement");
            return;
        }
    }
    printf("Bonjour voyageur ! Deux choix vont vous être confronté. À vous de faire le bon choix ! \n");
    int rock=0;
    do {
        if (donneesRound->salleActuelle->event->id == 1) {
            printf("%s", donneesRound->salleActuelle->event->description);
            printf("Choix A : %s \n Choix B : %s", donneesRound->salleActuelle->event->choixA, donneesRound->salleActuelle->event->choixB);
            printf("Faites votre choix mon ami ! (Taper 1 pour selectionner le choix A et 2 pour sélectionner le choix B)\n");
            scanf("%i", &rock);
            if (rock == 1) {
                printf("Vous venez de lancer le combat avec ce monstre ! Quel courage, Bonne chance aventurier ! \n");
                donneesRound->salleActuelle->monstre = trouverPointeurNiemeMonstre(miniBosses, genererEntier(0,
                                                                                                             miniBosses->nombreMonstres));
                jouerCombat(donneesRound, false);

            } else if (rock == 2) {
                printf("Très bien aventurier, vous décider de passer ce MiniBoss ! \n");
            }
        } else if (donneesRound->salleActuelle->event->id == 2) {
            printf("%s", donneesRound->salleActuelle->event->description);
            printf("Choix A : %s \n Choix B : %s", donneesRound->salleActuelle->event->choixA, donneesRound->salleActuelle->event->choixB);
            printf("Faites votre choix mon ami ! (Taper 1 pour selectionner le choix A et 2 pour sélectionner le choix B)\n");
            scanf("%i", &rock);
            if (rock == 1) {
                printf("Vous aller être téléporter dans une autre salle aventurier ! \n");
                //TODO : Mettre la fonciton pour se téléporter dans des salles adjacente.
            } else if (rock == 2) {
                printf("Vous avez décidé de dépenser 10 points de vie. En échange, vous pouvez aller ou vous le désirez. \n");
                donneesRound->joueur->pointsVieActuels -= 10;
                corrigerProprietesJoueur(donneesRound->joueur, 1, 'v');
            }
        } else if (donneesRound->salleActuelle->event->id == 3) {
            printf("%s", donneesRound->salleActuelle->event->description);
            printf("Choix A : %s \n Choix B : %s", donneesRound->salleActuelle->event->choixA, donneesRound->salleActuelle->event->choixB);
            printf("Faites votre choix mon ami ! (Taper 1 pour selectionner le choix A et 2 pour sélectionner le choix B)\n");
            scanf("%i", &rock);
            if (rock == 1) {
                printf("Toutes vos strikes sont changé en esquive !  \n");
                tranformerStrikeEnEsquive(donneesRound);
            } else if (rock == 2) {
                printf("Toutes vos esquives sont changé en strike ! \n");
                tranformerEsquiveEnStrike(donneesRound);
            }
        } else if (donneesRound->salleActuelle->event->id == 4) {
            printf("%s", donneesRound->salleActuelle->event->description);
            printf("Choix A : %s \n Choix B : %s", donneesRound->salleActuelle->event->choixA, donneesRound->salleActuelle->event->choixB);
            printf("Faites votre choix mon ami ! (Taper 1 pour selectionner le choix A et 2 pour sélectionner le choix B)\n");
            scanf("%i", &rock);
            if (rock == 1) {
                printf("Une potion de santé ? Très bon choix ! \n");
                donneesRound->joueur->pointsVieActuels += 10;
                corrigerProprietesJoueur(donneesRound->joueur, 1, 'v');
            } else if (rock == 2) {
                printf("Une potion de mana ? Très bon choix ! \n");
                donneesRound->joueur->pointsManaActuels += 10;
                corrigerProprietesJoueur(donneesRound->joueur, 1, 'm');
            }
        }
    } while (rock != 1 && rock != 2);
}

void jouerSanctuaire(p_joueur joueur) {
    printf("Peter arrive dans un sanctuaire, deux choix s'offrent à lui,  faire dormir Peter pour\n"
           "lui faire regagner la moitié de ses Hp max, ou de faire méditer Peter afin d’avoir la possibilité de\n"
           "retirer définitivement une carte du deck principal.\n");
    printf("Choisissez !\n");
    printf("1 - Dormir\n2 - Méditer\n>>>");
    int choix;
    scanf("%d", &choix);
    if (choix == 1) {
        joueur->pointsVieActuels = floor(joueur->pointsVieActuels += joueur->pointsVieMax / 2);
        corrigerProprietesJoueur(joueur, 1, 'v');
        printf("ZZzzz Peter a bien dormi, il a regagné la moitié de ses PV max.\n");
    } else if (choix == 2) {
        afficherListeCartes(joueur->deckPrincipal, 0);
        printf("Choisissez une carte à supprimer !\n>>>");
        int choixCarte;
        scanf("%d", &choixCarte);
        p_carteChainable carteChainable = joueur->deckPrincipal->premiereCarte;
        int choixCarteSauv = 0;
        for (int i = 0; i < choixCarte - 1; i++) {
            carteChainable = carteChainable->carteSuivante;
            choixCarteSauv = i;
        }
        printf("Hhmmm Peter a bien médité,  cette carte a été retiré du deck.\n\n");
        afficherCarte(carteChainable->carte, 1, choixCarteSauv);
        enleverCarteListe(joueur->deckPrincipal, carteChainable->carte);


    } else {
        printf("%d est impossible, recommencer\n", choix);
        jouerSanctuaire(joueur);
    }


}

void jouerCombat(p_donneesCombat donneesRound, bool debug) {

    processusCombat(donneesRound, debug);
}


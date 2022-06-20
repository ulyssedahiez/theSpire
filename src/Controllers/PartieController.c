//
// Created by charles on 30/05/22.
//

#include "Headers/PartieController.h"
#include "Map.h"
#include "../Vue/Menu//Headers/Affichages.h"
void processusPartie()
{
    p_joueur peter = creerJoueur();

    p_map map = creerMap();
    remplirMap(map);

    afficherMap(map, map->premiereSalle);

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
    donneesRound->joueur = peter;
    donneesRound->map = map;

    initialiserDeckPrincipal(peter->deckPrincipal, cartesBasiques, cartesRares);

    while (true != defaite && true != victoire) {

        afficherMap(map, salleActuelle);



        if (NULL != salleActuelle->monstre) {
            printf("Salle actuelle : %s\n", salleActuelle->monstre->nom);
            donneesRound->salleActuelle = salleActuelle;
            jouerCombat(donneesRound);
        } else if (NULL != salleActuelle->event) {
            printf("Salle actuelle : Event%d\n", salleActuelle->event->id);
            //jouerEvent(salleActuelle->event, creerListeMiniBosses(), donneesRound);
        } else {
            jouerSanctuaire(peter);
        }

        salleActuelle = choisirSalleSuivante(map, salleActuelle);
        defaite = verifierDefaite(peter);
        victoire = verifierVictoire(salleActuelle);
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
    if (NULL == salleActuelle->salleGauche && NULL == salleActuelle->salleMilieu && NULL == salleActuelle->salleDroite) {
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
    char* choix1 = "";
    char* choix2 = "";
    char* choix3 = "";

    if (NULL != salleActuelle->salleGauche) {
        choix1 = "Gauche";
    }
    if (NULL != salleActuelle->salleMilieu) {
        choix2 = "Milieu";
    }
    if (NULL != salleActuelle->salleDroite) {
        choix3 = "Droite";
    }

    int choix = menuChoixSalle(choix1, choix2, choix3,"");

    p_salle salleSuivante = NULL;
    if (1 == choix && NULL != salleActuelle->salleGauche) {
        salleSuivante = salleActuelle->salleGauche;
    } else if (2 == choix && NULL != salleActuelle->salleMilieu)
    {
        salleSuivante = salleActuelle->salleMilieu;
    } else if (3 == choix && NULL != salleActuelle->salleDroite) {
        salleSuivante = salleActuelle->salleDroite;
    } else {
        printf("Ce choix est impossible, recommencez\n");
        return choisirSalleSuivante(map, salleActuelle);
    }

    return salleSuivante;
}

void jouerEvent(p_event event, p_listeMonstres miniBosses, p_donneesCombat donneesRound) {

}

void jouerSanctuaire(p_joueur joueur) {
    printf("Peter arrive dans un sanctuaire, deux choix s'offrent à lui,  faire dormir Peter pour\n"
           "lui faire regagner la moitié de ses Hp max, ou de faire méditer Peter afin d’avoir la possibilité de\n"
           "retirer définitivement une carte du deck principal.\n");
    printf("Choisissez !\n");
    printf("1 - Dormir\n2 - Méditer\n>>>");
    int choix;
    scanf("%d", &choix);
     if(choix == 1){
        joueur->pointsVieActuels = floor(joueur->pointsVieActuels+=joueur->pointsVieMax/2);

        printf("ZZzzz Peter a bien dormi, ses HP on été multiplié par deux.\n");
    }else if(choix == 2){
         afficherListeCartes(joueur->deckPrincipal, 0);
         printf("Choisissez une carte à supprimer !\n>>>");
         int choixCarte;
         scanf("%d", &choixCarte);
         p_carteChainable carteChainable = joueur->deckPrincipal->premiereCarte;
         int choixCarteSauv=0;
         for (int i=0;i<choixCarte-1; i++){
             carteChainable = carteChainable->carteSuivante;
             choixCarteSauv =i;
         }
         printf("Hhmmm Peter a bien médité,  cette carte a été retiré du deck.\pn\n");
         afficherCarte(carteChainable->carte, 1, choixCarteSauv);
         enleverCarteListe(joueur->deckPrincipal,carteChainable->carte);



    }else{
        printf("%d est impossible, recommencer\n", choix);
        jouerSanctuaire(joueur);
    }


}

void jouerCombat(p_donneesCombat donneesRound) {

    processusCombat(donneesRound);
}


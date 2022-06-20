//
// Created by charles on 30/05/22.
//

#include <sys/time.h>
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
void deplacementSalleAleatoire(p_donneesCombat donneesRound) {
    int monCouloir = genererEntier(0,5);
    p_salle salleDestination;
    if (1 == monCouloir) {
        salleDestination = donneesRound->map->premiereSalle->salleGauche;
    } else if (2 == monCouloir )
    {
        salleDestination = donneesRound->map->premiereSalle->salleMilieuGauche;
    } else if (3 == monCouloir) {
        salleDestination = donneesRound->map->premiereSalle->salleMilieuDroite;
    }else if (4 == monCouloir){
        salleDestination = donneesRound->map->premiereSalle->salleDroite;
    }
}

void tranformerStrikeEnEsquive(p_donneesCombat donneesRound){
    p_carteChainable carteChainableActuelle = donneesRound->cartesAJouer->premiereCarte;

    while (carteChainableActuelle != NULL) {
        if (carteChainableActuelle->carte->nom == "Strike") {
            carteChainableActuelle->carte = trouverPointeurCarte(donneesRound->carteBasique, "Esquive");
            } else if (carteChainableActuelle->carte->nom == "") {

        }
        carteChainableActuelle = carteChainableActuelle->carteSuivante;
    }
}

void tranformerEsquiveEnStrike(p_donneesCombat donneesRound){
    p_carteChainable carteChainableActuelle = donneesRound->cartesAJouer->premiereCarte;

    while (carteChainableActuelle != NULL) {
        if (carteChainableActuelle->carte->nom == "Esquive") {
            carteChainableActuelle->carte = trouverPointeurCarte(donneesRound->carteBasique, "Strike");
        } else if (carteChainableActuelle->carte->nom == "") {

        }

        carteChainableActuelle = carteChainableActuelle->carteSuivante;
    }
}
void jouerEvent(p_event event, p_listeMonstres miniBosses, p_donneesCombat donneesRound,p_map map, p_salle salleActuelle) {

    struct s_event *eventDeLaSalle = donneesRound->salleActuelle->event;
    printf("Bonjour voyageur ! Deux choix vont vous être confronté. À vous de faire le bon choix ! \n");
    char choixJoueur;

    if(eventDeLaSalle->id == 1){
        printf("%s", eventDeLaSalle->description);
        printf("%s \n %s",eventDeLaSalle->choixA, eventDeLaSalle->choixB);
        printf("Faites votre choix mon ami ! (Taper A pour selectionner le choix A et B pour sélectionner le choix B)\n");
        scanf("%c",choixJoueur);
        if (choixJoueur == 'A'){
            printf("Vous venez de lancer le combat avec ce monstre ! Quel courage, Bonne chance aventurier ! \n");
            jouerCombat(donneesRound);

        } else if (choixJoueur == 'B'){
            printf("Très bien aventurier, vous décider de passer ce MiniBoss ! \n");
            choisirSalleSuivante(map, salleActuelle);
        }
    }
    else if (eventDeLaSalle->id == 2){
        printf("%s", eventDeLaSalle->description);
        printf("%s \n %s",eventDeLaSalle->choixA, eventDeLaSalle->choixB);
        printf("Faites votre choix mon ami ! (Taper A pour selectionner le choix A et B pour sélectionner le choix B)\n");
        scanf("%c",choixJoueur);
        if (choixJoueur == 'A'){
            printf("Vous aller être téléporter dans une autre salle aventurier ! \n");
            //TODO : Mettre la fonciton pour se téléporter dans des salles adjacente.
        } else if (choixJoueur == 'B'){
            printf("Vous avez décidé de dépenser 10 points de vie. En échange, vous pouvez aller ou vous le désirez. \n");
            choisirSalleSuivante(map, salleActuelle);
        }
    }
    else if (eventDeLaSalle->id == 3){
        printf("%s", eventDeLaSalle->description);
        printf("%s \n %s",eventDeLaSalle->choixA, eventDeLaSalle->choixB);
        printf("Faites votre choix mon ami ! (Taper A pour selectionner le choix A et B pour sélectionner le choix B)\n");
        scanf("%c",choixJoueur);
        if (choixJoueur == 'A'){
            printf("Toutes vos strikes sont changé en esquive !  \n");
            tranformerStrikeEnEsquive(donneesRound);
        } else if (choixJoueur == 'B'){
            printf("Toutes vos esquives sont changé en strike ! \n");
            tranformerEsquiveEnStrike(donneesRound);
        }
    } else if (eventDeLaSalle->id == 4){
        printf("%s", eventDeLaSalle->description);
        printf("%s \n %s",eventDeLaSalle->choixA, eventDeLaSalle->choixB);
        printf("Faites votre choix mon ami ! (Taper A pour selectionner le choix A et B pour sélectionner le choix B)\n");
        scanf("%c",choixJoueur);
        if (choixJoueur == 'A'){
            printf("Une potion de santé ? Très bon choix ! \n");
            donneesRound->joueur->pointsVieActuels += 10;
        } else if (choixJoueur == 'B'){
            printf("Une potion de mana ? Très bon choix ! \n");
            donneesRound->joueur->pointsManaActuels += 10;
        }
    }
}

void jouerSanctuaire(p_joueur joueur) {
    printf("Peter arrive dans un sanctuaire, il regagne ses points de vie au maximum.\n");
    joueur->pointsVieActuels = joueur->pointsVieMax;
}

void jouerCombat(p_donneesCombat donneesRound) {

    processusCombat(donneesRound);
}


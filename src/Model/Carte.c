//
// Created by charles on 11/05/22.
//
#include "Headers/Carte.h"

p_carte creerCarte(char *nomCarte, char *rareteCarte, int coutEnergie, int coutMana, p_listeEffets listeEffetsCarte, char *texteTechniqueCarte, char *texteDescriptionCarte) {
    p_carte carte = malloc(sizeof(t_carte));
    carte->nom = nomCarte;
    carte->rarete = rareteCarte;
    carte->pointsEnergie = coutEnergie;
    carte->pointsMana = coutMana;
    carte->listeEffets = listeEffetsCarte;
    carte->texteDescription = texteDescriptionCarte;
    carte->texteTechnique = texteTechniqueCarte;

    return carte;
}

p_listeCartes creerListeCartes() {
    p_listeCartes listeCartes = malloc(sizeof(t_listeCartes));
    listeCartes->nombreCartes = 0;
    listeCartes->premiereCarte = NULL;

    return listeCartes;
}

void ajouterCarteListe(p_listeCartes listeCartes, p_carte carte) {
    p_carteChainable carteChainableAAjouter = creerCarteChainable(carte);
    if (0 == listeCartes->nombreCartes) {
        listeCartes->premiereCarte = carteChainableAAjouter;
    } else {
        p_carteChainable carteChainableActuelle = listeCartes->premiereCarte;
        while (NULL != carteChainableActuelle->carteSuivante) {
            carteChainableActuelle = carteChainableActuelle->carteSuivante;
        }
        carteChainableActuelle->carteSuivante = carteChainableAAjouter;
    }
    listeCartes->nombreCartes += 1;
}

/** retourne true si supprimée, false si non présente dans la liste */
bool enleverCarteListe(p_listeCartes listeCartes, p_carte carte) {
    if (carte == listeCartes->premiereCarte->carte) {
        p_carteChainable aSupprimer = listeCartes->premiereCarte;
        listeCartes->premiereCarte = listeCartes->premiereCarte->carteSuivante;
        supprimerCarteChainable(aSupprimer);
        listeCartes->nombreCartes -= 1;

        return true;
    } else {
        p_carteChainable carteChainableActuelle = listeCartes->premiereCarte;
        while (carte != carteChainableActuelle->carte || NULL != carteChainableActuelle->carteSuivante) {
            carteChainableActuelle = carteChainableActuelle->carteSuivante;
        }
        if (carte == carteChainableActuelle->carte) {
            supprimerCarteChainable(carteChainableActuelle);
            listeCartes->nombreCartes -= 1;

            return true;
        }
    }
    return false;
}

void supprimerCarteChainable(p_carteChainable carteChainable) {
    free(carteChainable); // on ne supprime pas la p_carte à l'intérieur, elle peut avoir été utilisée autre part (déplacée du deck par exemple)
}

p_carteChainable creerCarteChainable(p_carte carte) {
    p_carteChainable carteChainable = malloc(sizeof(t_carteChainable));

    carteChainable->carte = carte;
    carteChainable->carteSuivante = NULL;

    return carteChainable;
}


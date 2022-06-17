//
// Created by charles on 16/06/22.
//

#include "Headers/MonstreService.h"
#include "stdio.h"

p_listeMonstres creerListeMonstresEtage1A4() {
    /* Génération monstres etage 1 à 4 */
    p_listeMonstres listeMonstresEtage1A4 = creerListeMonstres();
    /* Jawurm */
    p_listeEffets listeEffetsAttaqueAJawurm = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueAJawurm, creerEffet("Dégâts", true, 11));
    p_listeEffets listeEffetsAttaqueBJawurm = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueBJawurm, creerEffet("Dégâts", true, 7));
    ajouterEffetListe(listeEffetsAttaqueBJawurm, creerEffet("Esquive", false, 5));
    p_listeEffets listeEffetsAttaqueCJawurm = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueCJawurm, creerEffet("Force", false, 3));
    ajouterEffetListe(listeEffetsAttaqueCJawurm, creerEffet("Esquive", false, 6));

    p_listeAttaques listeAttaquesJawurm = creerListeAttaques();
    ajouterAttaqueListe(listeAttaquesJawurm, creerAttaque(listeEffetsAttaqueAJawurm, 33));
    ajouterAttaqueListe(listeAttaquesJawurm, creerAttaque(listeEffetsAttaqueBJawurm, 33));
    ajouterAttaqueListe(listeAttaquesJawurm, creerAttaque(listeEffetsAttaqueCJawurm, 33));
    ajouterMonstreListe(listeMonstresEtage1A4, creerMonstre("Jawurm", 0, listeAttaquesJawurm, 40, 44));

    /* Blouni */
    p_listeEffets listeEffetsAttaqueABlouni = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueABlouni, creerEffet("Dégâts", true, 13));
    p_listeEffets listeEffetsAttaqueBBlouni = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueBBlouni, creerEffet("Dégâts", true, 8));
    ajouterEffetListe(listeEffetsAttaqueBBlouni, creerEffet("Faible", true, 2));

    p_listeAttaques listeAttaquesBlouni = creerListeAttaques();
    ajouterAttaqueListe(listeAttaquesBlouni, creerAttaque(listeEffetsAttaqueABlouni, 50));
    ajouterAttaqueListe(listeAttaquesBlouni, creerAttaque(listeEffetsAttaqueBBlouni, 50));
    ajouterMonstreListe(listeMonstresEtage1A4, creerMonstre("Blouni", 0, listeAttaquesBlouni, 46, 50));

    /* Keliko */
    p_listeEffets listeEffetsAttaqueAKeliko = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueAKeliko, creerEffet("Dégâts", true, 3));
    ajouterEffetListe(listeEffetsAttaqueAKeliko, creerEffet("Force", false, 2));
    p_listeEffets listeEffetsAttaqueBKeliko = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueBKeliko, creerEffet("Dégâts", true, 3));
    ajouterEffetListe(listeEffetsAttaqueBKeliko, creerEffet("Esquive", false, 3));
    ajouterEffetListe(listeEffetsAttaqueBKeliko, creerEffet("Dextérité", false, 2));

    p_listeAttaques listeAttaquesKeliko = creerListeAttaques();
    ajouterAttaqueListe(listeAttaquesKeliko, creerAttaque(listeEffetsAttaqueAKeliko, 50));
    ajouterAttaqueListe(listeAttaquesKeliko, creerAttaque(listeEffetsAttaqueBKeliko, 50));
    ajouterMonstreListe(listeMonstresEtage1A4, creerMonstre("Keliko", 0, listeAttaquesKeliko, 60, 70));

    return listeMonstresEtage1A4;
}

p_listeMonstres creerListeMonstresEtage5A9() {
    /* Génération monstres etage 5 à 9 */
    p_listeMonstres listeMonstresEtage5A9 = creerListeMonstres();
    /* Jawurm2 */
    p_listeEffets listeEffetsAttaqueAJawurm2 = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueAJawurm2, creerEffet("Dégâts", true, 15));
    p_listeEffets listeEffetsAttaqueBJawurm2 = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueBJawurm2, creerEffet("Dégâts", true, 12));
    ajouterEffetListe(listeEffetsAttaqueBJawurm2, creerEffet("Esquive", false, 10));
    p_listeEffets listeEffetsAttaqueCJawurm2 = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueCJawurm2, creerEffet("Force", false, 3));
    ajouterEffetListe(listeEffetsAttaqueCJawurm2, creerEffet("Esquive", false, 18));

    p_listeAttaques listeAttaquesJawurm2 = creerListeAttaques();
    ajouterAttaqueListe(listeAttaquesJawurm2, creerAttaque(listeEffetsAttaqueAJawurm2, 33));
    ajouterAttaqueListe(listeAttaquesJawurm2, creerAttaque(listeEffetsAttaqueBJawurm2, 33));
    ajouterAttaqueListe(listeAttaquesJawurm2, creerAttaque(listeEffetsAttaqueCJawurm2, 33));
    ajouterMonstreListe(listeMonstresEtage5A9, creerMonstre("Jawurm2", 0, listeAttaquesJawurm2, 55, 62));

    /* Redoni */
    p_listeEffets listeEffetsAttaqueARedoni = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueARedoni, creerEffet("Dégâts", true, 20));
    p_listeEffets listeEffetsAttaqueBRedoni = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueBRedoni, creerEffet("Dégâts", true, 15));
    ajouterEffetListe(listeEffetsAttaqueBRedoni, creerEffet("Faible", true, 2));

    p_listeAttaques listeAttaquesRedoni = creerListeAttaques();
    ajouterAttaqueListe(listeAttaquesRedoni, creerAttaque(listeEffetsAttaqueARedoni, 50));
    ajouterAttaqueListe(listeAttaquesRedoni, creerAttaque(listeEffetsAttaqueBRedoni, 50));
    ajouterMonstreListe(listeMonstresEtage5A9, creerMonstre("Redoni", 0, listeAttaquesRedoni, 50, 54));

    /* Mangoustine */
    p_listeEffets listeEffetsAttaqueAMangoustine = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueAMangoustine, creerEffet("Dégâts", true, 3));
    ajouterEffetListe(listeEffetsAttaqueAMangoustine, creerEffet("Esquive", false, 3));
    ajouterEffetListe(listeEffetsAttaqueAMangoustine, creerEffet("Force", false, 2));
    ajouterEffetListe(listeEffetsAttaqueAMangoustine, creerEffet("Dextérité", false, 2));

    p_listeAttaques listeAttaquesMangoustine = creerListeAttaques();
    ajouterAttaqueListe(listeAttaquesMangoustine, creerAttaque(listeEffetsAttaqueAMangoustine, 100));
    ajouterMonstreListe(listeMonstresEtage5A9, creerMonstre("Mangoustine", 0, listeAttaquesMangoustine, 70, 80));

    return listeMonstresEtage5A9;
}

p_listeMonstres creerListeMiniBosses() {
    /* Génération Mini bosses */
    p_listeMonstres miniBosses = creerListeMonstres();
    /* Eldan */
    p_listeEffets listeEffetsAttaqueAEldan = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueAEldan, creerEffet("Dégâts", true, 15));
    p_listeEffets listeEffetsAttaqueBEldan = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueBEldan, creerEffet("Dégâts", true, 10));
    ajouterEffetListe(listeEffetsAttaqueBEldan, creerEffet("Esquive", false, 15));
    p_listeEffets listeEffetsAttaqueCEldan = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueCEldan, creerEffet("Faible", true, 25));
    ajouterEffetListe(listeEffetsAttaqueCEldan, creerEffet("Lenteur", true, 2));
    ajouterEffetListe(listeEffetsAttaqueCEldan, creerEffet("Dextérité", true, -1));

    p_listeAttaques listeAttaquesEldan = creerListeAttaques();
    ajouterAttaqueListe(listeAttaquesEldan, creerAttaque(listeEffetsAttaqueAEldan, 33));
    ajouterAttaqueListe(listeAttaquesEldan, creerAttaque(listeEffetsAttaqueBEldan, 33));
    ajouterAttaqueListe(listeAttaquesEldan, creerAttaque(listeEffetsAttaqueCEldan, 33));
    ajouterMonstreListe(miniBosses, creerMonstre("Eldan", 80, listeAttaquesEldan, 80, 80));

    /* Pyrox */
    p_listeEffets listeEffetsAttaqueAPyrox = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueAPyrox, creerEffet("Feu", true, 5));
    ajouterEffetListe(listeEffetsAttaqueAPyrox, creerEffet("Esquive", false, 10));
    p_listeEffets listeEffetsAttaqueBPyrox = creerListeEffets();
    ajouterEffetListe(listeEffetsAttaqueBPyrox, creerEffet("Feu", true, 10));
    ajouterEffetListe(listeEffetsAttaqueBPyrox, creerEffet("Dextérité", false, 2));

    p_listeAttaques listeAttaquesPyrox = creerListeAttaques();
    ajouterAttaqueListe(listeAttaquesPyrox, creerAttaque(listeEffetsAttaqueAPyrox, 50));
    ajouterAttaqueListe(listeAttaquesPyrox, creerAttaque(listeEffetsAttaqueBPyrox, 50));
    ajouterMonstreListe(miniBosses, creerMonstre("Pyrox", 120, listeAttaquesPyrox, 120, 120));

    return miniBosses;
}

p_monstre creerDernierBoss() {
    /* Dernier Boss */
    p_listeEffets listeEffetsAGardienDeLaPlume = creerListeEffets(); // Comme spectre complet
    ajouterEffetListe(listeEffetsAGardienDeLaPlume, creerEffet("Feu", true, 3));
    ajouterEffetListe(listeEffetsAGardienDeLaPlume, creerEffet("Dégâts", true, 6));
    ajouterEffetListe(listeEffetsAGardienDeLaPlume, creerEffet("Force", false, 1));
    ajouterEffetListe(listeEffetsAGardienDeLaPlume, creerEffet("Lenteur", true, 1));
    ajouterEffetListe(listeEffetsAGardienDeLaPlume, creerEffet("Faible", true, 1));
    ajouterEffetListe(listeEffetsAGardienDeLaPlume, creerEffet("Dextérité", false, 1));
    ajouterEffetListe(listeEffetsAGardienDeLaPlume, creerEffet("Esquive", false, 5));

    p_listeEffets listeEffetsBGardienDeLaPlume = creerListeEffets(); // comme pulvériser
    ajouterEffetListe(listeEffetsBGardienDeLaPlume, creerEffet("Dégâts", true, 30));


    p_listeEffets listeEffetsCGardienDeLaPlume = creerListeEffets();
    ajouterEffetListe(listeEffetsCGardienDeLaPlume, creerEffet("Dégâts", true, 4));
    ajouterEffetListe(listeEffetsCGardienDeLaPlume, creerEffet("Dégâts", true, 4));
    ajouterEffetListe(listeEffetsCGardienDeLaPlume, creerEffet("Dégâts", true, 4));
    ajouterEffetListe(listeEffetsCGardienDeLaPlume, creerEffet("Dégâts", true, 4));
    ajouterEffetListe(listeEffetsCGardienDeLaPlume, creerEffet("Dégâts", true, 4));


    p_listeEffets listeEffetsDGardienDeLaPlume = creerListeEffets();

    p_listeAttaques listeAttaquesDernierBoss = creerListeAttaques();
    ajouterAttaqueListe(listeAttaquesDernierBoss, creerAttaque(listeEffetsAGardienDeLaPlume, 25));
    ajouterAttaqueListe(listeAttaquesDernierBoss, creerAttaque(listeEffetsBGardienDeLaPlume, 25));
    ajouterAttaqueListe(listeAttaquesDernierBoss, creerAttaque(listeEffetsCGardienDeLaPlume, 25));
    ajouterAttaqueListe(listeAttaquesDernierBoss, creerAttaque(listeEffetsDGardienDeLaPlume, 25));
    return creerMonstre("Gardien de la plume", 150, listeAttaquesDernierBoss, 150, 150);
}

void remplirPointsVieMonstre(p_monstre monstre) {
    monstre->pointsVie = genererEntier(monstre->borneInfPointsVie, monstre->borneSupPointsVie);
}
//
// Created by charles on 30/05/22.
//
#include <stdlib.h>
#include "Headers/Map.h"
#include "Headers/Salle.h"
#include "Headers/Event.h"

void creerCouloirSalle(p_salle salleActuelle, p_salle derniereSalle) {
    for (int i = 0; i < 8; ++i) {
        salleActuelle->salleMilieu = creerSalle();
        salleActuelle = salleActuelle->salleMilieu;
    }
    salleActuelle->salleMilieu = derniereSalle;
}

p_salle trouverPointeurNiemeSuivante(p_salle salle, int nCherche) {
    int nActuel = 0;
    while (nActuel < nCherche) {
        salle = salle->salleMilieu;

        nActuel++;
    }
    return salle;
}

int trouverCoordoneesSalle(p_salleDebut salleDebut, p_salle salle) {
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;
    p_salle salle1 = salleDebut->salleGauche;
    p_salle salle2 = salleDebut->salleMilieuGauche;
    p_salle salle3 = salleDebut->salleMilieuDroite;
    p_salle salle4 = salleDebut->salleDroite;
    int trouvee = 0;
    while(trouvee != 1){
        if(salle1->salleMilieu == salle){
            trouvee = 1;
        }else{
            salle1 = salle1->salleMilieu;
            n1++;
        }
        if(salle2->salleMilieu == salle){
            trouvee = 1;
        }else{
            salle2 = salle2->salleMilieu;
            n2++;
        }
        if(salle3->salleMilieu == salle){
            trouvee = 1;
        }else{
            salle3 = salle3->salleMilieu;
            n3++;
        }
        if(salle4->salleDroite == salle){
            trouvee = 1;
        }else{
            salle4 = salle4->salleGauche;
            n4++;
        }
    }
    return n1;
}
p_map creerMap(){
    p_map map = malloc(sizeof(t_map));

    map->premiereSalle = creerSalleDebut();
    map->derniereSalle = creerSalle();
    map->premiereSalle->salleGauche = creerSalle();
    map->premiereSalle->salleMilieuGauche = creerSalle();
    map->premiereSalle->salleMilieuDroite = creerSalle();
    map->premiereSalle->salleDroite = creerSalle();

    p_salle actuelleGauche = map->premiereSalle->salleGauche;
    p_salle premiereGauche = map->premiereSalle->salleGauche;
    p_salle actuelleMilieuGauche = map->premiereSalle->salleMilieuGauche;
    p_salle premiereMilieuGauche = map->premiereSalle->salleMilieuGauche;
    p_salle actuelleMilieuDroite = map->premiereSalle->salleMilieuDroite;
    p_salle premiereMilieuDroite = map->premiereSalle->salleMilieuDroite;
    p_salle actuelleDroite = map->premiereSalle->salleDroite;
    p_salle premiereDroite = map->premiereSalle->salleDroite;

    creerCouloirSalle(actuelleGauche, map->derniereSalle);
    creerCouloirSalle(actuelleMilieuGauche, map->derniereSalle);
    creerCouloirSalle(actuelleMilieuDroite, map->derniereSalle);
    creerCouloirSalle(actuelleDroite,map->derniereSalle);


    for (int i = 0; i < 8; ++i) {
        actuelleGauche->salleDroite = trouverPointeurNiemeSuivante(premiereMilieuGauche, i+1);

        actuelleMilieuGauche->salleGauche = trouverPointeurNiemeSuivante(premiereGauche, i+1);
        actuelleMilieuGauche->salleDroite = trouverPointeurNiemeSuivante(premiereMilieuDroite, i+1);

        actuelleMilieuDroite->salleGauche = trouverPointeurNiemeSuivante(premiereMilieuGauche, i+1);
        actuelleMilieuDroite->salleDroite = trouverPointeurNiemeSuivante(premiereDroite, i+1);

        actuelleDroite->salleGauche = trouverPointeurNiemeSuivante(premiereMilieuDroite, i+1);

        actuelleGauche = actuelleGauche->salleMilieu;
        actuelleMilieuGauche = actuelleMilieuGauche->salleMilieu;
        actuelleMilieuDroite = actuelleMilieuDroite->salleMilieu;
        actuelleDroite = actuelleDroite->salleMilieu;
    }


    return map;
}
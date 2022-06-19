//
// Created by charles on 14/06/22.
//

#ifndef THESPIRE_CARTESSERVICE_H
#define THESPIRE_CARTESSERVICE_H
#include "../../Model/Headers/Carte.h"

p_listeCartes genererListeCartesBasiques();

p_listeCartes genererListeCartesCommunes();

p_listeCartes genererListeCartesAtypiques();

p_listeCartes genererListeCartesRares();

void initialiserDeckPrincipal(p_listeCartes deckPrincipal, p_listeCartes cartesBasiques, p_listeCartes cartesRares);

#endif //THESPIRE_CARTESSERVICE_H

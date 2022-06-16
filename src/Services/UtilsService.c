//
// Created by charles on 16/06/22.
//

#include "Headers/UtilsService.h"

int genererEntier(int borneInf, int borneSup) {
    return (borneInf + (rand()) % (int)(borneSup - borneInf));
}
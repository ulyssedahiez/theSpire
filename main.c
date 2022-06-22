//
// Created by charles on 11/05/22.
//
#include "src/Vue/Menu/Headers/Menu.h"
#include "time.h"



int main(int argc, char *argv[]) {
    srand(time(NULL));
    bool debug = false;
    if (argc != 1) {
        for (int i = 0; i < argc; ++i) {
            if (strcmp(argv[i], "--debug") == 0) {
                debug = true;
            }
        }
    }
    if (debug == true) {
        printf("************ PARTIE LANCéE EN MODE DEBUG ************\n\n");
    }
    lancerMenu(debug);
}

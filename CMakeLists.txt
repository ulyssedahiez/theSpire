cmake_minimum_required(VERSION 3.22)
project(theSpire C)

set(CMAKE_C_STANDARD 11)

include_directories(src/Controllers/Headers)
include_directories(src/Model/Headers)

add_executable(theSpire
        src/Controllers/Headers/Partie.h
        src/Controllers/Partie.c
        src/Model/Headers/Attaque.h
        src/Model/Headers/Carte.h
        src/Model/Headers/Combat.h
        src/Model/Headers/Deck.h
        src/Model/Headers/Effet.h
        src/Model/Headers/Event.h
        src/Model/Headers/Joueur.h
        src/Model/Headers/Map.h
        src/Model/Headers/Monstre.h
        src/Model/Headers/Objet.h
        src/Model/Headers/Salle.h
        src/Model/Attaque.c
        src/Model/Carte.c
        src/Model/Combat.c
        src/Model/Deck.c
        src/Model/Effet.c
        src/Model/Event.c
        src/Model/Joueur.c
        src/Model/Map.c
        src/Model/Monstre.c
        src/Model/Objet.c
        src/Model/Salle.c
        main.c src/Vue/Menu/Menu.c src/Vue/Menu/Headers/Menu.h src/Controllers/Round.c src/Controllers/Headers/Round.h src/Services/JoueurService.c src/Services/Headers/JoueurService.h)

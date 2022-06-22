cmake_minimum_required(VERSION 3.21)
project(theSpire C)

set(CMAKE_C_STANDARD 11)

include_directories(src/Controllers/Headers)
include_directories(src/Model/Headers)

add_executable(theSpire
        src/Controllers/Headers/PartieController.h
        src/Controllers/Headers/CombatController.h
        src/Controllers/PartieController.c
        src/Controllers/CombatController.c
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
        src/Vue/Menu/Headers/Menu.h
        src/Vue/Menu/Menu.c
        src/Services/Headers/JoueurService.h
        src/Services/Headers/CarteService.h
        src/Services/Headers/MonstreService.h
        src/Services/JoueurService.c
        src/Services/CarteService.c
        src/Services/MonstreService.c
        main.c src/Services/UtilsService.c src/Services/Headers/UtilsService.h src/Services/MapService.c src/Services/Headers/MapService.h src/Services/EventService.c src/Services/Headers/EventService.h src/Vue/Menu/Affichages.c src/Vue/Menu/Headers/Affichages.h src/Services/ObjetService.c src/Services/Headers/ObjetService.h src/Services/AttaqueService.c src/Services/Headers/AttaqueService.h)

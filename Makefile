CFLAGS =  -I./src/Controllers/Headers -I./src/Vue/Menu/Headers -I./src/Model/Headers -I./src/Services/Headers -Wall
LIBS = 
NAME = main
ODIR = ./build
OBJ = o

OBJS = PartieController.$(OBJ) \
	CombatController.$(OBJ) \
	Affichages.$(OBJ) \
	Menu.$(OBJ) \
	Carte.$(OBJ) \
	Monstre.$(OBJ) \
	Joueur.$(OBJ) \
	Combat.$(OBJ) \
	Attaque.$(OBJ) \
	Deck.$(OBJ) \
	Salle.$(OBJ) \
	Effet.$(OBJ) \
	Objet.$(OBJ) \
	Event.$(OBJ) \
	Map.$(OBJ) \
	EventService.$(OBJ) \
	AttaqueService.$(OBJ) \
	ObjetService.$(OBJ) \
	MonstreService.$(OBJ) \
	UtilsService.$(OBJ) \
	CarteService.$(OBJ) \
	MapService.$(OBJ) \
	JoueurService.$(OBJ) \
	main.$(OBJ)

OBJECTS = $(patsubst %,$(ODIR)/%,$(OBJS))
VPATH = ./src/Controllers:./src/Vue/Menu:./src/Model:./src/Services

.c.$(OBJ):
	@test -d $(ODIR) || mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c -o $(ODIR)/$@ $< $(LIBS)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $(ODIR)/$(NAME) $(OBJECTS) $(LIBS)
	cp ./build/main theSpire.exe

.PHONY: clean
clean:
	$(RM) $(ODIR)/$(NAME) $(OBJECTS)

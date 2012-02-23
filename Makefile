#
#	Makefile du projet Lilpower
#
#	Propriété de Loïc Dalloz, Alexandre Brand, Jean-Charles Blind, Arthur Declerq, Romain Brewee
#

#listage des executables
SERVER=lilserv
CLIENT=lilclient

#listage des dossiers
SERVERSRC=$(wildcard src/server/*.c)
CLIENTSRC=$(wildcard src/client/*.c)
NETSRC=$(wildcard src/network/*.c)
CRYPTSRC=$(wildcard src/crypt/*.c)

#différentes variables
FLAGS=-wall

#listage des fichiers objets
SERVEROBJ=$(SERVERSRC:.c=.o)
CLIENTOBJ=$(CLIENTSRC:.c=.o)
NETOBJ=$(NETSRC:.c=.o)
CRYPTOBJ=$(CRYPTSRC:.c=.o)


#compilation générale
all: $(SERVER) $(CLIENT) clean
	@echo
	@echo Compilation terminée
	@echo
	@echo

#compilation du serveur
$(SERVER): $(SERVEROBJ) $(NETOBJ) $(CRYPTOBJ)
	@echo
	@echo ======================================
	@echo ====	Linkage du serveur	====
	@echo ======================================
	@echo
	gcc -o $@ $^ $(FLAGS)
	@echo Done.
	@echo
	@€cho

#compilaiton du client
$(CLIENT): $(CLIENTOBJ) $(NETOBJ) $(CRYPTOBJ)
	@echo
	@echo ======================================
	@echo ====	Linkage du client	====
	@echo ======================================
	@echo
	gcc -o $@ $^ $(FLAGS)
	@echo Done.
	@echo
	@echo

#compilation générale
%.o: %.c %.h
	@echo
	@echo compilation de : $<
	gcc -o $@ $< $(FLAGS)
	@echo OK
	@echo

#netoyage du répertoire
clean:
	@echo
	@echo ======================================
	@echo ====	Netoyage du répertoire	====
	@echo ======================================
	@echo
	rm *.o
	rm src/network/*.o
	rm src/client/*.o
	rm src/server/*.o
	rm src/crypt/*.o
	@echo Done.
	@echo
	@echo
	

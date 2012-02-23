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

#différentes variables
FLAGS=-wall


#compilation générale
all: $(SERVER) $(CLIENT) clean
	@echo
	@echo ======================================
	@echo ====	Compilation générale	====
	@echo ======================================
	@echo

#compilation du serveur
$(SERVER):
	@echo
	@echo ======================================
	@echo ====	Compilation du serveur	====
	@echo ======================================
	@echo

#compilaiton du client
$(CLIENT):
	@echo
	@echo ======================================
	@echo ====	Compilation du client	====
	@echo ======================================
	@echo

#netoyage du répertoire
clean:
	@echo
	@echo ======================================
	@echo ====	Netoyage du dossier	====
	@echo ======================================
	@echo

	

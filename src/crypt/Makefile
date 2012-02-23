#
#	Make file de la lib d'en cryptage du projet Lilpower
#
#	Proporiété de Loïc Dalloz, Alexandre Brand, Jean-Charles Blind, Arthur Declerq, Romain Brewee
#


#listage des fichiers
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

#fichier de sortie
EXIT=crypt.o

#flags de compilation
FLAGS=-wall


all: $(EXIT)

#compilation du fichier objet général :
$(EXIT): $(OBJ)
	@echo
	@echo ====	linkage de la lib de cryptage	====
	@echo
	gcc -o $@ -c $^ $(FLAGS)
	@echo linkage terminé
	@echo
	@echo

%.o: %.c %.h
	@echo compilation de $< :
	@echo
	gcc -o $@ -c $< $(FLAGS)
	@echo OK
	@echo


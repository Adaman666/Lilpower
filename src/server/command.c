#include "comand.h"

void command_start()
{
	//ressources
	int quit = 0;
	char command[100];
	char* buffer = command;
	
	//lancement de la boucle:
	while(!quit)
	{
		//affichage du prompt
		printf("$> ");
		
		//lecture de la commande
		buffer = command_get(buffer);
		
		//traitement de la commande
		quit = command_treat(buffer);
	}
}

char* command_get(char* buffer)
{
	//ressources
	char* command = NULL;
	char* n = NULL;
	char c;
	
	//saisie de la chaine de caractère :
	command = gets(buffer);
	
	if(command)
	{
		//nettoyage :
		n = strchr(buffer, '\n');
	
		if(n != NULL)
			*n = '\0';
		
		else
		{
			do{
				c = getchar();
			}while(c != '\n' && c != EOF);
		}
	}
		
	return command;
}

int command_treat(char* command)
{
	//ressources
	int quit = 0;
	
	//traitement de la commande (beurk)
	if(strcmp(command, "quit") == 0)
		quit = 1;
		
	else if(strcmp(command, "help") == 0)
		command_help();
		
	else
		printf("Commande inconnue.\n\n");
		
	return quit;
}
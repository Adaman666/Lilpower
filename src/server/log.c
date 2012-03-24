#include "log.h"

/*	fonction d'�criture dans le fichier de log
 *
 *	@param: message -> message � �crire
 *			file -> nom du fichier � utiliser
 *	@retour: nothing
 */
void log_command_write(char* message, char* file)
{
	//resources 
	FILE* log = NULL;
	
	//ouverture du fichier
	log = fopen(file, "a+"); /* TODO: a v�rifier */
	if(!log){
		printf("\n****ERREUR****\nImpossible d'ouvrir le fichier de log !\nmessage � afficher : %s\n\n", message);
	}
	else
	{
		fprintf(log, "[%s]: %s\n", time("HH:MM:SS"), message);
		fclose(log);
	}
}

#include "log.h"

/*	fonction d'écriture dans le fichier de log
 *
 *	@param: message -> message à écrire
 *			file -> nom du fichier à utiliser
 *	@retour: nothing
 */
void log_command_write(char* message, char* file)
{
	//resources 
	FILE* log = NULL;
	
	//ouverture du fichier
	log = fopen(file, "a+"); /* TODO: a vérifier */
	if(!log){
		printf("\n****ERREUR****\nImpossible d'ouvrir le fichier de log !\nmessage à afficher : %s\n\n", message);
	}
	else
	{
		fprintf(log, "[%s]: %s\n", time("HH:MM:SS"), message);
		fclose(log);
	}
}

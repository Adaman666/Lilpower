#include "server.h"

int main(int argc, char* argv[])
{
	//ressources
	pthread_t th;
	serv_t* serv = NULL;
	
	//allocation de la structure
	serv = (serv_t*)malloc(sizeof(serv_t));
	if(!serv){
		perror("\n****ERROR****\nLors de l'allocation du serveur.\n\n");
		exit(EXIT_FAILURE);
	}
	serv->mut = PTHREAD_MUTEX_INITIALIZER;
	
	//lecture des configurations
	
	//affichage du message de bienvenue
	bienvenue_message();
	
	//ouverture des ports d'�coute
	
	//cr�ation des listes de connection
	
	//lancement du thread d'�coute r�seau
	pthread_create(&th, NULL, run_net, serv);
	
	//lancement de la boucle d'�coute des commandes
	command_start();
	
	//envoi du signal de fin du thread
	pthread_mutex_lock(serv->mut);
	serv->quit = 1;
	pthread_mutex_unlock(serv->mut);
	
	//destruction des donn�es
	
	//fin
	pthread_join(th, NULL);
	return 0;
}

void bienvenue_message()
{
	//ressources
	FILE* f = NULL;
	int c;
	
	//affichage du num�ro de version :
	printf("\n\n\n\nServeur du projet Lilpower.\n\tVersion : %d\n\n", VERSION);
	
	//lecture du fichier de message :
	f = fopen("hello_message.txt", "r");
	if(!f)
	{
		perror("****ERROR****\nImpossible de charger hello_message.txt ");
	}
	else
	{
		c = getc(f);
		while(c != EOF)
		{
			putchar(c);
			c = getc(f);
		}
	}
}
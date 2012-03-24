#include "serv_net.h"

void run_net(void* data)
{
	//ressoruces
	int quit = 0;
	serv_t* s = (serv_t*)data;
	
	//lancement de la boucle
	do{
	
		//vérification de quit :
		pthread_mutex_lock(s->mut);
		quit = s->quit;
		pthread_mutex_unlock(s->mut);
		
	}while(!quit);
}
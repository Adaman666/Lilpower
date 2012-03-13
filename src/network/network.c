/**
 *	network.c Fichier source de la lib de cryptage du projet Lilpower
 *
 *	PropriÃ©tÃ© de LoÃ¯c Dalloz, Alexandre Brand, Jean-Charles Blind, Arthur Declerq et Romain Brewee
 *
 */
#include "network.h"
#include "net_include.h"

/** fonctions de gestion du protocole */
/**fonctions de création et destruction de connections : */

/**
 * 	fonction de création d'une connection côté client
 *
 * 	@param: port -> port auquel se connecter
 * 		adress -> adresse IP à laquelle se connecter
 * 		infos -> buffer contenant les infos client à faire passer au serveur
 *
 * 	@retour: adresse de la structure contenant la connection ainsi créée
 *
 * 	ATTENTION : - fonction bloquante avec un temps d'exécution élevé car le serveur doit fair une autorisation manuelle de la connection pour que cette dernière soit terminée
 * 		    - les infos passens par le réseau et peuvent arriver sur une machine 32bits ou 64bits il faut donc faire attention aux types des données utilisés dans ce buffer
 */
t_lilnet_c* lilnet_create_client(int port, int adress, char* infos)
{
	//ressources
	t_lilnet_c* client = NULL;

	//TODO
	
	return client;
}

/**
 * 	fonction de création de connection côté serveur : elle vérifie si un client demande la connection
 *
 * 	@param: port -> le port à vérifier préalablement ouvert avec lilnet_server_open_port
 *
 * 	@retour: adresse de la structure contenant la connection ainsi créée NULL si aucun client n'essais de se conecter
 *
 * 	ATTENTION : pour que le connection soit terminée, cette fonction doit être suivie d'un appel à lilnet_server_accept_connection.
 */
t_lilnet_s* lilnet_server_is_client_connected(t_lilnet_s_port port)
{
	//ressources
	t_lilnet_s* server = NULL;

	//TODO
	
	return server;
}

/**
 * 	fonction d'ouverture d'un port côté serveur
 *
 * 	@param: port -> entier représentant le port où se connecter
 *
 * 	@retour: adresse de la structure t_lilnet_s_port ainsi créée
 */
t_lilnet_s_port* lilnet_server_open_port(int port)
{
	//ressources
	t_lilnet_s_port* port = NULL;

	//TODO
	
	return port;
}

/**
 * 	fonction serveur d'acceptation de la connection client
 *
 * 	@param: c -> connection serveur précédemment créée par lilnet_server_is_client_sonnected
 * 		autorisation -> autorisation décernée par le serveur. prend la valeur ACCEPTED ou REJECTED
 *
 * 	@retour: ACCEPTED si la connection a bien été créée REJECTED si la connection n'a pas pu être terminée
 */
t_lilnet_server_accepted_connection(t_lilnet_s* c, int autorisation)
{
	//TODO
}

/**
 * 	fonction de destruction de la connection côté client
 *
 * 	@param: c -> connection client à détruire
 *
 * 	@retour: nothing
 */
void lilnet_client_destroy_connection(t_lilnet_c* c)
{

}

/**
 * 	fonction de destruction de la connection côté server
 *
 * 	@param: c -> connection server à détruire
 *
 * 	@retour: nothing
 */
void lilnet_server_destroy_connection(t_lilnet_s* c)
{

}


/** fonctions de l'envoi régulier client */

/**
 * 	fonction d'envoi de la production actuelle
 *
 * 	@param: production -> production actuelle
 * 		c -> connection client à utiliser
 *
 * 	@retour: RECEIVED si le serveur a reçu NOT_RECEIVED si non
 */
int lilnet_client_send_production(int production, t_lilnet_c* c)
{

}

/**
 * 	fonction de reception de la production actuelle d'un client côté serveur
 *
 * 	@param: c -> connection serveur à tester
 *
 * 	@retour: -1 si rien d'envoyé la production actuelle si non
 */
int lilnet_server_client_sent_production(t_lilnet_s* c)
{

}


/** fonctions d'envoi du serveur */

/**
 * 	fonction d'envoie de la requete de production du serveur
 *
 * 	@param: production -> production demandée
 * 		c -> connection à utiliser
 *
 * 	@retour: production possible dans le temps impartis par le serveur
 */
int lilnet_server_send_productio

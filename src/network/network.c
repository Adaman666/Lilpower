/**
 *	network.c Fichier source de la lib de cryptage du projet Lilpower
 *
 *	Propriété de Loïc Dalloz, Alexandre Brand, Jean-Charles Blind, Arthur Declerq et Romain Brewee
 *
 */
#include "network.h"
#include "net_include.h"

/** fonctions de gestion du protocole */
/**fonctions de cr�ation et destruction de connections : */

/**
 * 	fonction de cr�ation d'une connection c�t� client
 *
 * 	@param: port -> port auquel se connecter
 * 		adress -> adresse IP � laquelle se connecter
 * 		infos -> buffer contenant les infos client � faire passer au serveur
 *
 * 	@retour: adresse de la structure contenant la connection ainsi cr��e
 *
 * 	ATTENTION : - fonction bloquante avec un temps d'ex�cution �lev� car le serveur doit fair une autorisation manuelle de la connection pour que cette derni�re soit termin�e
 * 		    - les infos passens par le r�seau et peuvent arriver sur une machine 32bits ou 64bits il faut donc faire attention aux types des donn�es utilis�s dans ce buffer
 */
t_lilnet_c* lilnet_create_client(int port, int adress, char* infos)
{
	//ressources
	t_lilnet_c* client = NULL;

	//TODO
	
	return client;
}

/**
 * 	fonction de cr�ation de connection c�t� serveur : elle v�rifie si un client demande la connection
 *
 * 	@param: port -> le port � v�rifier pr�alablement ouvert avec lilnet_server_open_port
 *
 * 	@retour: adresse de la structure contenant la connection ainsi cr��e NULL si aucun client n'essais de se conecter
 *
 * 	ATTENTION : pour que le connection soit termin�e, cette fonction doit �tre suivie d'un appel � lilnet_server_accept_connection.
 */
t_lilnet_s* lilnet_server_is_client_connected(t_lilnet_s_port port)
{
	//ressources
	t_lilnet_s* server = NULL;

	//TODO
	
	return server;
}

/**
 * 	fonction d'ouverture d'un port c�t� serveur
 *
 * 	@param: port -> entier repr�sentant le port o� se connecter
 *
 * 	@retour: adresse de la structure t_lilnet_s_port ainsi cr��e
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
 * 	@param: c -> connection serveur pr�c�demment cr��e par lilnet_server_is_client_sonnected
 * 		autorisation -> autorisation d�cern�e par le serveur. prend la valeur ACCEPTED ou REJECTED
 *
 * 	@retour: ACCEPTED si la connection a bien �t� cr��e REJECTED si la connection n'a pas pu �tre termin�e
 */
t_lilnet_server_accepted_connection(t_lilnet_s* c, int autorisation)
{
	//TODO
}

/**
 * 	fonction de destruction de la connection c�t� client
 *
 * 	@param: c -> connection client � d�truire
 *
 * 	@retour: nothing
 */
void lilnet_client_destroy_connection(t_lilnet_c* c)
{

}

/**
 * 	fonction de destruction de la connection c�t� server
 *
 * 	@param: c -> connection server � d�truire
 *
 * 	@retour: nothing
 */
void lilnet_server_destroy_connection(t_lilnet_s* c)
{

}


/** fonctions de l'envoi r�gulier client */

/**
 * 	fonction d'envoi de la production actuelle
 *
 * 	@param: production -> production actuelle
 * 		c -> connection client � utiliser
 *
 * 	@retour: RECEIVED si le serveur a re�u NOT_RECEIVED si non
 */
int lilnet_client_send_production(int production, t_lilnet_c* c)
{

}

/**
 * 	fonction de reception de la production actuelle d'un client c�t� serveur
 *
 * 	@param: c -> connection serveur � tester
 *
 * 	@retour: -1 si rien d'envoy� la production actuelle si non
 */
int lilnet_server_client_sent_production(t_lilnet_s* c)
{

}


/** fonctions d'envoi du serveur */

/**
 * 	fonction d'envoie de la requete de production du serveur
 *
 * 	@param: production -> production demand�e
 * 		c -> connection � utiliser
 *
 * 	@retour: production possible dans le temps impartis par le serveur
 */
int lilnet_server_send_production_request(int production, t_lilnet_c* c)
{

}

/**
 * 	fonction d'envoie d'une demande de production de la part du serveur
 *
 * 	@param: productoin fonction -> fonction de calcul du temps de r�ponse de la ressource
 * 		c -> connection � utiliser
 *
 * 	@retour: -1 si rien n'a �t� envoy� si non retour de la production demand�e
 *
 * 	Cahier des charges de la fonction production_function : retourne l production possible en un temps donn� (time) par rapport � la production demand�e (production)
 *
 */
int lilnet_client_server_sent_request(int(*production_function)(int time, int production), t_lilnet_c* c)
{

}


/** fonctions utilitaires */

/**
 * 	fonction d'extraction des infos du client dans la structure de connection du serveur
 *
 * 	@param: c -> connection a utiliser
 *
 * 	@retour: buffer des infos du client connect�
 */
char* lilnet_server_extract_client_infos(t_lilnet_s* c)
{

}

/**
 * 	fonction d'extraction des infos du serveur dans la structure de connection
 *
 * 	@param: c -> connection � utiliser
 *
 * 	@retour: buffer des infos du serveur connect�
 */
char* lilnet_client_extract_server_infos(t_lilnet_c* c)
{

}


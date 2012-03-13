/**
 *	network.h Fichier header de la lib réseau du projet Lilpower
 *
 *	propriÃ©tÃ© de LoÃ¯c Dalloz, Alexandre Brand, Jean-Charkes Blind, Arthur Declerq et Romain Brewee
 *
 */

#ifndef NETWORK_H
#define NETWORK_H

#include "../crypt/crypt.h"

#define ACCEPTED 1
#define REJECTED 0

#define RECEIVED 1
#define NOT_RECEIVED 0

/*definition des structures*/
typedef struct lilnet_c
{

}t_lilnet_c;

typedef struct lilnet_s
{

}t_lilnet_s;

typedef struct lilnet_s_port
{

}t_lilnet_s_port;

/*prototypes*/
//fonctions de création et destruction de connections
t_lilnet_c* lilnet_create_client(int port, int adress, char* infos);
t_lilnet_s* lilnet_server_is_client_connected(t_lilnet_s_port port);
t_lilnet_s_port* lilnet_server_open_port(int port);
int lilnet_server_accept_connection(t_lilnet_s* c, int autorisation);
void lilnet_client_destroy_connection(t_lilnet_c* c);
void lilnet_server_destroy_connection(t_lilnet_s* c);

//fonctions de l'envoi régulier du client :
int lilnet_client_send_production(int production, t_lilnet_c* c);
int lilnet_server_client_sent_production(t_lilnet_s* c);

//fonctions d'envoi du serveur
int lilnet_server_send_production_request(int production, t_lilnet_c* c);
int lilnet_client_server_sent_request(int(*production_function)(int time, int production), t_lilnet_c* c);

//fonctions utilitaires
char* lilnet_server_extract_client_infos(t_lilnet_s* c);

#endif

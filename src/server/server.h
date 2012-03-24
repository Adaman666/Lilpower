#define SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "serv_net.h"
#include "command.h"
#include "log.h"
#include "../network/network.h"

#define VERSION 0.0.1

typedef struct serv
{
	pthread_mutex_t mut;
	int quit;
}serv_t;

void bienvenue_message();

#endif
#ifndef NET_INCLUDES_H
#define NET_INCLUDES_H

#include <stdio.h>
#include <stdlib.h>


#ifdef WIN32

#include <winsock2.h>

#elif defined (linux)

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else

#error code non définit pour cette plateforme

#endif

#endif

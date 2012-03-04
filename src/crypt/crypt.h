/**
 *	crypt.h Fichier header de la lib de cryptage du projet Lilpower
 *
 *	propriété de Loïc Dalloz, Alexandre Brand, Jean-Charles Blind, Arthur Declerq et Romain Brewee
 * 
 */

#ifndef CRYPT_H
#define CRYPT_H

#include <stdlib.h>
#include <stdio.h>

#define PUBLIC 0
#define PRIVATE 1

typedef struct key
{
	int type;
	int key;
}crypt_key;

/* prototypes des fonctions */
//fonctions de création de clé
crypt_key* crypt_create_public(int key);
crypt_key* crypt_create_private(crypt_key** public_key);

//fonction de cryptage-decriptage
char* crypt_encrypt(char* message, crypt_key* public_key);
char* crypt_decrypt(char* message, crypt_key* private_key);

#endif

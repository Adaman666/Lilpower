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
#include <math.h>

#define PUBLIC 0
#define PRIVATE 1
#define CR_TRUE 1
#define CR_FALSE 0

typedef struct key
{
	int type;
	unsigned long double p, q;
	unsigned long double n, f;
	unsigned long double e, d;
}crypt_key;

/* prototypes des fonctions */
//fonctions de création de clé
crypt_key* crypt_create_public(unsigned long double e, unsigned long double n);
crypt_key* crypt_create_private(crypt_key** public_key);

//fonction de cryptage-decriptage
char* crypt_encrypt(char* message, crypt_key* public_key);
char* crypt_decrypt(char* message, crypt_key* private_key);

//fonction utilitaires
static unsigned long double crypt_find_prem_other(int size, unsigned long double a, unsigned long double b);
static unsigned long double crypt_find_prem(int size);
static int crypt_is_prem(unsigned long double a, unsigned long double b);
static unsigned long double crypt_euclide(unsigned long double a, unsigned long double b);

#endif

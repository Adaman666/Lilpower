/**
 *	crypt.c Fichier source de la lib de cryptage du projet Lilpower
 *
 *	propriété de Loïc Dalloz, Alexandre Brand, Jean-Charles Blind, Arthur Declerq et Romain Brewee
 *
 */

#include "cript.h"

/** fonction de cryptage du projet Lilpower. */

/**
 *	fonction de création d'une clé publique
 *
 *	@param: clée à contenir
 *
 *	@retour: adresse de la structure clée ainsi créée
 */
crypt_key* crypt_create_public(int key)
{
	//ressources
	crypt_key* k = NULL;

	//allocation de la clé:
	k = (crypt_key*)malloc(sizeof(crypt_key));
	if(!k){
		perror("****fatal error****\nin crypt_create_public ");
		exit(EXIT_FAILURE);}

	//remplissage de la structure
	k->type = PUBLIC;
	k->key = key;

	return k;
}

/**
 *	fonction de création d'une clée privée et de sa clée publique associée.
 *
 *	@param: pointeur sur le pointeur de la clée publique
 *
 *	@retour: adresse de la structure clée ainsi créée
 */
crypt_key* crypt_create_private(crypt_key** public_key)
{
	//ressources
	crypt_key* pr_k = NULL;

	//allocation de la strucure clé privée
	pr_k = (crypt_key*)malloc(sizeof(crypt_key));
	if(!pr_k){
		perror("****fatal error****\nin crypt_create_public ");
		exit(EXIT_FAILURE);}

	//création des deux clées
	//TODO

	//remplissage :
	*public_key = crypt_create_public(public_k);

	pr_k->type = PRIVATE;
	pr_k->key = private_k;

	return pr_k;
}

/**
 *	fonction d'encryptage d'un message :
 *
 *	@param: message -> message à encrypter
 *		public_key -> clée privée à utiliser pour encrypter le message
 *
 *	@retour: message encrypté
 */
char* crypt_encrypt(char* message, crypt_key* public_key)
{
	//ressources

	//TODO
}

/**
 *	fonction de décryptage d'un message :
 *
 *	@param: message -> message à décrypter
 *		private_key -> clée privée à utiliser pour décrypter le message
 *
 *	@retour: message décrypté
 */
char* crypt_decrypt(char* message, crypt_key* private_key)
{
	//ressources
	
	//TODO
}

/**
 *	fonction de recherche de nombre premier
 *
 *	@param: size -> taille (en bit) du nombre � trouver (max : sizeof(int) sur une machine 32bit
 *		a -> nombre avec lequel le nombre doit �tre premier (0 par d�faut)
 *		b -> comme a
 *
 *	@retour: num�ro retourn�
 */
static unsigned int crypt_find_prem(int size, int a, int b)
{

	//ressources
	unsigned int number;

	if(a == 0)
	{
		//...
	}
	else
	{
		if(b==0)
		{
			//...
		}
		else
		{
			//...
		}
	}
 	
	return number;
}

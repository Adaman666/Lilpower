/**
 *	crypt.c Fichier source de la lib de cryptage du projet Lilpower
 *
 *	propri�t� de Lo�c Dalloz, Alexandre Brand, Jean-Charles Blind, Arthur Declerq et Romain Brewee
 *
 */

#include "cript.h"

/** fonctions de cryptage du projet Lilpower. */

/**
 *	fonction de creation d'une cle publique
 *
 *	@param: cle a contenir
 *
 *	@retour: adresse de la structure cle ainsi creee
 */
crypt_key* crypt_create_public(unsigned long double e, unsigned long double n)
{
	//ressources
	crypt_key* k = NULL;

	//allocation de la cle:
	k = (crypt_key*)malloc(sizeof(crypt_key));
	if(!k){
		perror("****fatal error****\nin crypt_create_public ");
		exit(EXIT_FAILURE);}

	//remplissage de la structure
	k->type = PUBLIC;
	k->e = e;
	k->n = n;
	k->p = 0;
	k->q = 0;
	k->f = 0;
	k->d = 0;

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
	unsigned long double p, q, f, n, e, d;
	int k;

	//allocation de la strucure clé privée
	pr_k = (crypt_key*)malloc(sizeof(crypt_key));
	if(!pr_k){
		perror("****fatal error****\nin crypt_create_public ");
		exit(EXIT_FAILURE);}

	//creation des cles
	//r�cup�ration de p et q :
	p = crypt_find_prem(32);
	q = crypt_find_prem(32);
	//calcul de n et f :
	n = p*q;
	f = (p-1)*(q-1);
	//r�cup�ration de e :
	e = crypt_find_prem_other(32, n, f);
	//calul de d :
	k = 1;
	do{
		k++;
	}while(((k*f)-1)%e != 0);
	d = ((k*f)-1)/e;

	//remplissage :
	*public_key = crypt_create_public(e, n);

	pr_k->type = PRIVATE;
	pr_k->p = p;
	pr_k->q = q;
	pr_k->f = f;
	pr_k->n = n;
	pr_k->e = e;
	pr_k->d = d;

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
	int size, i;
	char* buffer;
	
	//r�cup�tation de la taille du message :
	size = sizeof(*message);
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
 *	fonction de recherche de nombre premier en fonction d'autres nombres
 *
 *	@param: size -> taille min (en bit) du nombre � trouver (max : sizeof(double) sur une machine 32bit)
 *		a -> nombre avec lequel le nombre doit �tre premier (0 par d�faut)
 *		b -> comme a
 *
 *	@retour: num�ro retourn�
 */
static unsigned long double crypt_find_prem_other(int size, int a, int b)
{

	//ressources
	unsigned long double number;

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

/**
 *	fonction de recherche d'un nombre premier
 *
 *	@param: size -> taille min (en bit) du nombre a trouver (max : sizeof(double) sur machine 32bit) 
 *
 *	@retour: nombre premier trouv�
 */
static unsigned long double crypt_find_prem(int size)
{
	//ressources
	unsigned long double nbr;
	
	//recherche
	
	return nbr;
}
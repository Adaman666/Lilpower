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
char* crypt_encrypt(unsigned short int* message, crypt_key* public_key)
{
	//ressources
	unsigned long double* encrypt = NULL;
	int i, size;
	
	//allocation du tableau du message encrypt�
	size = sizeof(message)/sizeof(unsigned short int);
	encrypt = (unsigned long double*)malloc(size*sizeof(unsigned long double));
	if(!encrypt){
		perror("****ERROR****\nIn crypt_encrypt ");
		exit(EXIT_FAILURE);}
		
	//encryptage:
	for(i=0; i<size; i++)
		encrypt[i]=pow(message[i], public_key->e)%public_key->n;
		
	//retour du message encrypt�
	return (char*)encrypt;
}

/**
 *	fonction de décryptage d'un message :
 *
 *	@param: message -> message à décrypter
 *		private_key -> clée privée à utiliser pour décrypter le message
 *
 *	@retour: message décrypté
 */
char* crypt_decrypt(unsigned long double* message, crypt_key* private_key)
{
	//ressources
	short int* decrypt = NULL;
	int i, size;
	
	//allocation du tableau de message d�crypt�
	size = sizeof(message)/sizeof(unsigned long double);
	decrypt = (unsigned short int)malloc(sizeof(unsigned short int)*size);
	if(!decrypt){
		perror("****ERROR****\nIn crypt_decrypt ");
		exit(EXIT_FAILURE);}
		
	//encrypt�ge
	for(i=0; i<size; i++)
		decrypt[i]=pow(message[i], private_key->d)%private_key->n;
		
	//retour du message d�crypt�
	return decrypt;
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
		nubmer = crypt_find_prem(size);
	}
	else
	{
		if(b==0)
		{
			do{
				number = crypt_find_prem(size);
			}while(crypt_is_prem(number, a) == CR_FALSE);
		}
		else
		{
			do{
				number = crypt_find_prem(size);
			}while((crypt_is_prem(number, a) == CR_FALSE) && (crypt_is_prem(number, b)));
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
 *
 *	Attention : les nombres premiers sont lus dans le fichier prem.txt
 */
static unsigned long double crypt_find_prem(int size)
{
	//ressources
	unsigned long double nbr, min, tmp, pres;
	int err;
	FILE* prem = NULL

	//ouverture du fichier
	prem = fopen("prem.txt", "r");
	if(!prem){perror("***FATAL ERROR*** when loading prem.txt file ");exit(EXIT_FAILURE);}
	
	/** recherche */
	//calcul du nombre minumum:
	min = 1;
	min = min << size;

	//recherche des nombres sup�rieurs � cette valeur :
	do{
		err = fscanf(prem, "%Ld", &tmp);
	}while((tmp < min) && (err == 1));
	//si fin de fichier pr�matur� :
	if(err == 0){printf("***FATAL ERROR*** when reading prem.txt file : the time to reach the end of file is too short.\n\n");exit(EXIT_FAILURE);}

	//s�lection du nombre premier (une chance sur 4)
	nbr = 0;
	do{
		err = fscanf(prem, "%Ld", &tmp);
		if(rand()%4 == 0)
			nbr = tmp;
	}while((nbr == 0) && (err != 0));
	if(nbr == 0)
		nbr = tmp;

	//fermeture du fichier
	fclose(prem);

	return nbr;
}

/**
 * 	fonction de pgcd
 *
 * 	@param: a et b -> les deux nombres � tester
 *
 * 	@retour: CR_TRUE si les deux nombre sont premiers entre eux et CR_FALSE si non
 */
static int crypt_is_prem(unsigned long double a, unsigned long double b)
{
	//ressources
	int result;
	unsigned long double x, y;

	//blindage :
	if(a > b){
		x = a;
		y = b;}
	else{
		x = b;
		y = a;}

	//test
	if(crypt_euclide(x, y) == 1)
		result = CR_TRUE;
	else
		result = CR_FALSE;

	//retour du r�sultat
	return result;
}
	
/**
 * 	fonction r�cursive de l'algorythme d'euclide
 *
 * 	@param: a et b -> les deux nombre � diviser (avec a>b)
 *
 * 	@retour: pgcd des deux nombres
 */
static unsigned long double crypt_euclide(unsigned long double a, unsigned long double b)
{
	//ressources
	unsigned long double r;
	unsigned long double ret;

	//division :
	r = a%b;

	//algo en lui m�me :
	if(r != 0)
		ret = crypt_euclide(b, r);
	else
		ret = b;

	return ret;
}

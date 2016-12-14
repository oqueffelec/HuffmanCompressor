#ifndef __FILE__DE__PRIORITE__
#define __FILE__DE__PRIORITE__

#define FDP_ERREUR_MEMOIRE 1

#include <errno.h>
#include "arbreDeHuffman.h"

/**
* \struct FDP_filedepriorite FileDePriorite.h
* \brief la structure est un tableau dynamique d'arbres
* L'enregistrement contient aussi la taille du tableau et le nombre d'elements
*/
typedef struct fileDePriorite{
	int taille;
	int nbElements;
    ArbreDeHuffman* Elements;
} fileDePriorite;

/**
* \fonction FDP_estVide
* \arguments fdp une file de priorite 
* \brief la fonction retoune 1 si la file de pririte est vide et 0 si elle n'est pas vide
*/
int FDP_estVide(fileDePriorite* fdp);

/**
* \fonction FDP_defiler 
* \arguments fdp une file de priorite 
* \brief la fonction retourne le plus grand element de la file et le suprimme de la file
*/
int FDP_defiler(fileDePriorite* fdp);

/**
* \fonction FDP_insererElement 
* \arguments fdp une file de priorite 
             element l'arbre a inserer
* \brief la fonction insere un arbre dans la file
*/
void FDP_insererElement(fileDePriorite* fdp, ArbreDeHuffman element);

/**
* \fonction FDP_initialiser
* \arguments fdp une file de priorite
* \brief la fonction initialise un file de priorite
*/
void FDP_intialiser(fileDePriorite* fdp);

/**
* \fonction ranger
* \arguments fdp un tableau d'arbres de huffman 
             tete l'indice du premier element
	     nbElement le nombre d'elements a ranger
* \brief la fonction trie recursivement le tableau d'arbres de façcon decroissante selon leur priorite (ponderation)
*/
void ranger(ArbreDeHuffman * fdp, int tete, int nbElements);

/**
* \fonction FDP_insererElement 
* \arguments fdp une file de priorite 
* \brief la fonction retourne le plus grand element de la liste
*/
ArbreDeHuffman FDP_ObtenirElement(fileDePriorite *fdp);

/**
* \fonction FDP_toutDefiler
* \arguments fdp une file de priorite 
             element l'arbre a inserer
* \brief la fonction vide la file de priorite et desalloue tous les elements
*/
void FDP_toutDefiler(fileDePriorite *fdp);
#endif


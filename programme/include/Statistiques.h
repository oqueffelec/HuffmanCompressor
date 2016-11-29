/**
 * \file Statistiques.h
 * \brief Implantation du TAD Statistiques : Statistiques est un dictionnaire qui a pour clé un octet et pour valeur un Naturel
 * \author Mathieu Vandecasteele
 * \version 1.0
 */
#ifndef __STATISTIQUES__
#define __STATISTIQUES__

//#include "Octet.h"
#define STAT_ERREUR_MEMOIRE 1

/**
* \struct STAT_Statistiques Statistiques.h
* \brief la structure est une liste chainee ayant 2 elements (la clé et la valeur)
*/

typedef struct STAT_Noeud* STAT_Statistiques;
typedef struct STAT_Noeud {
	int* octet;
  unsigned long int* naturel;
	STAT_Statistiques listeSuivante;
}  STAT_Noeud;

/**
* \fn STAT_Statistiques STAT_statistiques()
* \brief crée une variale de type STAT_Statistiques
* \return STAT_Statistiques
*/

STAT_Statistiques STAT_statistiques();

/**
* \fn void STAT_ajouterElement(STAT_Statistiques* stat, int*o, unsigned long int*naturel)
* \brief ajoute un couple cle valeur à la stat
* \return void
*/

void STAT_ajouterElement(STAT_Statistiques* stat, int*o, unsigned long int*naturel);

/**
* \fn int STAT_estPresentOctet(STAT_Statistiques stat, int*o);
* \brief verifie la presence d'un octet dans la stat
* \return int
*/

int STAT_estPresentOctet(STAT_Statistiques stat, int*o);

/**
* \fn int STAT_estPresentNaturel(STAT_Statistiques stat, unsigned long int*nat)
* \brief verifie la presence d'un naturel dans la stat
* \return int
*/

int STAT_estPresentNaturel(STAT_Statistiques stat, unsigned long int*nat);

/**
* \fn int* STAT_obtenirOctet(STAT_Statistiques stat, unsigned long int*nat)
* \brief renvoie l'octet correspondant à un naturel
* \return int*
*/


int* STAT_obtenirOctet(STAT_Statistiques stat, unsigned long int*nat);

/**
* \fn unsigned long int* STAT_obtenirValeur(STAT_Statistiques stat, int*o)
* \brief renvoie le naturel correspondant
* \return unsigned long int*
*/

unsigned long int* STAT_obtenirValeur(STAT_Statistiques stat, int*o);

/**
* \fn void STAT_obtenirValeurs(STAT_Statistiques* stat)
* \brief renvoie la liste des octets présents
* \return void
*/

void STAT_obtenirValeurs(STAT_Statistiques* stat);

#endif

/**
 * \file statistiques.h
 * \brief Implantation du TAD Statistiques : Statistiques est un dictionnaire de 256 Octets et 256 pondérations
 * \author Mathieu Vandecasteele
 * \version 1.0
 * \date 20/11/2016
 */
#ifndef __STATISTIQUES__
#define __STATISTIQUES__

#include "Octet.h"


#define STAT_ERREUR_MEMOIRE 1
#define STAT_SIZE 256

/**
* \struct STAT_Statistiques Statistiques.h
* \brief la structure est un tableau de 256 élements soit 256 octets de type Octet maximum.
*/

typedef struct STAT_Statistiques {
unsigned long int valeur[STAT_SIZE];
}  STAT_Statistiques;


/**
* \fn STAT_Statistiques STAT_statistiques()
* \brief initialise une variable STAT_Statistiques avec des octets zeros et des pondérations nulles
* \return STAT_Statistiques
*/

STAT_Statistiques STAT_statistiques();

/**
* \fn void STAT_ajouter(STAT_Statistiques* stat, O_Octet* octet, unsigned long int pond)
* \brief incrémente la pondération associée à l'octet.
* \return void
*/

void STAT_ajouter(STAT_Statistiques* stat, O_Octet o);

/**
* \fn int STAT_estPresentOctet(STAT_Statistiques stat, int octet)
* \brief verifie la présence d'une octet dans le tableau d'octet i.e la pondération est différente de 0.
* \return int
*/

int STAT_estPresentOctet(STAT_Statistiques stat, O_Octet octet);

/**
* \fn unsigned long int STAT_obtenirPonderation(STAT_Statistiques stat, O_Octet* o)
* \brief renvoie la pondération correspondante
* \return unsigned long int
*/

unsigned long int STAT_obtenirPonderation(STAT_Statistiques stat, O_Octet o);

#endif

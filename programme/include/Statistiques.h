/**
 * \file Statistiques.h
 * \brief Implantation du TAD Statistiques : Statistiques est un dictionnaire de 256 Octets et 256 ponderations
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
* \brief la structure est un tableau de 256 elements soit 256 octets de type Octet maximum.
*/

typedef struct STAT_Statistiques {
unsigned long int valeur[STAT_SIZE];
}  STAT_Statistiques;


/**
* \fn STAT_Statistiques STAT_statistiques()
* \brief initialise une variable STAT_Statistiques avec des octets zeros et des ponderations nulles
* \return STAT_Statistiques
*/

STAT_Statistiques STAT_statistiques();

/**
* \fn void STAT_ajouter(STAT_Statistiques* stat, O_Octet o)
* \brief incremente la ponderation associee à l'octet.
* \return void
*/

void STAT_ajouter(STAT_Statistiques* stat, O_Octet o);

/**
* \fn int STAT_estPresentOctet(STAT_Statistiques stat, O_Octet octet)
* \brief verifie la presence d'une octet dans le tableau d'octet i.e la ponderation est differente de 0.
* \return int
*/

int STAT_estPresentOctet(STAT_Statistiques stat, O_Octet octet);

/**
* \fn unsigned long int STAT_obtenirPonderation(STAT_Statistiques stat, O_Octet o)
* \brief renvoie la ponderation correspondante
* \return unsigned long int
*/

unsigned long int STAT_obtenirPonderation(STAT_Statistiques stat, O_Octet o);

#endif

/**
 * \file tableDeCodage.h
 * \brief Implantation du TAD tableDeCodage : tableDeCodage est un dictionnaire qui a pour clé un octet et pour valeur un code binaire
 * \author Octave Queffelec
 * \version 1.0
 */
#ifndef __STATISTIQUES__
#define __STATISTIQUES__

#include "Octet.h"
#define STAT_ERREUR_MEMOIRE 1
#define STAT_SIZE 256

/**
* \struct STAT_Statistiques tableDeCodage.h
* \brief la structure est une liste chainee ayant 2 elements (la clé et la valeur)
*/


typedef struct STAT_Statistiques {
unsigned long int valeur[STAT_SIZE];
}  STAT_Statistiques;

/**
* \fn STAT_Statistiques STAT_Statistiques()
* \brief renvoie la position d'un coup
* \return STAT_Statistiques
*/

STAT_Statistiques STAT_statistiques();

/**
* \fn void ajouter(STAT_Statistiques, octet, codeBinaire)
* \brief ajoute un couple cle valeur à la stat
* \return void
*/

void STAT_ajouter(STAT_Statistiques* stat, O_Octet* o, unsigned long int nat);

/**
* \fn int stat_estPresentCodeBinaire(STAT_Statistiques stat, codeBinaire cb)
* \brief verifie la presence d'un codebinaire dans la stat
* \return int
*/

int STAT_estPresent(STAT_Statistiques stat, unsigned long int nat);


/**
* \fn codeBinaire stat_obtenirCodeBinaire(STAT_Statistiques stat, octet o)
* \brief renvoie le codebinaire correspondant
* \return codebinaire
*/

unsigned long int STAT_obtenirCodeBinaire(STAT_Statistiques stat, O_Octet* o);

/**
* \fn void stat_retirerOctet(STAT_Statistiques stat, octet o)
* \brief retire le couple octet codebinaire
* \return void
*/

unsigned long int STAT_obtenirCodeBinaires(STAT_Statistiques stat);

#endif

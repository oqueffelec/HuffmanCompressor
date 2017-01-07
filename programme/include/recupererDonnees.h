/**
 * \file recupererDonnees.h
 * \brief Implantation de la fonction recupererDonnees : récupère la stat, la longeur du fichier source, et ressort le codeBinaire du fichier compressé
 * \author Octave Queffelec
 * \version 1.0
 * \date 26/12/2016
 */

#ifndef __RECUPERERDONNEES__
#define __RECUPERERDONNEES__


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Octet.h"
#include "Statistiques.h"
#include "creerTableDeCodage.h"
#include "CodeBinaire.h"
#include "FileDePriorite.h"
#include "creerFileDePriorite.h"
#include "TableDeCodage.h"


/**
* \fn int estFichierHuffman(FB_FichierBinaire fichierSource)
* \brief retourne si l'identifiant du fichier est un identifiant .huff
* \return int
*/

int estFichierHuffman(FB_FichierBinaire fichierSource);

/**
* \fn void recupererStatistiques(FB_FichierBinaire fichierSource, STAT_Statistiques* stat)
* \brief récupère les statistiques du fichier
* \return void
*/


void recupererStatistiques(FB_FichierBinaire fichierSource, STAT_Statistiques* stat);

/**
* \fn void recupererLongueur(FB_FichierBinaire fichierSource, int* longueur);
* \brief récupère la longeur en octet du fichier
* \return void
*/

void recupererLongueur(FB_FichierBinaire fichierSource, int* longueur);

/**
* \fn void recupererDonnees(FB_FichierBinaire fichierSource, STAT_Statistiques* stat, int* longueur)
* \brief récupère l'entete du fichier, statistiques + longueur + vérification de l'id
* \return void
*/

void recupererDonnees(FB_FichierBinaire fichierSource, STAT_Statistiques* stat, int* longueur);
#endif

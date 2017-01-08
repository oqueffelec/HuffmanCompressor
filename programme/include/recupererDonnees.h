/**
 * \file recupererDonnees.h
 * \brief Implantation de la fonction recupererDonnees : recupere la stat, la longeur du fichier source, et ressort le codeBinaire du fichier compresse
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
* \brief recupere les statistiques du fichier
* \return void
*/


void recupererStatistiques(FB_FichierBinaire fichierSource, STAT_Statistiques* stat);

/**
* \fn void recupererLongueur(FB_FichierBinaire fichierSource, int* longueur);
* \brief recupere la longeur en octet du fichier
* \return void
*/

void recupererLongueur(FB_FichierBinaire fichierSource, int* longueur);

/**
* \fn void recupererDonnees(FB_FichierBinaire fichierSource, STAT_Statistiques* stat, int* longueur)
* \brief recupere l'entete du fichier, statistiques + longueur + verification de l'id
* \return void
*/

void recupererDonnees(FB_FichierBinaire fichierSource, STAT_Statistiques* stat, int* longueur);
#endif

/**
 * \file recupererDonnees.h
 * \brief Implantation de la fonction recupererDonnees : recupere la stat, la longeur du fichier source, et ressort le codeBinaire du fichier compressé
 * \author Octave Queffelec
 * \version 1.0
 * \date 26/12/2016
 */

#ifndef __RECUPERERDONNEES__
#define __RECUPERERDONNEES__


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "octet.h"
#include "statistiques.h"
#include "creerTableDeCodage.h"
#include "codeBinaire.h"
#include "FileDePriorite.h"
#include "creerFileDePriorite.h"
#include "tableDeCodage.h"


/**
* \fn ArbreDeHuffman creerAbreDeHuffman(FDP_FileDePriorite file)
* \brief renvoie l'arbre de Huffman créer à partir d'une file de priorite
* \return ArbreDeHuffman
*/

int estFichierHuffman(FB_FichierBinaire fichierSource);

/**
* \fn void remplirTableDeCodage(TDC_TableDeCodage tdc, ArbreDeHuffman arbre, CB_CodeBinaire code);
* \brief remplie la table de codage à partir d'un arbre de Huffman
* \return void
*/


void recupererStatistiques(FB_FichierBinaire fichierSource, STAT_Statistiques* stat);

/**
* \fn TDC_TableDeCodage creerTableDeCodage(STAT_Statistiques stats);
* \brief remplie la table de codage à partir des stats
* \return TDC_TableDeCodage
*/

void recupererCodeBinaire(FB_FichierBinaire fichierSource, CB_CodeBinaire* cb);

void recupererDonnees(FB_FichierBinaire fichierSource, STAT_Statistiques* stat, int* longueur, CB_CodeBinaire* cb);


#endif

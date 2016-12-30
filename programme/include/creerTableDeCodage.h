/**
 * \file creerTableDeCodage.h
 * \brief Implantation de la fonction creerTableDeCodage : crée la table de codage correspondante au statistiques donnés.
 * \author Jean-Gabriel Wacyk
 * \version 1.0
 * \date 26/12/2016
 */

#ifndef __CREERTABLEDECODAGE__
#define __CREERTABLEDECODAGE__


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

ArbreDeHuffman creerAbreDeHuffman(FDP_FileDePriorite file);

/**
* \fn void remplirTableDeCodage(TDC_TableDeCodage tdc, ArbreDeHuffman arbre, CB_CodeBinaire code);
* \brief remplie la table de codage à partir d'un arbre de Huffman
* \return void
*/


void remplirTableDeCodage(TDC_TableDeCodage* tdc, ArbreDeHuffman arbre, CB_CodeBinaire* code);

/**
* \fn TDC_TableDeCodage creerTableDeCodage(STAT_Statistiques stats);
* \brief remplie la table de codage à partir des stats
* \return TDC_TableDeCodage
*/

TDC_TableDeCodage creerTableDeCodage(STAT_Statistiques stats);

#endif
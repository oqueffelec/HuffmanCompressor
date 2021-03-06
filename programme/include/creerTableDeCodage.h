/**
 * \file creerTableDeCodage.h
 * \brief Implantation de la fonction creerTableDeCodage : cree la table de codage correspondante au statistiques donnees.
 * \author Jean-Gabriel Wacyk
 * \version 1.0
 * \date 26/12/2016
 */

#ifndef __CREERTABLEDECODAGE__
#define __CREERTABLEDECODAGE__


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
* \fn ArbreDeHuffman creerArbreDeHuffman(FDP_FileDePriorite file)
* \brief renvoie l arbre de Huffman cree a partir d une file de priorite
* \return ArbreDeHuffman
*/

ArbreDeHuffman creerArbreDeHuffman(FDP_FileDePriorite file);

/**
* \fn void remplirTableDeCodage(TDC_TableDeCodage* tdc, ArbreDeHuffman arbre, CB_CodeBinaire* code)
* \brief remplit la table de codage a partir d un arbre de Huffman
* \return void
*/


void remplirTableDeCodage(TDC_TableDeCodage* tdc, ArbreDeHuffman arbre, CB_CodeBinaire* code);

/**
* \fn TDC_TableDeCodage creerTableDeCodage(STAT_Statistiques stats)
* \brief remplit la table de codage a partir des stats
* \return TDC_TableDeCodage
*/

TDC_TableDeCodage creerTableDeCodage(STAT_Statistiques stats);

#endif

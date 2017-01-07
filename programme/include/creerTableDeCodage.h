/**
 * \file creerTableDeCodage.h
 * \brief Implantation de la fonction creerTableDeCodage : crée la table de codage correspondante au statistiques données.
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
* \fn ArbreDeHuffman creerAbreDeHuffman(FDP_FileDePriorite file)
* \brief renvoie l'arbre de Huffman créé à partir d'une file de priorité
* \return ArbreDeHuffman
*/

ArbreDeHuffman creerArbreDeHuffman(FDP_FileDePriorite file);

/**
* \fn void remplirTableDeCodage(TDC_TableDeCodage tdc, ArbreDeHuffman arbre, CB_CodeBinaire code);
* \brief remplit la table de codage à partir d'un arbre de Huffman
* \return void
*/


void remplirTableDeCodage(TDC_TableDeCodage* tdc, ArbreDeHuffman arbre, CB_CodeBinaire* code);

/**
* \fn TDC_TableDeCodage creerTableDeCodage(STAT_Statistiques stats);
* \brief remplit la table de codage à partir des stats
* \return TDC_TableDeCodage
*/

TDC_TableDeCodage creerTableDeCodage(STAT_Statistiques stats);

#endif

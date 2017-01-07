/**
  * \file decodageCodeBinaire.c
  * \brief Décompression et écriture des données dans un fichier
  * \author Jean-Gabriel Wacyk
  * \version 1.0
  * \date 30/12/2016
  */

#ifndef __DECODAGE__CODE__BINAIRE__
#define __DECODAGE__CODE__BINAIRE__

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "Statistiques.h"
#include "CodeBinaire.h"
#include "TableDeCodage.h"
#include "FichierBinaire.h"
#include "creerTableDeCodage.h"
#include "Octet.h"

/**
* \fn void decodage(CB_CodeBinaire donne,FB_FichierBinaire* dest,STAT_Statistiques stats);
* \brief décode le Code Binaire donné par la procédure decodage et renvoie un booléen si le code binaire correspond à un code binaire du fichier codé
* \return void
*/

void decodageCodeBinaire(CB_CodeBinaire cbAdecoder, ArbreDeHuffman adh, O_Octet* octet, int* trouve);

#endif

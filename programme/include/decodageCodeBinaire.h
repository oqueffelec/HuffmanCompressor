/**
  * \file decodageCodeBinaire.h
  * \brief Decompression et ecriture des donnees dans un fichier
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
* \fn void decodageCodeBinaire(CB_CodeBinaire cbAdecoder, ArbreDeHuffman adh, O_Octet* octet, int* trouve)
* \brief decode le Code Binaire donne par la procedure decodage et renvoie un booleen si le code binaire correspond à un code binaire du fichier code
* \return void
*/

void decodageCodeBinaire(CB_CodeBinaire cbAdecoder, ArbreDeHuffman adh, O_Octet* octet, int* trouve);

#endif

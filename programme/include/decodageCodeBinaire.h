/**
  * \file decodageCodeBinaire.c
  * \brief Décompression et écriture des donnée dans un fichier
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
#include "statistiques.h"
#include "codeBinaire.h"
#include "tableDeCodage.h"
#include "fichierBinaire.h"
#include "creerTableDeCodage.h"
#include <errno.h>
#include "octet.h"

/**
* \fn void decodage(CB_CodeBinaire donne,FB_FichierBinaire* dest,STAT_Statistiques stats);
* \brief decode le Code Binaire donné par la procedure decodage et renvoie un boolean si le code binaire correspond à un code binaire du fichier codé
* \return void
*/

void decodageCodeBinaire(CB_CodeBinaire cbAdecoder, ArbreDeHuffman adh, O_Octet* octet, int* trouve);

#endif

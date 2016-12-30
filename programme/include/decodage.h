/**
  * \file decodage.c
  * \brief Décompression et écriture des donnée dans un fichier
  * \author Jean-Gabriel Wacyk
  * \version 1.0
  * \date 30/12/2016
  */

#ifndef __DECODAGE__
#define __DECODAGE__

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
* \brief decode le Code Binaire à l'aide d'un arbre de Huffman crée à partir des statistiques et écris dans un fichier
* \return void
*/

void decodage(CB_CodeBinaire donne,FB_FichierBinaire* dest,STAT_Statistiques stats);


#endif

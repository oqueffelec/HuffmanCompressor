/**
  * \file decodage.c
  * \brief Décompression et écriture des données dans le fichier destination
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
#include "Statistiques.h"
#include "CodeBinaire.h"
#include "TableDeCodage.h"
#include "FichierBinaire.h"
#include "creerTableDeCodage.h"
#include "Octet.h"

/**
* \fn void decodage(CB_CodeBinaire donne,FB_FichierBinaire* dest,STAT_Statistiques stats);
* \brief concatène les bits du fichier pour former un codebinaire qui sera decodé par la procédure decodageCodeBinaire
* \return void
*/

void decodage(FB_FichierBinaire* fichierDest,FB_FichierBinaire fichierSource,int longueur,ArbreDeHuffman adh);


#endif

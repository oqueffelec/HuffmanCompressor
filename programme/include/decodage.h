/**
  * \file decodage.h
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
* \fn void decodage(FB_FichierBinaire* fichierDest,FB_FichierBinaire fichierSource,int longueur,ArbreDeHuffman adh)
* \brief décode le fichierSource grâce à l'ArbreDeHuffman dans le fichierDest
* \return void
*/

void decodage(FB_FichierBinaire* fichierDest,FB_FichierBinaire fichierSource,int longueur,ArbreDeHuffman adh);


#endif

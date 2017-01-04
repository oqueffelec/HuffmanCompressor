/**
  * \file decodage.c
  * \brief Décompression et écriture des donnée dans un fichier
  * \author Jean-Gabriel Wacyk
  * \version 1.0
  * \date 30/12/2016
  */
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
#include "decodageCodeBinaire.h"
#include <errno.h>
#include "octet.h"

void decodage(FB_FichierBinaire* fichierDest,FB_FichierBinaire fichierSource,int longueur,ArbreDeHuffman adh){
  int posCurseur = 0;
  O_Octet octetAlire=O_octetZero();
  O_Octet octetAecrire= O_octetZero();
  CB_CodeBinaire cbAdecoder=CB_codeBinaire();

  while(posCurseur <= longueur-1 && !FB_finFichier(fichierSource) && FB_lireOctet(fichierSource, &octetAlire)){
   int trouve=false;
   int i = 0;
   octetAlire.nb=8;
    while (i < 8 && posCurseur < longueur-1) {
      CB_ajouter(&cbAdecoder,O_obtenirBit(octetAlire,i));
      decodageCodeBinaire(cbAdecoder, adh, &octetAecrire, &trouve);
      if(trouve){
        FB_ecrireOctet(fichierDest, octetAecrire);
        cbAdecoder=CB_codeBinaire();
        posCurseur++;
      }
      i++;
    }
  }
 }

/**
  * \file decodage.c
  * \brief Decompression et ecriture des donnee dans un fichier
  * \author Jean-Gabriel Wacyk
  * \version 1.0
  * \date 30/12/2016
  */
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
#include "decodageCodeBinaire.h"
#include "Octet.h"

void decodage(FB_FichierBinaire* fichierDest,FB_FichierBinaire fichierSource,int longueur,ArbreDeHuffman adh){
  int posCurseur = 0;
  O_Octet octetAlire=O_octetZero();
  O_Octet octetAecrire= O_octetZero();
  CB_CodeBinaire cbAdecoder=CB_codeBinaire();
  CB_CodeBinaire cbAdecoderInverse=CB_codeBinaire();


  while(posCurseur <= longueur-1 && !FB_finFichier(fichierSource) && FB_lireOctet(fichierSource, &octetAlire)){
   int trouve=false;
   int i = 0;
   octetAlire.nb=8;
    while (i < 8 && posCurseur < longueur-1) {
      CB_ajouter(&cbAdecoder,O_obtenirBit(octetAlire,7-i));
      cbAdecoderInverse=CB_copie(cbAdecoder);
      decodageCodeBinaire(cbAdecoderInverse, adh, &octetAecrire, &trouve);
      if(trouve){
        FB_ecrireOctet(fichierDest, octetAecrire);
        CB_supprimer(&cbAdecoder);
        CB_supprimer(&cbAdecoderInverse);
        cbAdecoder=CB_codeBinaire();
        cbAdecoderInverse=CB_codeBinaire();
        posCurseur++;
      }
      i++;
    }
  }
 }

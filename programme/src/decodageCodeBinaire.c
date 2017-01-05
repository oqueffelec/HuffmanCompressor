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
#include <errno.h>
#include "octet.h"

void decodageCodeBinaire(CB_CodeBinaire cbAdecoder, ArbreDeHuffman adh, O_Octet* octet, int* trouve){
  ArbreDeHuffman adhtemp = adh;
  *trouve=false;

  for(int i=0;i<CB_longueur(cbAdecoder);i++){
      if(CB_obtenirBit(cbAdecoder,i+1)==bitA0){
        adhtemp=ADH_obtenirFilsGauche(adhtemp);
      }
      else {
        adhtemp = ADH_obtenirFilsDroit(adhtemp);
      }
  }
  if(ADH_estUneFeuille(adhtemp)){
    *octet=ADH_obtenirCaractere(adhtemp);
    *trouve=true;
  }
}
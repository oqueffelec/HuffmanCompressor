/**
  * \file creerFileDePriorite.c
  * \brief création de la file de priorité à partir des statistiques
  * \author Quentin Robcis
  * \version 1.0
  * \date 29/12/2016
  */

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "statistiques.h"
#include "FileDePriorite.h"
#include "octet.h"

FDP_FileDePriorite creerFileDePriorite(STAT_Statistiques stats){
  FDP_FileDePriorite fileDePriorite=FDP_fileDePriorite();
  ArbreDeHuffman feuille;

  for (unsigned int i=0; i<STAT_SIZE; i++) {
    if (STAT_estPresentOctet(stats,i)){
      feuille = ADH_arbreDeHuffman(stats.valeur[i],O_decimalEnOctet(i));
      FDP_enfilerADH(&fileDePriorite,feuille);
    }
  }
  return (fileDePriorite);
}

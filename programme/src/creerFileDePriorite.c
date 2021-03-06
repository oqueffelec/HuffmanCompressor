/**
  * \file creerFileDePriorite.c
  * \brief creation de la file de priorite a partir des statistiques
  * \author Quentin Robcis
  * \version 1.0
  * \date 29/12/2016
  */

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Statistiques.h"
#include "FileDePriorite.h"
#include "Octet.h"

FDP_FileDePriorite creerFileDePriorite(STAT_Statistiques stats){
  FDP_FileDePriorite fileDePriorite=FDP_fileDePriorite();
  ArbreDeHuffman feuille;

  for (unsigned int i=0; i<STAT_SIZE; i++) {
    if (STAT_estPresentOctet(stats,O_decimalEnOctet(i))){
      feuille = ADH_arbreDeHuffman(STAT_obtenirPonderation(stats,O_decimalEnOctet(i)),O_decimalEnOctet(i));
      FDP_enfilerADH(&fileDePriorite,feuille);
    }
  }
  return (fileDePriorite);
}

/**
  * \file compression.c
  * \brief compression du fichier source
  * \author Octave Queffelec
  * \version 1.0
  * \date 20/12/2016
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
#include <errno.h>
#include "creerStatistiques.h"
#include "creerTableDeCodage.h"
#include "enTete.h"
#include "codage.h"
#include "octet.h"


#define TRUE 1
#define FALSE 0

void compression(FB_FichierBinaire fichierSource, FB_FichierBinaire* fichierDest){
  STAT_Statistiques stat= creerStatistiques(fichierSource);
  TDC_TableDeCodage tdc= creerTableDeCodage(stat);
  enTete(fichierSource, fichierDest, stat);
  codage(fichierSource, fichierDest, tdc);
}

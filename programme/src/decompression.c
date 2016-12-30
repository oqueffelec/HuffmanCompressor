/**
  * \file decompression.c
  * \brief decompression du fichier huffman
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
#include "decodage.h"
#include "recupererDonnees.h"


#define TRUE 1
#define FALSE 0

void decompression(FB_FichierBinaire fichierSource, FB_FichierBinaire* fichierDest){
  STAT_Statistiques stat =STAT_statistiques();
  CB_CodeBinaire cb = CB_codeBinaire();
  int longueur;

  recupererDonnees(fichierSource,&stat,&longueur,&cb);
  decodage(cb,fichierDest,stat);
}

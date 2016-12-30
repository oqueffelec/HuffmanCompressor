/**
  * \file enTete.c
  * \brief Ecriture de l'enTete dans le fichier
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
#include "octet.h"


#define TRUE 1
#define FALSE 0

void enTete(FB_FichierBinaire fichierSource, FB_FichierBinaire* fichierDest, STAT_Statistiques stat){
  int longueur = FB_longueurFichier(fichierSource);
  char* identifiant= "Huffman";
  O_Octet o=O_octetZero();

  FB_ecrireChaine(fichierDest, identifiant);
  FB_ecrireNaturel(fichierDest, longueur);


  for(int i=0;i<STAT_SIZE;i++){
    FB_ecrireNaturel(fichierDest, STAT_obtenirPonderation(stat,O_decimalEnOctet(i)));
  }
}

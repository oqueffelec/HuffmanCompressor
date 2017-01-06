/**
  * \file recupererDonnees.c
  * \brief Recuperation des stats, longueur du fichier source, verif de l'identifiant, recup des données compress
  * \author Octave Queffelec
  * \version 1.0
  * \date 20/12/2016
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
#include "Octet.h"


#define TRUE 1
#define FALSE 0

int estFichierHuffman(FB_FichierBinaire fichierSource){
  char* huffman = "huffman";
  char* id = FB_lireChaine(fichierSource,7);
  id[7]='\0';
  if(strcmp(id,huffman)==0){
    return TRUE;
  }
  else{
    return FALSE;
  }
}

void recupererLongueur(FB_FichierBinaire fichierSource, int* longueur){
  FB_lireNaturel(fichierSource,longueur);
}

void recupererStatistiques(FB_FichierBinaire fichierSource, STAT_Statistiques* stat){
  int iStat=0;
  for(int i=0;i<STAT_SIZE;i++){
    FB_lireNaturel(fichierSource, &iStat);
    for(int j=0;j<iStat;j++){
    STAT_ajouter(stat,O_decimalEnOctet(i));
    }
  }
}

void recupererDonnees(FB_FichierBinaire fichierSource, STAT_Statistiques* stat, int* longueur){
  assert(estFichierHuffman(fichierSource));
  recupererLongueur(fichierSource, longueur);
  recupererStatistiques(fichierSource,stat);
}

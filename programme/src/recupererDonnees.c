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
#include "statistiques.h"
#include "codeBinaire.h"
#include "tableDeCodage.h"
#include "fichierBinaire.h"
#include <errno.h>
#include "octet.h"


#define TRUE 1
#define FALSE 0

int estFichierHuffman(FB_FichierBinaire fichierSource){
  char* huffman = "Huffman";
  char* id = FB_lireChaine(fichierSource,7);
  if(strcmp(id,huffman)==0){
    return TRUE;
  }
  else{
    return FALSE;
  }
}

void recupererLongueur(FB_FichierBinaire fichierSource, int* longueur){
  FB_lireNaturel(fichierSource,&longueur);
}

void recupererStatistiques(FB_FichierBinaire fichierSource, STAT_Statistiques* stat){
  int iStat=0;
  for(int i=0;i<STAT_SIZE;i++){
    FB_lireNaturel(fichierSource, &iStat);
    STAT_ajouter(stat,O_decimalEnOctet(iStat));
  }
}

void recupererCodeBinaire(FB_FichierBinaire fichierSource, CB_CodeBinaire* cb){
  O_Octet octetSource=O_octetZero();
  while(FB_finFichier(fichierSource)==0 &&  FB_lireOctet(fichierSource,&octetSource)){
    FB_lireOctet(fichierSource,&octetSource);
    for(int i=0; i<8; i++){
      CB_ajouter(cb,O_obtenirbit(octetSource,i));
    }
  }
}

void recupererDonnees(FB_FichierBinaire fichierSource, STAT_Statistiques* stat, int* longueur, CB_CodeBinaire* cb){
  assert(estFichierHuffman(fichierSource));
  recupererLongueur(fichierSource, longueur);
  recupererStatistiques(fichierSource,stat);
  recupererCodeBinaire(fichierSource,cb);
}

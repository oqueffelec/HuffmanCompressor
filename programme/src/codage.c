/**
  * \file codeBinaireEnFichier.c
  * \brief Ecriture du codebinaire dans le fichier compressé
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

void codage(FB_FichierBinaire source, FB_FichierBinaire* dest, TDC_TableDeCodage tdc){
  O_Octet octetSource;
  O_Octet octetDest=O_octetZero();

  while(!FB_finFichier(source) &&  FB_lireOctet(source,&octetSource)){
    CB_CodeBinaire code= TDC_obtenirCodeBinaire(tdc,octetSource);
    for(int i=0;i<CB_longueur(code);i++){
      O_ajouter(&octetDest,CB_obtenirBit(code,i));
    }
    if(O_estRempli(octetDest)){
      FB_ecrireOctet(dest,octetDest);
      octetDest=O_octetZero();
    }
    else{
      while(!O_estRempli(octetDest)){
        O_ajouter(&octetDest,bitA0);
        FB_ecrireOctet(dest,octetDest);
      }
    }
  }
}


/*

void codageBis(FB_FichierBinaire source, FB_FichierBinaire* dest, TDC_TableDeCodage tdc){
  CB_CodeBinaire codeCumule= CB_codeBinaire();
  O_Octet octetAecrire= O_octetZero();
  O_Octet octetSource= O_octetZero();
  while(!FB_finFichier(source) &&  FB_lireOctet(source,&octetSource)){
    FB_lireOctet(source,&octetSource);
    CB_CodeBinaire code= TDC_obtenirCodeBinaire(tdc,octetSource);
    for(int i=1; i<= CB_longueur(code);i++){
      CB_ajouter(&codeCumule,CB_obtenirBit(code,i));
      }
    }
    int i;
    for( i=0; i< CB_longueur(codeCumule)/8;i++){
      for(int j=1; j<=8;j++)
        O_ajouter(&octetAecrire,CB_obtenirBit(codeCumule,8*i+j));
      FB_ecrireOctet(dest,octetAecrire);
      octetAecrire= O_octetZero();
    }
    int bitrestant= CB_longueur(codeCumule)-i*8;
    for(int k=0; k<bitrestant;k++)
      O_ajouter(&octetAecrire,CB_obtenirBit(codeCumule,i*8+k));
    FB_ecrireOctet(dest,octetAecrire);
  }
*/

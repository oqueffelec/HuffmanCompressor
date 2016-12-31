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
/*
void codage(FB_FichierBinaire source, FB_FichierBinaire* dest, TDC_TableDeCodage tdc){
  O_Octet octetSource;
  O_Octet octetDest=O_octetZero();
  CB_CodeBinaire code= CB_codeBinaire();
  FB_deplacerCurseur(&source,0);


  while(FB_finFichier(source)==0 &&  FB_lireOctet(source,&octetSource)){
    FB_lireOctet(source,&octetSource);
    code= TDC_obtenirCodeBinaire(tdc,octetSource);
    for(int i=0;i<CB_longueur(code);i++){
      O_ajouter(&octetDest,CB_obtenirBit(code,i+1));
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

*/

void codage(FB_FichierBinaire source, FB_FichierBinaire* dest, TDC_TableDeCodage tdc){
  CB_CodeBinaire codeCumule= CB_codeBinaire();
  O_Octet octetAecrire= O_octetZero();

  // On creer un tab de Octet pour la lecture du fichier

  O_Octet octetSource[FB_longueurFichier(source)];
  for(int i=0; i<FB_longueurFichier(source);i++)
    octetSource[i]=O_octetZero();

    // On recupere les octets qu'on stocke dans un tab d'octet

  FB_lireOctets(source,octetSource,FB_longueurFichier(source));

  // On creer un tab de codeBinaires correspondants au tab d'octet

    CB_CodeBinaire code[FB_longueurFichier(source)];
    for(int i=0; i<FB_longueurFichier(source);i++){
      code[i]=CB_codeBinaire();
      code[i]= TDC_obtenirCodeBinaire(tdc,octetSource[i]);
    }

    // On concatene les cb en un cb, en partant de la fin du tab de cb et en remontant
    for(int j=FB_longueurFichier(source)-1; j>=0;j--){
        codeCumule = CB_concatener(codeCumule,code[j]);
      }

    // On ecris convertit les cb en octet, puis lorsque l'octet est rempli, on l'ecris dans le fichier

    for(int compteur=0; compteur< CB_longueur(codeCumule);compteur++){
      if(O_estRempli(octetAecrire)){
        FB_ecrireOctet(dest,octetAecrire);
        octetAecrire= O_octetZero();
        O_ajouter(&octetAecrire,CB_obtenirBit(codeCumule,compteur+1));
      }
      else{
        O_ajouter(&octetAecrire,CB_obtenirBit(codeCumule,compteur+1));
      }
    }

    // On bourre de zeros les derniers bits du cb ne formant pas forcement un octet complet

    while(O_nombreBit(octetAecrire)!=0 && O_nombreBit(octetAecrire)<8){
      O_ajouter(&octetAecrire,bitA0);
      }
    FB_ecrireOctet(dest,octetAecrire);
    
    }

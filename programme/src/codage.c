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
  CB_CodeBinaire codeCumule= CB_codeBinaire();
  O_Octet octetAecrire= O_octetZero();
  O_Octet octetAlire= O_octetZero();


  FB_deplacerCurseur(&source,0);
  while(FB_lireOctet(source,&octetAlire)==1 && FB_finFichier(source)==0){
    FB_lireOctet(source,&octetAlire);
    CB_CodeBinaire code = CB_codeBinaire();
    code = TDC_obtenirCodeBinaire(tdc,octetAlire);
    CB_concatener(&codeCumule,code); // SEG FAULT je ne sais pas pq
  }
    // On ecris convertit les cb en octet, puis lorsque l'octet est rempli, on l'ecris dans le fichier
    FB_deplacerCurseur(&source,0);

    for(int compteur=0; compteur< CB_longueur(codeCumule);compteur++){
      if(O_estRempli(octetAecrire)){
        FB_ecrireOctet(dest,octetAecrire);
        octetAecrire= O_octetZero();
        O_ajouterEnTete(&octetAecrire,CB_obtenirBit(codeCumule,compteur+1));
      }
      else{
        O_ajouterEnTete(&octetAecrire,CB_obtenirBit(codeCumule,compteur+1));
      }
    }

    // On bourre de zeros les derniers bits du cb ne formant pas forcement un octet complet

    while(O_nombreBit(octetAecrire)!=0 && O_nombreBit(octetAecrire)<8){
      O_ajouterEnTete(&octetAecrire,bitA0);
      }
    FB_ecrireOctet(dest,octetAecrire);
    }

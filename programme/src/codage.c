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

FB_FichierBinaire coder(FB_FichierBinaire source, TDC_TableDeCodage tdc){
  O_Octet octetSource;
  O_Octet octetDest=O_octetZero();
  FB_FichierBinaire fichierDest;

  while(!FB_finFichier(source) &&  FB_lireOctet(source,&octetSource)){
    CB_CodeBinaire code= TDC_obtenirCodeBinaire(tdc,octetSource);
    for(int i=0;i<CB_longueur(code);i++){
      O_ajouter(&octetDest,CB_obtenirBit(code,i));
    }
    if(O_estRempli(octetDest)){
      FB_ecrireOctet(&fichierDest,octetDest);
      octetDest=O_octetZero();
    }
    else{
      while(!O_estRempli(octetDest)){
        O_ajouter(&octetDest,bitA0);
        FB_ecrireOctet(&fichierDest,octetDest);
      }
    }
  }
  return fichierDest;
}

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
#include "CodeBinaire.h"
#include "TableDeCodage.h"
#include "FichierBinaire.h"
#include <errno.h>
#include "Octet.h"
#include "codage.h"



#define TRUE 1
#define FALSE 0


void codage(FB_FichierBinaire source, FB_FichierBinaire* dest, TDC_TableDeCodage tdc){
  O_Octet octetAecrire= O_octetZero();
  O_Octet octetAlire= O_octetZero();

  FB_deplacerCurseur(&source,0);

  while(FB_lireOctet(source,&octetAlire)==1 && FB_finFichier(source)==0){
      CB_CodeBinaire code = CB_codeBinaire();
      code = TDC_obtenirCodeBinaire(tdc,octetAlire);
      for(int i=0; i<CB_longueur(code); i++){
        O_ajouterPoidsFort(&octetAecrire,CB_obtenirBit(code,i+1));
        if(O_estRempli(octetAecrire)){
          FB_ecrireOctet(dest,octetAecrire);
          octetAecrire=O_octetZero();
        }
      }
    }
    bourrageZeros(dest,octetAecrire);
  }

  void bourrageZeros(FB_FichierBinaire* dest, O_Octet octetAecrire){
    if(O_nombreBit(octetAecrire)!=0){
      while(O_nombreBit(octetAecrire)<8){
        O_ajouterPoidsFort(&octetAecrire,bitA0);
        }
      FB_ecrireOctet(dest,octetAecrire);
    }
  }

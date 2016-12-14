/**
  * \file TableDeCodage.c
  * \brief Conception du TAD tableDeCodage
  * \author Octave Queffelec
  * \version 1.0
  * \date 20/11/2016
  */
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "tableDeCodage.h"
#include <errno.h>
#include "codeBinaire.h"
#include "octet.h"


#define TRUE 1
#define FALSE 0

TDC_TableDeCodage TDC_tableDeCodage(){
  TDC_TableDeCodage tdc;
  for(int i=0; i<TDC_SIZE;i++){
    tdc.codeBinaire[i]=NULL;
  }
  return tdc;
}

void TDC_ajouter(TDC_TableDeCodage* tdc, O_Octet* o, CB_CodeBinaire cb){
tdc->codeBinaire[O_octetendecimal(o)]=cb;
}

int TDC_estPresentCodeBinaire(TDC_TableDeCodage tdc, CB_CodeBinaire cb){
  int i=0;
  int estPresent=FALSE;
  while(!estPresent && i<TDC_SIZE){// a changer avec compareCodeBinaire
    if(CB_compareCodeBinaire(tdc.codeBinaire[i],cb))
      estPresent=TRUE;
    else
      i++;
  }
  return estPresent;
}

CB_CodeBinaire TDC_obtenirCodeBinaire(TDC_TableDeCodage tdc, O_Octet* o){
  assert(tdc.codeBinaire[O_octetendecimal(o)]!=NULL);
  return tdc.codeBinaire[O_octetendecimal(o)];
}

//CB_CodeBinaire TDC_obtenirCodeBinaires(TDC_TableDeCodage tdc)

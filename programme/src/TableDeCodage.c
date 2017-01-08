/**
  * \file TableDeCodage.c
  * \brief Conception du TAD tableDeCodage
  * \author Regis Maskemde
  * \version 1.0
  * \date 20/11/2016
  */
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "TableDeCodage.h"
#include "CodeBinaire.h"
#include "Octet.h"


#define TRUE 1
#define FALSE 0

TDC_TableDeCodage TDC_tableDeCodage(){
  TDC_TableDeCodage tdc;
  for(int i=0; i<TDC_SIZE;i++){
    tdc.codeBinaire[i]=NULL;
  }
  return tdc;
}

void TDC_ajouter(TDC_TableDeCodage* tdc, O_Octet o, CB_CodeBinaire cb){
tdc->codeBinaire[O_octetEnDecimal(o)]=cb;
}

int TDC_estPresentCodeBinaire(TDC_TableDeCodage tdc, CB_CodeBinaire cb){
  int i=0;
  int estPresent=FALSE;
  while(!estPresent && i<TDC_SIZE){
    if(CB_compareCodeBinaire(tdc.codeBinaire[i],cb))
      estPresent=TRUE;
    else
      i++;
  }
  return estPresent;
}

CB_CodeBinaire TDC_obtenirCodeBinaire(TDC_TableDeCodage tdc, O_Octet o){
  return tdc.codeBinaire[O_octetEnDecimal(o)];
}

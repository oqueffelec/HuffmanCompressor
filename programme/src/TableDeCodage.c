/**
  * \file TableDeCodage.c
  * \brief Conception du TAD tableDeCodage
  * \author Octave Queffelec
  * \version 1.0
  * \date 20/11/2016
  */

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "TableDeCodage.h"
#include <errno.h>


#define TRUE 1
#define FALSE 0

TDC_TableDeCodage TDC_tableDeCodage(){
  errno=0;
  return NULL;
}

void TDC_ajouter(TDC_TableDeCodage* tdc, int* o, int*cb){
  TDC_TableDeCodage pNoeud=(TDC_TableDeCodage)malloc(sizeof(TDC_Noeud));
  if (pNoeud!=NULL) {
      errno=0;
      pNoeud->octet=o;
      pNoeud->codeBinaire=cb;
      pNoeud->listeSuivante=*tdc;
      *tdc=pNoeud;
  } else {
    errno=TDC_ERREUR_MEMOIRE;
  }
}

int TDC_estPresentOctet(TDC_TableDeCodage tdc, int* o){
  assert(tdc!=NULL);
    if(tdc->octet==o){
      return TRUE;
    }
    else{
      TDC_estPresentOctet(tdc->listeSuivante,o);
    }
    return FALSE;
}

int TDC_estPresentCodeBinaire(TDC_TableDeCodage tdc, int*cb){
    assert(tdc!=NULL);
    if(tdc->codeBinaire==cb){
      return TRUE;
    }
    else{
      TDC_estPresentCodeBinaire(tdc->listeSuivante,cb);
    }
    return FALSE;
}



int* TDC_obtenirOctet(TDC_TableDeCodage tdc, int*cb){
  assert(TDC_estPresentCodeBinaire(tdc,cb));
  assert(tdc!=NULL);
    if(tdc->codeBinaire==cb)
      return tdc->octet;
    else
      return TDC_obtenirOctet(tdc->listeSuivante,cb);
}

int* TDC_obtenirCodeBinaire(TDC_TableDeCodage tdc, int* o){
  assert(TDC_estPresentOctet(tdc,o));
  assert(tdc!=NULL);
    if(tdc->octet==o)
      return tdc->codeBinaire;
    else
      return TDC_obtenirCodeBinaire(tdc->listeSuivante,o);
}

void TDC_retirerOctet(TDC_TableDeCodage* tdc, int* o){
  assert(TDC_estPresentOctet(*tdc,o));
  int* cb=TDC_obtenirCodeBinaire(*tdc,o);
  TDC_TableDeCodage temp;
  assert(tdc!=NULL);
  errno=0;
  temp=*tdc;
  *tdc=(*tdc)->listeSuivante;
  free(temp);

}

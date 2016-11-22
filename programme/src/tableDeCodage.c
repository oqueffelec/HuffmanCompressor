/**
  * \file TableDeCodage.c
  * \brief Conception du TAD TableDeCodage
  * \author Octave Queffelec
  * \version 1.0
  * \date 20/11/2016
  */

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include "TableDeCodage.h"

#define TRUE 1
#define FALSE 0

TDC_TableDeCodage TDC_TableDeCodageVide(){
  errno=0;
  return NULL;
}

void TDC_ajouter(TDC_TableDeCodage* tdc, Octet o, CodeBinaire cb){
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

int TDC_estPresentOctet(TDC_TableDeCodage tdc, Octet o){
  if(tdc->listeSuivante!=NULL){
    if(tdc->octet==o){
      return TRUE;
    }
    else{
      return TDC_estPresentOctet(tdc->listeSuivante,o);
    }
  }
  else
    return FALSE;
}

int TDC_estPresentCodeBinaire(TDC_TableDeCodage tdc, CodeBinaire cb){
  if(tdc->listeSuivante!=NULL){
    if(tdc->codeBinaire==cb){
      return TRUE;
    }
    else{
      return TDC_estPresentOctet(tdc->listeSuivante,cb);
    }
  }
  else
    return FALSE;
}



Octet TDC_obtenirOctet(TDC_TableDeCodage tdc, CodeBinaire cb){
  assert(TDC_estPresentCodeBinaire(tdc,cb));
    if(tdc->codeBinaire==cb)
      return tdc->octet;
    else
      return TDC_obtenirOctet(tdc->listeSuivante,cb);
}

CodeBinaire TDC_obtenirCodeBinaire(TDC_TableDeCodage tdc, Octet o){
  assert(TDC_estPresentOctet(tdc,o));
    if(tdc->octet==o)
      return tdc->codeBinaire;
    else
      return TDC_obtenirCodeBinaire(tdc->listeSuivante,o);
}

void TDC_retirerOctet(TDC_TableDeCodage* tdc, Octet o){
  assert(TDC_estPresentOctet(*tdc,o));
  CodeBinaire cb=TDC_obtenirCodeBinaire(*tdc,o);
  TDC_TableDeCodage temp;
  assert(tdc!=NULL);
  errno=0;
  temp=*tdc;
  *tdc=(*tdc)->listeSuivante;
  free(temp);

}

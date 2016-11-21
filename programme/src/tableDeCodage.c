/**
  * \file tableDeCodage.c
  * \brief Conception du TAD tableDeCodage
  * \author Octave Queffelec
  * \version 1.0
  * \date 20/11/2016
  */

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include "tableDeCodage.h"

#define TRUE 1
#define FALSE 0

TDC_tableDeCodage TDC_tableDeCodageVide(){
  errno=0;
  return NULL;
}

void TDC_ajouter(TDC_tableDeCodage* tdc, octet o, codeBinaire cb){
  TDC_tableDeCodage pNoeud=(TDC_tableDeCodage)malloc(sizeof(TDC_Noeud));
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

int TDC_estPresentOctet(TDC_tableDeCodage tdc, octet o){
  if(tdc.listeSuivante!=NULL){
    if(tdc.octet==o){
      return TRUE;
    }
    else{
      TDC_estPresentOctet(tdc.listeSuivante,o);
    }
  }
  else
    return FALSE;
}

int TDC_estPresentCodeBinaire(TDC_tableDeCodage tdc, codeBinaire cb){
  if(tdc.listeSuivante!=NULL){
    if(tdc.codeBinaire==cb){
      return TRUE;
    }
    else{
      TDC_estPresentOctet(tdc.listeSuivante,cb);
    }
  }
  else
    return FALSE;
}



octet TDC_obtenirOctet(TDC_tableDeCodage tdc, codeBinaire cb){
  assert(TDC_estPresentCodeBinaire(tdc,cb));
  if(tdc.listeSuivante!=NULL){
    if(tdc.codeBinaire==cd)
      return tdc.octet;
    else
      TDC_obtenirOctet(tdc.listeSuivante,cb);
  }
}

codeBinaire TDC_obtenirCodeBinaire(TDC_tableDeCodage tdc, octet o){
  assert(TDC_estPresentOctet(tdc,o));
  if(tdc.listeSuivante!=NULL){
    if(tdc.octet==o)
      return tdc.codeBinaire;
    else
      TDC_obtenirCodeBinaire(tdc.listeSuivante,cb);
  }
}

void TDC_retirerOctet(TDC_tableDeCodage* tdc, octet o){
  assert(TDC_estPresentOctet(tdc,o));
  codeBinaire cb=TDC_obtenirCodeBinaire(tdc,o);
  TDC_tableDeCodage temp;
  assert(tdc!=NULL);
  errno=0;
  temp=*tdc;
  *tdc=tdc->listeSuivante;
  free(temp);

}

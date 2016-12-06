/**
  * \file codeBinaire.c
  * \brief Conception du TAD codeBinaire
  * \author Wacyk Jean-Gabriel
  * \version 1.0
  * \date 5/12/2016
  */

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "bit.h"
#include <errno.h>


#define TRUE 1
#define FALSE 0

CB_CodeBinaire CB_codeBinaire(){
  errno=0;
  return NULL;
}

void CB_ajouter(CB_CodeBinaire* cb, Bit* b){
  CB_CodeBinaire pNoeud=(CB_CodeBinaire)malloc(sizeof(CB_Noeud));
  if (pNoeud!=NULL) {
      errno=0;
      pNoeud->bit=b;
      pNoeud->listeSuivante=*tdc;
      *tdc=pNoeud;
  } else {
    errno=TDC_ERREUR_MEMOIRE;
  }
}

Bit* CB_obtenirbit(CB_CodeBinaire cb, int pos){
  assert(tdc!=NULL);
  if(pos==1){
    return cb->bit;
  }
  else{
    return CB_obtenirbit(cb->listeSuivante,pos-1);
  }
}

void CB_suprimerTete(CB_CodeBinaire* cb){
  CB_CodeBinaire temp;
  assert(tdc!=NULL);
  errno=0;
  temp=*cb;
  *tdc=(*tdc)->listeSuivante;
  free(temp);
}

void CB_suprimer(CB_CodeBinaire* cb){
  erno=0;
  if(cb!=NULL){
    CB_suprimerTete(cb);
    CB_suprimer(cb);
  }
}

int CB_longueur(CB_CodeBinaire cb){
  if(cb!=NULL){
    return 0
  }
  else{
    return 1+CB_longueur(cb->listeSuivante)
  }
  
}

int CB_compareCodeBinaire(CB_CodeBinaire cb1, CB_CodeBinaire cb2){
  if((cb1==NULL && cb2!=NULL) || (cb1!=NULL && cb2==NULL))){
    return FALSE;
  }
 else if((CB_obtenirbit(cb1,1)!=CB_obtenirbit(cb2,1)){
	return FALSE;
   }
   else if (cb1==NULL && cb2==NULL){
     return TRUE;
   }
   else{
     return CB_compareCodeBinaire(cb1->listeSuivante,cb2->listeSuivante);
   }
}

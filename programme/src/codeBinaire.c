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
#include "codeBinaire.h"
#include <errno.h>


#define TRUE 1
#define FALSE 0

CB_CodeBinaire CB_codeBinaire(){
  errno=0;
  return NULL;
}

void CB_ajouter(CB_CodeBinaire* cb, Bit b){
  CB_CodeBinaire pNoeud=(CB_CodeBinaire)malloc(sizeof(CB_Noeud));
  if (pNoeud!=NULL) {
      errno=0;
      pNoeud->bit=b;
      pNoeud->listeSuivante=*cb;
      *cb=pNoeud;
  } else {
    errno=TDC_ERREUR_MEMOIRE;
  }
}

Bit CB_obtenirBit(CB_CodeBinaire cb, unsigned int pos){
  assert(pos>0);
  assert(cb!=NULL);
  if(pos==1){
    return cb->bit;
  }
  else{
    return CB_obtenirbit(cb->listeSuivante,pos-1);
  }
}

void CB_supprimerTete(CB_CodeBinaire* cb){
  CB_CodeBinaire temp;
  assert(cb!=NULL);
  errno=0;
  temp=*cb;
  *cb=(*cb)->listeSuivante;
  free(temp);
}

void CB_supprimer(CB_CodeBinaire* cb){
  errno=0;
  if(*cb!=NULL){
    CB_supprimerTete(cb);
    CB_supprimer(cb);
  }
}

int CB_longueur(CB_CodeBinaire cb){
  if(cb==NULL){
    return 0;
  }
  else{
    return 1+CB_longueur(cb->listeSuivante);
  }

}

int CB_compareCodeBinaire(CB_CodeBinaire cb1, CB_CodeBinaire cb2){
  if (cb1==NULL && cb2==NULL)
    return TRUE;
  else{
    if((cb1==NULL && cb2!=NULL) || (cb1!=NULL && cb2==NULL))
      return FALSE;
    else{
      if((CB_obtenirbit(cb1,1)!=CB_obtenirbit(cb2,1)))
     	  return FALSE;
        else{
           return CB_compareCodeBinaire(cb1->listeSuivante,cb2->listeSuivante);
          }
        }
      }
    }

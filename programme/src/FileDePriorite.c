#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include "FileDePriorite.h"
#include "ArbreDeHuffman.h"

// Partie Privée

void FDP_ajouter(FDP_FileDePriorite* fdp, ArbreDeHuffman a){
  FDP_FileDePriorite f=(FDP_FileDePriorite)malloc(sizeof(FDP_FileDePriorite));
  if(f!=NULL){
    errno=0;
    f->arbre=a;
    f->fileSuivante=*fdp;
    *fdp=f;
  }
  else{
    errno=FDP_ERREUR_MEMOIRE;
  }
}

FDP_FileDePriorite FDP_obtenirFileSuivante(FDP_FileDePriorite fdp){
  assert(!FDP_estVide(fdp));
  return fdp->fileSuivante;
}

void FDP_fixerFileSuivante(FDP_FileDePriorite* fdp1, FDP_FileDePriorite fdp2){
  assert(!FDP_estVide(*fdp1));
  (*fdp1)->fileSuivante=fdp2;
}

// Partie Publique


FDP_FileDePriorite FDP_fileDePriorite() {
  return NULL;
}



int FDP_estVide(FDP_FileDePriorite fdp){
  return fdp==NULL;
}


void FDP_enfilerADH(FDP_FileDePriorite* fdp, ArbreDeHuffman a){
  FDP_FileDePriorite temp = FDP_fileDePriorite();
  if (FDP_estVide(*fdp) || ADH_obtenirPonderation(FDP_obtenirADH(*fdp)) >= ADH_obtenirPonderation(a)) {
    FDP_ajouter(fdp,a);
  }
  else {
    temp = FDP_obtenirFileSuivante(*fdp);
    FDP_enfilerADH(&temp,a);
    FDP_fixerFileSuivante(fdp,temp);
  }
}

ArbreDeHuffman FDP_obtenirADH(FDP_FileDePriorite fdp){
  assert(!FDP_estVide(fdp));
  return fdp->arbre;
}

int FDP_longueur(FDP_FileDePriorite fdp) {
  int res = 0;
  FDP_FileDePriorite temp = fdp;
  while (!FDP_estVide(temp)) {
    temp = FDP_obtenirFileSuivante(temp);
    res++;
  }
  return res;
}

void FDP_defilerADH(FDP_FileDePriorite* fdp){
  FDP_FileDePriorite temp;
  assert(!FDP_estVide(*fdp));
  errno=0;
  temp=*fdp;
  *fdp=(*fdp)->fileSuivante;
  free(temp);
}

/**
  * \file Statistiques.c
  * \brief Conception du TAD Statistiques
  * \author Mathieu Vandecasteele
  * \version 1.0
  * \date 26/11/2016
  */

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "Statistiques.h"
#include <errno.h>


#define TRUE 1
#define FALSE 0

STAT_Statistiques STAT_statistiques(){
  errno=0;
  return NULL;
}

void STAT_ajouterElement(STAT_Statistiques* stat, int*o, unsigned long int*naturel){
  STAT_Statistiques pNoeud=(STAT_Statistiques)malloc(sizeof(STAT_Noeud));
  if (pNoeud!=NULL) {
      errno=0;
      pNoeud->octet=o;
      pNoeud->naturel=cb;
      pNoeud->listeSuivante=*stat;
      *stat=pNoeud;
  } else {
    errno=STAT_ERREUR_MEMOIRE;
  }
}

int STAT_estPresentOctet(STAT_Statistiques stat, int*o){
  assert(stat!=NULL);
    if(stat->octet==o){
      return TRUE;
    }
    else{
      STAT_estPresentOctet(stat->listeSuivante,o);
    }
    return FALSE;
}

int STAT_estPresentNaturel(STAT_Statistiques stat, unsigned long int*nat){
    assert(stat!=NULL);
    if(stat->naturel==nat){
      return TRUE;
    }
    else{
      STAT_estPresentNaturel(stat->listeSuivante,nat);
    }
    return FALSE;
}

int* STAT_obtenirOctet(STAT_Statistiques stat, unsigned long int*nat){
  assert(STAT_estPresentNaturel(stat,nat));
  assert(stat!=NULL);
    if(stat->naturel==nat)
      return stat->octet;
    else
      return STAT_obtenirOctet(stat->listeSuivante,nat);
}

unsigned long int* STAT_obtenirValeur(STAT_Statistiques stat, int*o);{
  assert(STAT_estPresentOctet(stat,o));
  assert(stat!=NULL);
    if(stat->octet==o)
      return stat->naturel;
    else
      return STAT_obtenirValeur(stat->listeSuivante,o);
}

void STAT_obtenirValeurs(STAT_Statistiques* stat){
}

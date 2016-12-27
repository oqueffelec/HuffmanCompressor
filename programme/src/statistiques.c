/**
  * \file statistiques.c
  * \brief Conception du TAD Statistiques
  * \author Mathieu Vandecasteele
  * \version 1.0
  * \date 20/11/2016
  */
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "statistiques.h"
#include <errno.h>
#include "octet.h"


#define TRUE 1
#define FALSE 0

STAT_Statistiques STAT_statistiques(){
  STAT_Statistiques stat;
  for(int i=0; i<STAT_SIZE;i++){
    stat.valeur[i]=0;
  }
  return stat;
}

void STAT_ajouter(STAT_Statistiques* stat, O_Octet o){
stat->valeur[O_octetendecimal(o)]=STAT_obtenirPonderation(*stat,o)+1;
}

int STAT_estPresentPonderation(STAT_Statistiques stat, unsigned long int pond){
  int i=0;
  int estPresent=FALSE;
  while ((!estPresent) && (i<STAT_SIZE)){
    if (stat.valeur[i] == pond){
      estPresent=TRUE;
    }
    else{
      i++;
    }
  }
  return estPresent;
}

unsigned long int STAT_obtenirPonderation(STAT_Statistiques stat, O_Octet o){
  return stat.valeur[O_octetendecimal(o)];
}

/*STAT_ListeOctets STAT_obtenirOctets(STAT_Statistiques stat)
STAT_ListesOctets Liste;
Liste.o = O_Octet(0,0,0,0,0,0,0,0)
if (Liste.listeSuivante = NULL){
return Liste;}
else {
return STAT_obtenirOctets()

}*/

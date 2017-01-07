/**
  * \file Statistiques.c
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
#include "Statistiques.h"
#include "Octet.h"


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
stat->valeur[O_octetEnDecimal(o)]=STAT_obtenirPonderation(*stat,o)+1;
}

int STAT_estPresentOctet(STAT_Statistiques stat, O_Octet octet){
  int estPresent=FALSE;
  if (STAT_obtenirPonderation(stat,octet) != 0){
    estPresent=TRUE;
  }
  return (estPresent);
}

unsigned long int STAT_obtenirPonderation(STAT_Statistiques stat, O_Octet o){
  return stat.valeur[O_octetEnDecimal(o)];
}

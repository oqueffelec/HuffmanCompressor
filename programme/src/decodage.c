/**
  * \file decodage.c
  * \brief Décompression et écriture des donnée dans un fichier
  * \author Jean-Gabriel Wacyk
  * \version 1.0
  * \date 30/12/2016
  */
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "statistiques.h"
#include "codeBinaire.h"
#include "tableDeCodage.h"
#include "fichierBinaire.h"
#include "creerTableDeCodage.h"
#include <errno.h>
#include "octet.h"

void decodage(CB_CodeBinaire donne,FB_FichierBinaire* dest,STAT_Statistiques stats){
  FDP_FileDePriorite file = creerFileDePriorite(stats);
  ArbreDeHuffman arbre = creerAbreDeHuffman(file);
  ArbreDeHuffman temp = arbre;
  while (!(CB_longueur(donne)==0)) {
    while (!(ADH_estUneFeuille(temp)==1)) {
      if (CB_obtenirBit(donne,1)==bitA0){
        temp = ADH_obtenirFilsGauche(temp);
      }
      else{
        temp = ADH_obtenirFilsDroit(temp);
      }
      CB_supprimerTete(&donne);
    }
    FB_ecrireOctet(dest,ADH_obtenirCaractere(temp));
    temp = arbre;
  }
}

/**
 * \file creerTableDeCodage.c
 * \brief Implantation de la fonction creerTableDeCodage : crée la table de codage correspondante au statistiques donnés.
 * \author Jean-Gabriel Wacyk
 * \version 1.0
 * \date 26/12/2016
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "octet.h"
#include "statistiques.h"
#include "creerTableDeCodage.h"
#include "codeBinaire.h"
#include "FileDePriorite.h"
#include "creerFileDePriorite.h"
#include "tableDeCodage.h"


ArbreDeHuffman creerAbreDeHuffman(FDP_FileDePriorite file){
  ArbreDeHuffman temp;
  ArbreDeHuffman arbre1;
  ArbreDeHuffman arbre2;
  while (!(FDP_longueur(file)==1)) {
    arbre1 = FDP_obtenirADH(file);
    FDP_defilerADH(&file);
    arbre2 = FDP_obtenirADH(file);
    FDP_defilerADH(&file);
    temp = ADH_ajouterRacine(arbre1,arbre2);
    FDP_enfilerADH(&file,temp);
  }
  return temp;
}

void remplirTableDeCodage(TDC_TableDeCodage* tdc, ArbreDeHuffman arbre, CB_CodeBinaire* code){
  if (ADH_estUneFeuille(arbre)==1){
    CB_CodeBinaire temp = CB_copie(*code);
    TDC_ajouter(tdc,ADH_obtenirCaractere(arbre),temp);
    CB_supprimerTete(code);
  }
  else{
    CB_ajouter(code,bitA0);
    remplirTableDeCodage(tdc,ADH_obtenirFilsGauche(arbre),code);
    CB_ajouter(code,bitA1);
    remplirTableDeCodage(tdc,ADH_obtenirFilsDroit(arbre),code);
    if (!(CB_longueur(*code)==0)){
      CB_supprimerTete(code);
    }
  }
}

TDC_TableDeCodage creerTableDeCodage(STAT_Statistiques stats){
  CB_CodeBinaire code = CB_codeBinaire();
  TDC_TableDeCodage res = TDC_tableDeCodage();
  FDP_FileDePriorite file = creerFileDePriorite(stats);
  ArbreDeHuffman arbre = creerAbreDeHuffman(file);
  remplirTableDeCodage(&res,arbre,&code);
  return res;
}

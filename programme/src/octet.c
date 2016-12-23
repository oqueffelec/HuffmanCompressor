/**
  * \file Octet.c
  * \brief Conception du TAD codeBinaire
  * \author Wacyk Jean-Gabriel
  * \version 1.0
  * \date 5/12/2016
  */

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include "octet.h"

#define TRUE 1
#define FALSE 0

// Partie Privée

int puissance2(int n){
  if(n==0)
    return 1;
  else{
    unsigned char res=1;
    for(int i=1;i<=n;i++){
      res=res*2;
    }
    return res;
  }

}

// Partie publique

O_Octet O_octetZero(){
  O_Octet o;
  o = 0;
  return o;
  }

Bit O_obtenirbit(O_Octet o, int pos){
  unsigned char temp;
  temp = o;
  for (int i=0;i<(8-pos-1);i++){
    if (temp >= puissance2(7-i)){
      temp=temp - puissance2(7-i);
    }
  }
  if (temp >= puissance2(pos)){
    return bitA1;
  }
  else{
    return bitA0;
    }
}



void O_ajouter(O_Octet* o,Bit bit,int pos){
  if ((bit == bitA1) && (O_obtenirbit(*o,pos)==bitA0)){
    *o = *o + puissance2(pos);
    }
  if ((bit == bitA0) && (O_obtenirbit(*o,pos)==bitA1)) {
    *o = *o - puissance2(pos);
    }
}

O_Octet O_octet(CB_CodeBinaire cb){
  assert(CB_longueur(cb)==8);
  O_Octet res;
  res = O_octetZero();
  int i;
  for (i=0;i<8;i++)
    {
      O_ajouter(&res,CB_obtenirbit(cb,i+1),i);
    }
  return res;

}

O_Octet O_octetParBit(Bit bit0, Bit bit1, Bit bit2, Bit bit3,Bit bit4, Bit bit5, Bit bit6, Bit bit7){
  O_Octet res;
  O_ajouter(&res,bit0,0);
  O_ajouter(&res,bit1,1);
  O_ajouter(&res,bit2,2);
  O_ajouter(&res,bit3,3);
  O_ajouter(&res,bit4,4);
  O_ajouter(&res,bit5,5);
  O_ajouter(&res,bit6,6);
  O_ajouter(&res,bit7,7);
  return res;
}





int O_octetendecimal(O_Octet o){
  int res=0;
  res = (int)o;
  // Autre méthode indépendante de la représentation d'un Octet mais plus lourde
  //for (int i=0;i<8;i++){
      //if (O_obtenirbit(o,i)==bitA1){
	       //res=res+puissance2(i);
	      //}
    //}
  return res;
}

int O_comparerOctet(O_Octet o1,O_Octet o2){
  return o1==o2;
}

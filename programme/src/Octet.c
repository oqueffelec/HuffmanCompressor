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
#include "Octet.h"

#define TRUE 1
#define FALSE 0

// Partie Privée

int puissance2(int n){
  if(n==0)
    return 1;
  else{
    int res=1;
    for(int i=1;i<=n;i++){
      res=res*2;
    }
    return res;
  }

}

// Partie publique

O_Octet* O_octetZero(){
  O_Octet* o;
  for(int i=0;i<8;i++)
    O_ajouter(o,bitA0,i);
  return o;
  }



void O_ajouter(O_Octet* o,Bit bit,int pos){
  (*o)[7-pos]=bit;
}

O_Octet* O_octet(CB_CodeBinaire cb){
  assert(CB_longueur(cb)==8);
  O_Octet* res=(O_Octet*)malloc(sizeof(O_Octet));
  int i;
  for (i=1;i<9;i++)
    {
      O_ajouter(res,CB_obtenirbit(cb,i),i);
      //(*res)[i]=CB_obtenirbit(cb,i);
    }
  return res;

}

O_Octet* O_octetparbit(Bit bit0, Bit bit1, Bit bit2, Bit bit3,Bit bit4, Bit bit5, Bit bit6, Bit bit7){
  O_Octet* res=(O_Octet*)malloc(sizeof(O_Octet));
  (*res)[0]=bit0;
  (*res)[1]=bit1;
  (*res)[2]=bit2;
  (*res)[3]=bit3;
  (*res)[4]=bit4;
  (*res)[5]=bit5;
  (*res)[6]=bit6;
  (*res)[7]=bit7;
  return res;
}

Bit O_obtenirbit(O_Octet* o, int pos){
  return (*o)[pos];
}



int O_octetendecimal(O_Octet* o){
  int res=0;
  for (int i=0;i<8;i++){
      if (O_obtenirbit(o,i)==bitA1){
	       res=res+puissance2(i);
	      }
    }
  return res;
}

int O_comparerOctet(O_Octet* o1,O_Octet* o2){
  int res;
  int i;
  i=0;
  res=TRUE;
  while(res && i<8)
    {
      if (O_obtenirbit(o1,i)!=O_obtenirbit(o2,i))
	{
	  res=FALSE;
	}
      i++;
	}
  return res;
}

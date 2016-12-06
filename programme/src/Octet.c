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

#define TRUE 1
#define FALSE 0

void O_ajouter(O_Octet* o,Bit bit,int pos){
  o[pos]=bit;
}

O_Octet* O_octet(CB_CodeBinaire cb){
  O_Octet res;
  int i;
  for (i=0;i<8;i++)
    {
      res[i]=obtenirbit(cb,i);
    }
  return res;

}

Bit O_obtenirbit(O_Octet* o, int pos){
  return o[pos];
}

int O_octetendecimal(O_Octet* o){
  int res;
  int i;
  int puissance;
  puissance=1;
  for (i=0;1<8;i++)
    {
      if (O_obtenirbit(o,i)==1){
	res=res+puissance;
	  }
      puissance=puissance*2;
    }
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
      i++
	}
  return res;
}


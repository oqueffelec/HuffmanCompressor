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
#include <math.h>
#include "octet.h"

#define TRUE 1
#define FALSE 0

int O_nombreBit(O_Octet o){
  return o.nb;
}

unsigned char O_getOctet(O_Octet o){
  return o.octet;
}

int O_estRempli(O_Octet o){
  return O_nombreBit(o)==8;
}

O_Octet O_octetZero(){
  O_Octet o;
  o.octet = 0;
  o.nb=0;
  return o;
  }

Bit O_obtenirbit(O_Octet o, int pos){
  assert(O_nombreBit(o)>=pos);
  unsigned char temp;
  temp = O_getOctet(o);
  for (int i=0;i<(8-pos-1);i++){
    if (temp >= pow(2,7-i)){
      temp=temp - pow(2,7-i);
    }
  }
  if (temp >= pow(2,pos)){
    return bitA1;
  }
  else{
    return bitA0;
    }
}



void O_ajouter(O_Octet* o,Bit bit){
  assert(!O_estRempli(*o));
  if(bit==bitA1){
    o->octet= O_getOctet(*o) + pow(2,O_nombreBit(*o));
  }
  o->nb++;
}



int O_octetEnDecimal(O_Octet o){
  int res=0;
  res = (int)O_getOctet(o);
  // Autre méthode indépendante de la représentation d'un Octet mais plus lourde
  //for (int i=0;i<8;i++){
      //if (O_obtenirbit(o,i)==bitA1){
	       //res=res+puissance2(i);
	      //}
    //}
  return res;
}

int O_comparerOctet(O_Octet o1,O_Octet o2){
  return O_nombreBit(o1)==O_nombreBit(o2) && O_getOctet(o1)==O_getOctet(o2) ;
}

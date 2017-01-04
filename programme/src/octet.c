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
#include "puissance.h"

#define TRUE 1
#define FALSE 0

// Partie Privée

unsigned char O_getOctet(O_Octet o){
  return o.octet;
}

// Partie publique

O_Octet O_octetZero(){
  O_Octet o;
  o.octet = 0;
  o.nb=0;
  return o;
  }

int O_nombreBit(O_Octet o){
  return o.nb;
}

int O_estRempli(O_Octet o){
  return O_nombreBit(o)==8;
}

Bit O_obtenirBit(O_Octet o, int pos){
  assert(O_nombreBit(o)>=pos);
  unsigned char temp;
  temp = O_getOctet(o);
  for (int i=0;i<(8-pos-1);i++){
    if (temp >= puissance(2,7-i)){
      temp=temp - puissance(2,7-i);
    }
  }
  if (temp >= puissance(2,pos)){
    return bitA1;
  }
  else{
    return bitA0;
    }
}



void O_ajouterPoidsFaible(O_Octet* o,Bit bit){
  assert(!O_estRempli(*o));
  if(bit==bitA1){
    o->octet= O_getOctet(*o) + puissance(2,O_nombreBit(*o));
  }
  o->nb++;
}

void O_ajouterPoidsFort(O_Octet* o,Bit bit){
  assert(!O_estRempli(*o));
  if(bit==bitA1){
    o->octet= O_getOctet(*o) + puissance(2,7-O_nombreBit(*o));
  }
  o->nb++;
}



int O_octetEnDecimal(O_Octet o){
  int res=0;
  res = (int)O_getOctet(o);
  return res;
}

O_Octet O_decimalEnOctet(int i){
  O_Octet res = O_octetZero();
  res.octet=(unsigned char)i;
  if (i<2){
    res.nb=1;
  }
  if (2<=i && i<4){
    res.nb=2;
  }
  if (4<=i && i<8){
    res.nb=3;
  }
  if (8<=i && i<16){
    res.nb=4;
  }
  if (16<=i && i<32){
    res.nb=5;
  }
  if (32<=i && i<64){
    res.nb=6;
  }
  if (64<=i && i<128){
    res.nb=7;
  }
  if (128<=i && i<256){
    res.nb=8;
  }
  return res;
}

int O_comparerOctet(O_Octet o1,O_Octet o2){
  return O_nombreBit(o1)==O_nombreBit(o2) && O_getOctet(o1)==O_getOctet(o2) ;
}

CB_CodeBinaire O_octetEnCodeBinaire(O_Octet o){
  CB_CodeBinaire cb = CB_codeBinaire();
  int val = O_octetEnDecimal(o);
  if(val==0){
    CB_ajouter(&cb,bitA0);
  }
  else{
    int division;
    int reste;
    while(val/2 != 0){
      division=val/2;
      reste = val-2*division;
      CB_ajouter(&cb,O_obtenirBit(O_decimalEnOctet(reste),0));
      val=division;
    }
    division=val/2;
    reste = val-2*division;
    CB_ajouter(&cb,O_obtenirBit(O_decimalEnOctet(reste),0));
  }
  return cb;
}

O_Octet O_codeBinaireEnOctet(CB_CodeBinaire cb){
  //assert(CB_longueur(cb)==8);
  O_Octet res = O_octetZero();
  for(int i=0;i<8;i++){
    O_ajouterPoidsFaible(&res,CB_obtenirBit(cb,i+1));
  }
    return res;
  }

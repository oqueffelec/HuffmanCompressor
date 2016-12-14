#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "arbreDeHuffman.h"
#include "octet.h"

#define TRUE 1
#define FALSE 0


ArbreDeHuffman ADH_creerArbreDeHuffman(unsigned int ponderation, O_Octet caractere){
  ArbreDeHuffman arbre=(ArbreDeHuffman)malloc(sizeof(ADH_Noeud));
  if (arbre!=NULL){
    errno = 0;
    arbre->ponderation = ponderation;
    memcpy(arbre->caractere,caractere,sizeof(O_Octet));
    arbre->filsG = NULL;
    arbre->filsD = NULL;
    return(arbre);
  }
  else{
    errno = ADH_ERREUR_MEMOIRE;
    return NULL;
  }
}


int ADH_estUneFeuille(ArbreDeHuffman arbre){
  if(((arbre->filsG)==NULL)&&((arbre->filsD)==NULL)){
    return (TRUE);
  }
  else{
    return (FALSE);
  }
}


ArbreDeHuffman ADH_obtenirFilsGauche(ArbreDeHuffman arbre){
  return(arbre->filsG);
}


ArbreDeHuffman ADH_obtenirFilsDroit(ArbreDeHuffman arbre){
  return(arbre->filsD);
}

unsigned int ADH_obtenirPonderation(ArbreDeHuffman arbre){
  return(arbre->ponderation);
}

O_Octet *ADH_obtenirCaractere(ArbreDeHuffman feuille){
  assert(ADH_estUneFeuille(feuille));
  O_Octet *octet=(O_Octet*)malloc(sizeof(O_Octet));
  memcpy(octet,feuille->caractere,sizeof(feuille->caractere));
  return (octet);
}

ArbreDeHuffman ADH_ajouterRacine(ArbreDeHuffman arbre1, ArbreDeHuffman arbre2){
  ArbreDeHuffman arbre=(ArbreDeHuffman)malloc(sizeof(ADH_Noeud));
  if (arbre!=NULL){
    errno=0;
    arbre->ponderation = (arbre1->ponderation)+(arbre2->ponderation);
    memcpy(arbre->caractere,O_octetZero(),sizeof(arbre->caractere));
    if ((arbre1->ponderation)<(arbre2->ponderation)){
      arbre->filsG = arbre2;
      arbre->filsD = arbre1;
    }
    else{
      arbre->filsG = arbre1;
      arbre->filsD = arbre2;
    }
    return(arbre);
  }
  else{
    errno=ADH_ERREUR_MEMOIRE;
    return NULL;
  }
}

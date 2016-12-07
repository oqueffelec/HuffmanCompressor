#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include "arbreDeHuffman.h"

#define TRUE 1
#define FALSE 0
#define ADH_ERREUR_MEMOIRE 1


ArbreDeHuffman creerArbreDeHuffman(unsigned int ponderation, char caractere){
  ArbreDeHuffman *arbre=(ArbreDeHuffman)malloc(sizeof(ADH_Noeud));
  if (arbre!=NULL){
    errno = 0;
    arbre->ponderation = ponderation;
    arbre->caractere = caractere;
    arbre->filsG = NULL;
    arbre->filsD = NULL;
    return(arbre);
  }
  else{
    errno = ADH_ERREUR_MEMOIRE;
  }
}


int estUneFeuille(ArbreDeHuffman arbre){
  if(((arbre->filsG)==NULL)&&((arbre->filsD)==NULL)){
    return (TRUE);
  }
  else{
    return (FALSE);
  }
}


ArbreDeHuffman obtenirFilsGauche(ArbreDeHuffman arbre){
  return(arbre->filsG);
}


ArbreDeHuffman obtenirFilsDroit(ArbreDeHuffman arbre){
  return(arbre->filsD);
}

unsigned int obtenirPonderation(ArbreDeHuffman arbre){
  return(arbre->ponderation);
}

char obtenirCaractere(ArbreDeHuffman feuille){
  assert(estUneFeuille(feuille));
  return(arbre->caractere);
}

ArbreDeHuffman ajouterRacine(ArbreDeHuffman arbre1, ArbreDeHuffman arbre2){
  ArbreDeHuffman *arbre=(ArbreDeHuffman)malloc(siezof(ADH_Noeud));
  if (arbre!=NULL){
    errno=0;
    arbre->ponderation = (arbre1->pondaration)+(arbre2->ponderation);
    arbre->caractere = NULL;
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
  }
}

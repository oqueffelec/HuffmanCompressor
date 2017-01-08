/**
  * \file FichierBinaire.c
  * \brief Conception du TAD FichierBinaire
  * \author Octave Queffelec
  * \version 1.0
  * \date 15/12/2016
  */

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include "FichierBinaire.h"
#include "Mode.h"
#include "Octet.h"

#define TRUE 1
#define FALSE 0

FB_FichierBinaire FB_ouvrir(char nom[], Mode mode) {
  FB_FichierBinaire fb;
  fb.file = NULL;
  errno = 0;
  switch (mode) {
  case ecriture :
    fb.file = fopen(nom, "wb");
    break;
  case lecture :
    fb.file = fopen(nom, "rb");
    break;
  default :
    errno = FB_ERREUR_OUVERTURE;
    break;
  }
  if (fb.file == NULL)
    errno = FB_ERREUR_OUVERTURE;
  return fb;
}

void FB_fermer(FB_FichierBinaire fb) {
  fclose(fb.file);
}

int FB_finFichier(FB_FichierBinaire fb) {
  return feof(fb.file);
}


void FB_ecrireOctet(FB_FichierBinaire* fb, O_Octet o) {
  fwrite(&(o.octet), sizeof(unsigned char), 1, (fb->file));
}

int FB_lireOctet(FB_FichierBinaire fb, O_Octet* o) {
  int res=0;
    res =fread(&(o->octet), sizeof(unsigned char), 1, fb.file);
return res;
}

void FB_ecrireNaturel(FB_FichierBinaire* fb, int n) {
  fwrite(&n, sizeof(int), 1, fb->file);
}

int FB_lireNaturel(FB_FichierBinaire fb, int* naturel) {
  return fread(naturel, sizeof(int), 1, fb.file);
}

void FB_ecrireCaractere(FB_FichierBinaire* fb, char c) {
  fwrite(&c, sizeof(char), 1, fb->file);
}

int FB_lireCaractere(FB_FichierBinaire fb, char* caractere) {
  return fread(caractere, sizeof(char), 1, fb.file);
}


int FB_longueurFichier(FB_FichierBinaire fb) {
  struct stat fileStat;
  fstat(fileno(fb.file), &fileStat);
  return fileStat.st_size;
}


void FB_ecrireChaine(FB_FichierBinaire* fb, char* chaine) {
  for (int i=0; i < strlen(chaine); i++){
    FB_ecrireCaractere(fb, chaine[i]);
  }
}

char* FB_lireChaine(FB_FichierBinaire fb, int n) {
  char* res=(char*)malloc((n+1)*sizeof(char));
  int i = 0;
  while(i <= (n-1) && !FB_finFichier(fb) && FB_lireCaractere(fb, &res[i])){
    i++;
  }
  res[i+1] =  \0 ;
  return res;
}

void FB_deplacerCurseur(FB_FichierBinaire* f, long position) {
  fseek(f->file, position, SEEK_SET);
}

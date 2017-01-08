/**
  * \file main.c
  * \brief Ecriture du main
  * \author Octave Queffelec
  * \version 1.0
  * \date 5/1/2017
  */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "compression.h"
#include "decompression.h"
#include "FichierBinaire.h"
#include "Statistiques.h"
#include "creerStatistiques.h"
#include "TableDeCodage.h"
#include "creerTableDeCodage.h"
#include "enTete.h"
#include "codage.h"
#include <fcntl.h>
#include <unistd.h>




int main(int argc, char *argv[]){
	FB_FichierBinaire fichierCompresse;
	FB_FichierBinaire fichierOriginal;
  char nomFichier[100];
	if(argc!=3 || (strcmp(argv[1],"c")!=0 && strcmp(argv[1],"d")!=0)){
		printf("Veuillez respecter la syntaxe suivante : \n Pour compresser : huffman c nomFichier \n Pour decompresser : huffman d nomFichier.huff \n");
	}
	else{
		if(strcmp(argv[1], "c") == 0){
			printf("Compression...");
			strcpy(nomFichier, argv[2]);
			strcat(nomFichier, ".huff");
      fichierOriginal = FB_ouvrir(argv[2],lecture);
			fichierCompresse = FB_ouvrir(nomFichier, ecriture);
			compression(fichierOriginal,&fichierCompresse);
      printf("termine avec succes\n");

		}
		else{
			printf("Decompression...");
			strcpy(nomFichier, argv[2]);
			nomFichier[strlen(nomFichier) - strlen(".huff")] =  \0 ;
      fichierCompresse = FB_ouvrir(argv[2], lecture);
			fichierOriginal = FB_ouvrir(nomFichier, ecriture);
			decompression(fichierCompresse,&fichierOriginal);
      printf("termine avec succes\n");
		  }
		}
  return EXIT_SUCCESS;
}

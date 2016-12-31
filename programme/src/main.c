#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "TableDeCodage.h"
#include <errno.h>
#include "Bit.h"
#include "Statistiques.h"
#include "CodeBinaire.h"
#include "fichierBinaire.h"
#include "octet.h"
#include "enTete.h"
#include "puissance.h"
#include "creerStatistiques.h"
#include "creerTableDeCodage.h"
#include "codage.h"
#include "recupererDonnees.h"
#include "compression.h"
#include "decompression.h"






#include <fcntl.h>
#include <unistd.h>

#define MSG_ERREUR "*** ERREUR\nUtilisation : './bin/huffman c cheminFichier' pour compresser et './bin/huffman d cheminFichier pour décompresser\n"
#define EXT_HUFF ".huff"



int main(int argc, char *argv[]){
	FB_FichierBinaire fichierHuff;
	FB_FichierBinaire fichierBin;
  char nomFichier[100];
	if(argc!=3){
		printf(MSG_ERREUR);
	}
	else{
		if(strcmp(argv[1], "c") == 0){
			printf("Compression ...\n");

			strcpy(nomFichier, argv[2]);
			strcat(nomFichier, EXT_HUFF);

			fichierHuff = FB_ouvrir(nomFichier, ecriture);
			fichierBin = FB_ouvrir(argv[2],lecture);

			compression(fichierBin,&fichierHuff);
			printf("*** Terminée\n");
		}
		else{
			if(strcmp(argv[1], "d") == 0){
				printf("Décompression ...\n");

				strcpy(nomFichier, argv[2]);
				nomFichier[strlen(nomFichier) - strlen(EXT_HUFF)] = '\0';

				fichierBin = FB_ouvrir(nomFichier, ecriture);
				fichierHuff = FB_ouvrir(argv[2], lecture);

				decompression(fichierHuff,&fichierBin);

		   }
		  }
	   }
  return EXIT_SUCCESS;
}

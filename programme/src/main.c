#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "tableDeCodage.h"
#include <errno.h>
#include "bit.h"
#include "statistiques.h"
#include "codeBinaire.h"
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

/*
CB_CodeBinaire cb = CB_codeBinaire();
CB_CodeBinaire c = CB_codeBinaire();
CB_ajouter(&cb,bitA1);
CB_ajouter(&cb,bitA1);
CB_CodeBinaire c3 = CB_codeBinaire();
CB_CodeBinaire c4 = CB_codeBinaire();
CB_ajouter(&c3,bitA0);
CB_ajouter(&c3,bitA1);

int k=0;
while(k<4){
CB_codeBinaireEnCodeBinaire(&c,c4);
k++;
}



for(int i=0;i<CB_longueur(c);i++)
printf("%d\n", CB_obtenirBit(c,i+1));

*/

//COMPRESSION

FB_FichierBinaire fb= FB_ouvrir("04-TAD-4PagesParPage.pdf",lecture);
FB_FichierBinaire fb2= FB_ouvrir("a.txt",ecriture);
STAT_Statistiques stat= creerStatistiques(fb);




TDC_TableDeCodage tdc= creerTableDeCodage(stat);

enTete(fb,&fb2,stat);
codage(fb,&fb2,tdc);


FB_fermer(fb);
FB_fermer(fb2);

//DECOMPRESSION

 fb= FB_ouvrir("a.txt",lecture);
 fb2= FB_ouvrir("faibleBIS.pdf",ecriture);



decompression(fb,&fb2);

FB_fermer(fb);
FB_fermer(fb2);



FB_fermer(fb);
FB_fermer(fb2);












/*
CB_CodeBinaire tab[4];

CB_CodeBinaire cb = CB_codeBinaire();
CB_CodeBinaire c2 = CB_codeBinaire();
CB_CodeBinaire c3 = CB_codeBinaire();


CB_ajouter(&cb,bitA1);
CB_ajouter(&cb,bitA1);
CB_ajouter(&cb,bitA1);

CB_ajouter(&c2,bitA0);
CB_ajouter(&c2,bitA0);
CB_ajouter(&c2,bitA0);

CB_ajouter(&c3,bitA0);
CB_ajouter(&c3,bitA1);
CB_ajouter(&c3,bitA0);



tab[0]=cb;
tab[1]=c2;
tab[2]=c3;


CB_CodeBinaire res = CB_codeBinaire();
for(int i=2; i>=0;i--){
  res = CB_concatener(res,tab[i]);
}

printf(" cb : %d\n", CB_obtenirBit(res,1));
printf(" cb : %d\n", CB_obtenirBit(res,2));
printf(" cb : %d\n", CB_obtenirBit(res,3));
printf(" cb : %d\n", CB_obtenirBit(res,4));
printf(" cb : %d\n", CB_obtenirBit(res,5));
printf(" cb : %d\n", CB_obtenirBit(res,6));
printf(" cb : %d\n", CB_obtenirBit(res,7));
printf(" cb : %d\n", CB_obtenirBit(res,8));
printf(" cb : %d\n", CB_obtenirBit(res,9));




*/












  /*
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
  */
}

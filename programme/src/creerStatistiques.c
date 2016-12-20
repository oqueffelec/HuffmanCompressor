/**
 * \file creerStatistiques.c
 * \brief Implantation de la fonction creerStatistiques : crée un tableau de 256 cases correspondants à des octets remplies avec leur nombre d'occurences.
 * \author Mathieu Vandecasteele
 * \version 1.3
 * \date 16/12/2016
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "octet.h"
#include "statistiques.h"
#include "recupererOctet.h"
#include "creerStatistiques.h"

STAT_Statistiques creerStatistiques(FILE* fichier,const char* nomfichier){

fichier= fopen(nomfichier,"r");
STAT_Statistiques stat;
O_Octet* octet;
stat = STAT_statistiques();

 if (fichier != NULL)
    {

		while (!feof(fichier)){
		octet = recupererOctet(fichier,nomfichier);	
		STAT_ajouter(&stat,octet);
		}

        fclose(fichier);
    }
 else{
	printf("erreur, impossible d'ouvrir le fichier");
     }

return stat;
}




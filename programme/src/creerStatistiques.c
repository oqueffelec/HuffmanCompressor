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
#include "fichierBinaire.h"
#include "octet.h"
#include "mode.h"
#include "statistiques.h"
#include "creerStatistiques.h"

STAT_Statistiques creerStatistiques(FB_FichierBinaire fichier){
	STAT_Statistiques stat = STAT_statistiques();
	O_Octet octet[FB_longueurFichier(fichier)];
	for(int i=0; i<FB_longueurFichier(fichier);i++)
		octet[i]=O_octetZero();
	FB_lireOctets(fichier,octet,FB_longueurFichier(fichier));
	for(int i=0; i<FB_longueurFichier(fichier);i++)
		STAT_ajouter(&stat,octet[i]);
	return stat;
}

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
	STAT_Statistiques stat;
	O_Octet octet;
	stat = STAT_statistiques();
	while (FB_lireOctet(fichier,&octet)!=0){
		if(FB_finFichier(fichier)!=0){
			FB_lireOctet(fichier,&octet);
			STAT_ajouter(&stat,octet);
		}
	 }
	FB_fermer(fichier);
	return stat;
}

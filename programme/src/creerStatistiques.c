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
#include "FichierBinaire.h"
#include "Octet.h"
#include "Mode.h"
#include "Statistiques.h"
#include "creerStatistiques.h"

STAT_Statistiques creerStatistiques(FB_FichierBinaire fichier){
	STAT_Statistiques stat = STAT_statistiques();
	O_Octet octet = O_octetZero();
	while(FB_lireOctet(fichier,&octet)==1 && FB_finFichier(fichier)==0){
			STAT_ajouter(&stat,octet);
	}
	return stat;
}

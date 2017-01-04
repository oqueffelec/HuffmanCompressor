/**
 * \file creerStatistiques.h
 * \brief Implantation de la fonction creerStatistiques : crée un tableau de 256 cases correspondants à des octets remplies avec leur nombre d'occurences.
 * \author Mathieu Vandecasteele
 * \version 1.0
 * \date 16/12/2016
 */
#ifndef __CREERSTAT__
#define __CREERSTAT__

#include "statistiques.h"
#include "fichierBinaire.h"


/**
* \fn STAT_Statistiques creerStatistiques(FB_FichierBinaire fichier,char* nomfichier)
* \brief renvoie la statistiques du fichier passé en parametre
* \return STAT_Statistiques
*/

STAT_Statistiques creerStatistiques(FB_FichierBinaire fichier);


#endif

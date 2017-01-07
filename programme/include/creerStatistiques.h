/**
 * \file creerStatistiques.h
 * \brief Implantation de la fonction creerStatistiques : crée un tableau de 256 cases correspondants à des octets remplies avec leur nombre d'occurences.
 * \author Mathieu Vandecasteele
 * \version 1.0
 * \date 16/12/2016
 */
#ifndef __CREERSTAT__
#define __CREERSTAT__

#include "Statistiques.h"
#include "FichierBinaire.h"


/**
* \fn STAT_Statistiques creerStatistiques(FB_FichierBinaire fichier)
* \brief renvoie la statistiques du fichier passé en paramètre
* \return STAT_Statistiques
*/

STAT_Statistiques creerStatistiques(FB_FichierBinaire fichier);


#endif

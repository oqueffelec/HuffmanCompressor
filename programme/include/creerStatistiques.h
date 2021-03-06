/**
 * \file creerStatistiques.h
 * \brief Implantation de la fonction creerStatistiques : cree un tableau de 256 cases correspondants a des octets remplies avec leur nombre d occurences.
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
* \brief renvoie la statistiques du fichier passe en parametre
* \return STAT_Statistiques
*/

STAT_Statistiques creerStatistiques(FB_FichierBinaire fichier);


#endif

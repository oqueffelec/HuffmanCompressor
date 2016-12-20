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


/**
* \fn STAT_Statistiques creerStatistiques(FILE* fichier,const char* nomfichier)
* \brief renvoie un STAT_Statistiques
* \return STAT_Statistiques
*/

STAT_Statistiques creerStatistiques(FILE* fichier,const char* nomfichier);


#endif

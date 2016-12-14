/**
 * \file statistiques.h
 * \brief Implantation du TAD Statistiques : Statistiques est un tableau de 256 Octets.
 * \author Mathieu Vandecasteele
 * \version 1.0
 * \date 20/11/2016
 */
#ifndef __STATISTIQUES__
#define __STATISTIQUES__

#include "octet.h"

#define STAT_ERREUR_MEMOIRE 1
#define STAT_SIZE 255

/**
* \struct STAT_Statistiques Statistiques.h
* \brief la structure est un tableau de 256 élements soit 256 octets de type Octet maximum.
*/

typedef struct STAT_Statistiques {
unsigned long int valeur[STAT_SIZE];
}  STAT_Statistiques;


/**
* \struct STAT_ListeOctets Statistiques.h
* \brief la structure est une liste chainée (1 élément + 1 pointeur vers listesuivante).
*/

/*typedef struct noeud Noeud;
struct noeud
{
    O_Octets* o;
    struct noeud *listeSuivante;
};

typedef Noeud* STAT_ListeOctets;*/

/**
* \fn STAT_Statistiques STAT_statistiques()
* \brief initialise une variable STAT_Statistiques
* \return STAT_Statistiques
*/

STAT_Statistiques STAT_statistiques();



/**
* \fn void STAT_ajouter(STAT_Statistiques* stat, O_Octet* octet, unsigned long int pond)
* \brief met à jour la pondération associée à un octet.
* \return void
*/

void STAT_ajouter(STAT_Statistiques* stat, O_Octet* o, unsigned long int pond);


/**
* \fn int STAT_estPresentPonderation(STAT_Statistiques stat, unsigned long int pond)
* \brief verifie la presence d'une pondération dans la stat
* \return int
*/

int STAT_estPresentPonderation(STAT_Statistiques stat, unsigned long int pond);



/**
* \fn unsigned long int STAT_obtenirPonderation(STAT_Statistiques stat, O_Octet* o)
* \brief renvoie la pondération correspondante
* \return unsigned long int
*/

unsigned long int STAT_obtenirPonderation(STAT_Statistiques stat, O_Octet* o);



/**
* \fn STAT_ListeOctets STAT_obtenirOctets(STAT_Statistiques stat)
* \brief obtient une liste d'Octets
* \return STAT_ListeOctets
*/

/*STAT_ListeOctets STAT_obtenirOctets(STAT_Statistiques stat);*/

#endif

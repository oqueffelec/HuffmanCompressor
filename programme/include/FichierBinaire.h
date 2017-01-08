/**
 * \file FichierBinaire.h
 * \brief Implantation du TAD fichierBinaire
 * \author Octave Queffelec
 * \version 1.0
 */
#ifndef __FICHIER__BINAIRE__
#define __FICHIER__BINAIRE__

#include "CodeBinaire.h"
#include "Octet.h"
#include "Mode.h"
#define FB_ERREUR_OUVERTURE 1

/**
* \struct FB_FichierBinaire FB_FichierBinaire.h
* \brief la structure est une redefinition du type FILE*
*/


typedef struct FB_FichierBinaire {
FILE* file;
} FB_FichierBinaire;



/**
* \fn FB_FichierBinaire FB_ouvrir(char nom[], Mode mode)
* \brief ouvre un fichier binaire suivant le mode passe en parametre
* \return FB_FichierBinaire
*/

FB_FichierBinaire FB_ouvrir(char nom[], Mode mode);

/**
* \fn void FB_fermer(FB_FichierBinaire fb)
* \brief ferme le fichier binaire
* \return void
*/

void FB_fermer(FB_FichierBinaire fb);


/**
* \fn int FB_finFichier(FB_FichierBinaire fb);
* \brief renvoie 0 si n est pas a la fin du fichier, un nombre non nul sinon
* \return int
*/

int FB_finFichier(FB_FichierBinaire fb);

/**
* \fn void FB_ecrireOctet(FB_FichierBinaire* fb, O_Octet o)
* \brief ecrit un octet dans le fichier
* \return void
*/

void FB_ecrireOctet(FB_FichierBinaire* fb, O_Octet o);

/**
* \fn int FB_lireOctet(FB_FichierBinaire fb, O_Octet* o)
* \brief lit un octet dans le fichier, renvoie 1 si lecture sans erreur, 0 sinon
* \return int
*/


int FB_lireOctet(FB_FichierBinaire fb, O_Octet* o);

/**
* \fn void FB_ecrireNaturel(FB_FichierBinaire* fb, int n)
* \brief ecrit un naturel dans le fichier
* \return void
*/

void FB_ecrireNaturel(FB_FichierBinaire* fb, int n);

/**
* \fn int FB_lireNaturel(FB_FichierBinaire fb, int* i)
* \brief lis un naturel dans le fichier, renvoie 1 si lecture sans erreur, 0 sinon
* \return int
*/

int FB_lireNaturel(FB_FichierBinaire fb, int* i);

/**
* \fn void FB_ecrireCaractere(FB_FichierBinaire* fb, char c)
* \brief ecris un char dans le fichier
* \return void
*/

void FB_ecrireCaractere(FB_FichierBinaire* fb, char c);

/**
* \fn int FB_lireCaractere(FB_FichierBinaire fb, char* c)
* \brief lis un char dans le fichier, renvoie 1 si lecture sans erreur, 0 sinon
* \return int
*/

int FB_lireCaractere(FB_FichierBinaire fb, char* c);

/**
* \fn void FB_ecrireChaine(FB_FichierBinaire* fb, char* chaine)
* \brief ecris un char* dans le fichier
* \return void
*/

void FB_ecrireChaine(FB_FichierBinaire* fb, char* chaine);

/**
* \fn char* FB_lireChaine(FB_FichierBinaire fb, int n)
* \brief ecris une chaine de caractere dans le fichier, la taille de la chaine en param, retourne la chaine lu
* \return char*
*/

char* FB_lireChaine(FB_FichierBinaire fb, int n);

/**
* \fn int FB_longueurFichier(FB_FichierBinaire fb)
* \brief retourne la longueur du fichier passe en parametre
* \return int
*/

int FB_longueurFichier(FB_FichierBinaire fb) ;

/**
* \fn void FB_deplacerCurseur(FB_FichierBinaire* f, long position)
* \brief deplace le curseur de la position passee en parametre depuis la position actuelle
* \return void
*/

void FB_deplacerCurseur(FB_FichierBinaire* f, long position);
#endif

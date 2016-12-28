/**
 * \file fichierBinaire.h
 * \brief Implantation du TAD fichierBinaire
 * \author Octave Queffelec
 * \version 1.0
 */
#ifndef __FICHIER__BINAIRE__
#define __FICHIER__BINAIRE__

#include "codeBinaire.h"
#include "octet.h"
#include "mode.h"
#define BUFFER_SIZE 8
#define FB_ERREUR_OUVERTURE 1

/**
* \struct TDC_tableDeCodage tableDeCodage.h
* \brief la structure est une liste chainee ayant 2 elements (la clé et la valeur)
*/


typedef struct FB_FichierBinaire {
FILE* file;
} FB_FichierBinaire;



/**
* \fn TDC_tableDeCodage TDC_tableDeCodage()
* \brief renvoie la position d'un coup
* \return TDC_tableDeCodage
*/

FB_FichierBinaire FB_fichierBinaire(char nom[]);

/**
* \fn void ajouter(TDC_tableDeCodage, octet, codeBinaire)
* \brief ajoute un couple cle valeur à la TDC
* \return void
*/

FB_FichierBinaire FB_ouvrir(char nom[], Mode mode);

/**
* \fn int TDC_estPresentCodeBinaire(TDC_tableDeCodage tdc, codeBinaire cb)
* \brief verifie la presence d'un codebinaire dans la TDC
* \return int
*/

void FB_fermer(FB_FichierBinaire fb);


/**
* \fn codeBinaire TDC_obtenirCodeBinaire(TDC_tableDeCodage tdc, octet o)
* \brief renvoie le codebinaire correspondant
* \return codebinaire
*/

int FB_estOuvert(FB_FichierBinaire fb);
/**
* \fn void TDC_retirerOctet(TDC_tableDeCodage tdc, octet o)
* \brief retire le couple octet codebinaire
* \return void
*/

int FB_finFichier(FB_FichierBinaire fb);

void FB_ecrireOctets(FB_FichierBinaire* fb, O_Octet* o,int tailleTab);

int FB_lireOctets(FB_FichierBinaire fb, O_Octet* o, int tailleTab);

void FB_ecrireOctet(FB_FichierBinaire* fb, O_Octet o);

int FB_lireOctet(FB_FichierBinaire fb, O_Octet* o);

void FB_ecrireNaturel(FB_FichierBinaire* fb, int n);

int FB_lireNaturel(FB_FichierBinaire fb, int* i);

void FB_ecrireCaractere(FB_FichierBinaire* fb, char c);

int FB_lireCaractere(FB_FichierBinaire fb, char* c);

void FB_ecrireChaine(FB_FichierBinaire* fb, char* chaine);

char* FB_lireChaine(FB_FichierBinaire fb, int n);

int FB_longueurFichier(FB_FichierBinaire fb) ;

void FB_deplacerCurseur(FB_FichierBinaire* f, long position);


#endif

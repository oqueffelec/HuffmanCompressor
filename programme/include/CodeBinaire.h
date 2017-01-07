/**
 * \file CodeBinaire.h
 * \brief Implantation du TAD codeBinaire : codeBinaire est une liste chainée
 * \author Jean-Gabriel Wacyk
 * \version 1.0
 */

#ifndef __CODE__BINAIRE__
#define __CODE__BINAIRE__

#include "Bit.h"
#define TDC_ERREUR_MEMOIRE 1

/**
* \struct CB_codeBinaire CodeBinaire.h
* \brief la structure est une liste chainée avec un élément de type bit
*/

typedef struct CB_Noeud* CB_CodeBinaire;
typedef struct CB_Noeud {
  Bit bit;
  CB_CodeBinaire listeSuivante;
} CB_Noeud;

/**
 *\fn CB_codeBinaire CB_codeBinaire()
 *\brief renvoie
 *\return CB_codeBinaire
 */

CB_CodeBinaire CB_codeBinaire();

/**
* \fn void CB_ajouter(CB_codeBinaire, bit)
* \brief ajoute un bit au codeBinaire
* \return void
*/

void CB_ajouter(CB_CodeBinaire* cb,Bit bit);

/**
* \fn void CB_suprimer(CB_codeBinaire)
* \brief supprime un bit au codeBinaire
* \return void
*/

void CB_supprimer(CB_CodeBinaire* cb);

/**
* \fn int CB_longueur(CB_codeBinaire)
* \brief renvoie la longueur du codebinaire
* \return int
*/

int CB_longueur(CB_CodeBinaire cb);

/**
* \fn int CB_obtenirbit(CB_codeBinaire, int)
* \brief renvoie le bit en position pos
* \return Bit
*/

Bit CB_obtenirBit(CB_CodeBinaire cb, unsigned int pos);

/**
* \fn int CB_compareCodeBinaire(CB_codeBinaire, CB_codeBinaire)
* \brief compare deux codeBinaire, renvoie 1 si égaux, 0 sinon
* \return int
*/

int CB_compareCodeBinaire(CB_CodeBinaire cb1, CB_CodeBinaire cb2);

/**
* \fn void CB_supprimerTete(CB_CodeBinaire* cb)
* \brief supprime le bit en Tête de du code binaire
* \return void
*/

void CB_supprimerTete(CB_CodeBinaire* cb);

/**
* \fn CB_CodeBinaire CB_copie(CB_CodeBinaire cb)
* \brief clone un code binaire
* \return CB_CodeBinaire
*/

CB_CodeBinaire CB_copie(CB_CodeBinaire cb);
#endif

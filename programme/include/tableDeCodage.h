/**
 * \file TableDeCodage.h
 * \brief Implantation du TAD TableDeCodage : TableDeCodage est un dictionnaire qui a pour clé un Octet et pour valeur un code binaire
 * \author Octave Queffelec
 * \version 1.0
 */
#ifndef __TABLE__DE__CODAGE__
#define __TABLE__DE__CODAGE__

#include "CodeBinaire.h"
#include "Octet.h"

#define TDC_ERREUR_MEMOIRE 1

/**
* \struct TDC_TableDeCodage TableDeCodage.h
* \brief la structure est une liste chainee ayant 2 elements (la clé et la valeur)
*/

typedef struct TDC_Noeud* TDC_TableDeCodage;
typedef struct TDC_Noeud {
	Octet octet;
  CodeBinaire codeBinaire;
	TDC_TableDeCodage listeSuivante;
}  TDC_Noeud;

/**
* \fn TDC_TableDeCodage TDC_TableDeCodage()
* \brief renvoie la position d'un coup
* \return TDC_TableDeCodage
*/

TDC_TableDeCodage TDC_TableDeCodageVide();

/**
* \fn void ajouter(TDC_TableDeCodage, Octet, CodeBinaire)
* \brief ajoute un couple cle valeur à la TDC
* \return void
*/

void TDC_ajouter(TDC_TableDeCodage* tdc, Octet o, CodeBinaire cb);

/**
* \fn TDC_estPresentOctet(TDC_TableDeCodage, Octet)
* \brief verifie la presence d'un Octet dans la TDC
* \return int
*/

int TDC_estPresentOctet(TDC_TableDeCodage tdc, Octet o);

/**
* \fn int TDC_estPresentCodeBinaire(TDC_TableDeCodage tdc, CodeBinaire cb)
* \brief verifie la presence d'un CodeBinaire dans la TDC
* \return int
*/

int TDC_estPresentCodeBinaire(TDC_TableDeCodage tdc, CodeBinaire cb);

/**
* \fn Octet TDC_obtenirOctet(TDC_TableDeCodage tdc, CodeBinaire cb)
* \brief renvoie l'Octet correspondant
* \return Octet
*/

Octet TDC_obtenirOctet(TDC_TableDeCodage tdc, CodeBinaire cb);

/**
* \fn CodeBinaire TDC_obtenirCodeBinaire(TDC_TableDeCodage tdc, Octet o)
* \brief renvoie le CodeBinaire correspondant
* \return CodeBinaire
*/

CodeBinaire TDC_obtenirCodeBinaire(TDC_TableDeCodage tdc, Octet o);

/**
* \fn void TDC_retirerOctet(TDC_TableDeCodage tdc, Octet o)
* \brief retire le couple Octet CodeBinaire
* \return void
*/

void TDC_retirerOctet(TDC_TableDeCodage* tdc, Octet o);

#endif

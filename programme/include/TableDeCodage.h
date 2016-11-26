/**
 * \file tableDeCodage.h
 * \brief Implantation du TAD tableDeCodage : tableDeCodage est un dictionnaire qui a pour clé un octet et pour valeur un code binaire
 * \author Octave Queffelec
 * \version 1.0
 */
#ifndef __TABLE__DE__CODAGE__
#define __TABLE__DE__CODAGE__

//#include "CodeBinaire.h"
//#include "Octet.h"
#define TDC_ERREUR_MEMOIRE 1

/**
* \struct TDC_tableDeCodage tableDeCodage.h
* \brief la structure est une liste chainee ayant 2 elements (la clé et la valeur)
*/

typedef struct TDC_Noeud* TDC_TableDeCodage;
typedef struct TDC_Noeud {
	int* octet;
  int* codeBinaire;
	TDC_TableDeCodage listeSuivante;
}  TDC_Noeud;

/**
* \fn TDC_tableDeCodage TDC_tableDeCodage()
* \brief renvoie la position d'un coup
* \return TDC_tableDeCodage
*/

TDC_TableDeCodage TDC_tableDeCodage();

/**
* \fn void ajouter(TDC_tableDeCodage, octet, codeBinaire)
* \brief ajoute un couple cle valeur à la TDC
* \return void
*/

void TDC_ajouter(TDC_TableDeCodage* tdc, int*o, int*cb);

/**
* \fn TDC_estPresentOctet(TDC_tableDeCodage, octet)
* \brief verifie la presence d'un octet dans la TDC
* \return int
*/

int TDC_estPresentOctet(TDC_TableDeCodage tdc, int*o);

/**
* \fn int TDC_estPresentCodeBinaire(TDC_tableDeCodage tdc, codeBinaire cb)
* \brief verifie la presence d'un codebinaire dans la TDC
* \return int
*/

int TDC_estPresentCodeBinaire(TDC_TableDeCodage tdc, int*cb);

/**
* \fn octet TDC_obtenirOctet(TDC_tableDeCodage tdc, codeBinaire cb)
* \brief renvoie l'octet correspondant
* \return octet
*/

int* TDC_obtenirOctet(TDC_TableDeCodage tdc, int*cb);

/**
* \fn codeBinaire TDC_obtenirCodeBinaire(TDC_tableDeCodage tdc, octet o)
* \brief renvoie le codebinaire correspondant
* \return codebinaire
*/

int* TDC_obtenirCodeBinaire(TDC_TableDeCodage tdc, int*o);

/**
* \fn void TDC_retirerOctet(TDC_tableDeCodage tdc, octet o)
* \brief retire le couple octet codebinaire
* \return void
*/

void TDC_retirerOctet(TDC_TableDeCodage* tdc, int*o);

#endif

/**
 * \file tableDeCodage.h
 * \brief Implantation du TAD tableDeCodage : tableDeCodage est un dictionnaire qui a pour clé un octet et pour valeur un code binaire
 * \author Octave Queffelec
 * \version 1.0
 */
#ifndef __TABLE__DE__CODAGE__
#define __TABLE__DE__CODAGE__

#include "codeBinaire.h"
#include "octet.h"


/**
* \struct TDC_tableDeCodage tableDeCodage.h
* \brief la structure est une liste chainee ayant 2 elements (la clé et la valeur)
*/

typedef struct TDC_Noeud* TDC_tableDeCodage;
typedef struct TDC_Noeud {
	octet octet;
  codeBinaire codeBinaire;
	TDC_tableDeCodage listeSuivante;
}  TDC_Noeud;

/**
* \fn TDC_tableDeCodage TDC_tableDeCodage()
* \brief renvoie la position d'un coup
* \return TDC_tableDeCodage
*/

TDC_tableDeCodage TDC_TableDeCodageVide();

/**
* \fn void ajouter(TDC_tableDeCodage, octet, codeBinaire)
* \brief ajoute un couple cle valeur à la TDC
* \return void
*/

void TDC_ajouter(TDC_tableDeCodage* tdc, octet o, codeBinaire cb);

/**
* \fn TDC_estPresentOctet(TDC_tableDeCodage, octet)
* \brief verifie la presence d'un octet dans la TDC
* \return int
*/

int TDC_estPresentOctet(TDC_tableDeCodage tdc, octet o);

/**
* \fn int TDC_estPresentCodeBinaire(TDC_tableDeCodage tdc, codeBinaire cb)
* \brief verifie la presence d'un codebinaire dans la TDC
* \return int
*/

int TDC_estPresentCodeBinaire(TDC_tableDeCodage tdc, codeBinaire cb);

/**
* \fn octet TDC_obtenirOctet(TDC_tableDeCodage tdc, codeBinaire cb)
* \brief renvoie l'octet correspondant
* \return octet
*/

octet TDC_obtenirOctet(TDC_tableDeCodage tdc, codeBinaire cb);

/**
* \fn codeBinaire TDC_obtenirCodeBinaire(TDC_tableDeCodage tdc, octet o)
* \brief renvoie le codebinaire correspondant
* \return codebinaire
*/

codeBinaire TDC_obtenirCodeBinaire(TDC_tableDeCodage tdc, octet o);

/**
* \fn void TDC_retirerOctet(TDC_tableDeCodage tdc, octet o)
* \brief retire le couple octet codebinaire
* \return void
*/

void TDC_retirerOctet(TDC_tableDeCodage* tdc, octet o);

#endif

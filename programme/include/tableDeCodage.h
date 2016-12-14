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
#define TDC_ERREUR_MEMOIRE 1
#define TDC_SIZE 256

/**
* \struct TDC_tableDeCodage tableDeCodage.h
* \brief la structure est une liste chainee ayant 2 elements (la clé et la valeur)
*/


typedef struct TDC_TableDeCodage {
CB_CodeBinaire codeBinaire[TDC_SIZE];
}  TDC_TableDeCodage;

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

void TDC_ajouter(TDC_TableDeCodage* tdc, O_Octet* o, CB_CodeBinaire cb);

/**
* \fn int TDC_estPresentCodeBinaire(TDC_tableDeCodage tdc, codeBinaire cb)
* \brief verifie la presence d'un codebinaire dans la TDC
* \return int
*/

int TDC_estPresentCodeBinaire(TDC_TableDeCodage tdc, CB_CodeBinaire cb);


/**
* \fn codeBinaire TDC_obtenirCodeBinaire(TDC_tableDeCodage tdc, octet o)
* \brief renvoie le codebinaire correspondant
* \return codebinaire
*/

CB_CodeBinaire TDC_obtenirCodeBinaire(TDC_TableDeCodage tdc, O_Octet* o);

/**
* \fn void TDC_retirerOctet(TDC_tableDeCodage tdc, octet o)
* \brief retire le couple octet codebinaire
* \return void
*/

CB_CodeBinaire TDC_obtenirCodeBinaires(TDC_TableDeCodage tdc);

#endif

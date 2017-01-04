/**
 * \file tableDeCodage.h
 * \brief Implantation du TAD tableDeCodage : tableDeCodage est un dictionnaire qui a pour clé un octet et pour valeur un code binaire
 * \author Régis Maskembe
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
* \brief la structure est un tableau dont les indices correspondent à la clé (l'octet) et la valeur du tableau aux valeurs du dictionnaire, c'est-a-dire au code binaire
*/


typedef struct TDC_TableDeCodage {
CB_CodeBinaire codeBinaire[TDC_SIZE];
}  TDC_TableDeCodage;

/**
* \fn TDC_tableDeCodage TDC_tableDeCodage()
* \brief renvoie un tableau dont tous les codes binaires sont initialisés à NULL
* \return TDC_tableDeCodage
*/

TDC_TableDeCodage TDC_tableDeCodage();

/**
* \fnv void TDC_ajouter(TDC_TableDeCodage* tdc, O_Octet o, CB_CodeBinaire cb)
* \brief ajoute le code binaire à l'octet correspondant
* \return void
*/

void TDC_ajouter(TDC_TableDeCodage* tdc, O_Octet o, CB_CodeBinaire cb);

/**
* \fn int TDC_estPresentCodeBinaire(TDC_tableDeCodage tdc, codeBinaire cb)
* \brief verifie la presence d'un codebinaire dans la TDC
* \return int
*/

int TDC_estPresentCodeBinaire(TDC_TableDeCodage tdc, CB_CodeBinaire cb);


/**
* \fn codeBinaire TDC_obtenirCodeBinaire(TDC_tableDeCodage tdc, octet o)
* \brief renvoie le codebinaire correspondant à l'octet
* \return codebinaire
*/

CB_CodeBinaire TDC_obtenirCodeBinaire(TDC_TableDeCodage tdc, O_Octet o);

#endif

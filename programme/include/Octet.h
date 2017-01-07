/**
 * \Octet.h
 * \brief Implantation du TAD octet : codeBinaire est un tableau de 8 bit
 * \author Jean-Gabriel Wacyk
 * \version 1.0
 */

#ifndef __OCTET__
#define __OCTET__

#include "Bit.h"
#include "CodeBinaire.h"

/**
* \struct O_Octet Octet.h
* \brief la structure est un unsigned char
*/

typedef struct O_Octet {
  unsigned char octet;
  int nb;
} O_Octet;

/**
 *\fn O_Octet O_octet(CB_CodeBinaire cb)
 *\brief renvoie un octet de 8 bits à partir d'un CodeBinaire
 *\return O_Octet
 */

O_Octet O_octet(CB_CodeBinaire cb);

/**
* \fn int O_obtenirBit(O_Octet o, int pos)
* \brief renvoie le bit en position pos, O étant le bit de poids faible, 7 de poids fort
* \return int
*/

Bit O_obtenirBit(O_Octet o, int pos);

/**
* \fn void O_ajouterPoidsFaible(O_Octet* o,Bit bit)
* \brief ajoute un bit a l'octet : le nombre de bits de l'octet doit être strictement inférieur à 8, le sens d'ajout est du bit de poids faible au poids fort
* \return void
*/

void O_ajouterPoidsFaible(O_Octet* o,Bit bit);

/**
* \fn int O_octetEnDecimal(O_Octet o)
* \brief convertit l'octet en décimal
* \return int
*/

int O_octetEnDecimal(O_Octet o);

/**
* \fn int O_comparerOctet(O_Octet o1,O_Octet o2)
* \brief compare deux octets,renvoie 1 si identique, 0 sinon
* \return int
*/

int O_comparerOctet(O_Octet o1,O_Octet o2);

/**
* \fn int O_octetZero()
* \brief renvoie un octet avec tous les bits à 0
* \return O_Octet
*/

O_Octet O_octetZero();

/**
* \fn int O_nombreBit(O_Octet o)
* \brief renvoie le nombre de bits ajoutés à l'octet
* \return int
*/

int O_nombreBit(O_Octet o);

/**
* \fn unsigned char O_getOctet(O_Octet o)
* \brief renvoie un unsigned char qui correspond à la valeur de l'octet
* \return unsigned char
*/

//unsigned char O_getOctet(O_Octet o);

/**
* \fn int O_estRempli(O_Octet o)
* \brief renvoie 1 si octet est rempli, 0 sinon
* \return int
*/

int O_estRempli(O_Octet o);

/**
* \fn O_Octet O_decimalEnOctet(int i)
* \brief convertit la valeur décimale en O_Octet
* \return O_Octet
*/

O_Octet O_decimalEnOctet(int i);

/**
* \fn void O_ajouterPoidsFort(O_Octet* o,Bit bit)
* \brief ajoute un bit a l'octet : le nombre de bits de l'octet doit être strictement inférieur à 8, le sens d'ajout est du bit de poids fort au poids faible
* \return void
*/


void O_ajouterPoidsFort(O_Octet* o,Bit bit);


#endif

/**
 * \Octet.h
 * \brief Implantation du TAD octet : codeBinaire est un tableau de 8 bit
 * \author Jean-Gabriel Wacyk
 * \version 1.0
 */

#ifndef __OCTET__
#define __OCTET__

#include "bit.h"
#include "codeBinaire.h"

/**
* \struct O_octet Octet.h
* \brief la structure est un unsigned char
*/

typedef struct O_Octet {
  unsigned char octet;
  int nb;
} O_Octet;
/**
 *\fn O_Octet O_octet(CB_CodeBinaire)
 *\brief renvoie un octet de 8 bit à partir d'un CodeBinaire
 *\return O_octet
 */

O_Octet O_octet(CB_CodeBinaire cb);

/**
 *\fn O_Octet O_octetparbit(Bit, Bit, Bit, Bit, Bit, Bit, Bit, Bit)
 *\brief renvoie un octet de 8 bit à partir de 8 bit
 *\return O_octet
 */

O_Octet O_octetParBit(Bit bit0, Bit bit1, Bit bit2, Bit bit3,Bit bit4, Bit bit5, Bit bit6, Bit bit7);

/**
* \fn int O_obtenirbit(O_octet, int)
* \brief renvoie le bit en position pos
* \return int
*/

Bit O_obtenirBit(O_Octet o, int pos);

/**
* \fn void O_ajouter(O_octet, int)
* \brief ajouter un bit a l'octet
* \return void
*/

void O_ajouter(O_Octet* o,Bit bit);

/**
* \fn int O_octetendecimal(O_octet)
* \brief convertis l'octet en décimal
* \return int
*/

int O_octetEnDecimal(O_Octet o);

/**
* \fn int O_comparerOctet(O_octet,O_octet)
* \brief compare deux octet
* \return int
*/

int O_comparerOctet(O_Octet o1,O_Octet o2);

/**
* \fn int O_octetZero()
* \brief renvoie un octet avec tous les bit à 0
* \return unsigned char
*/

O_Octet O_octetZero();

int O_nombreBit(O_Octet o);

unsigned char O_getOctet(O_Octet o);

int O_estRempli(O_Octet o);

O_Octet O_decimalEnOctet(int i);

CB_CodeBinaire O_octetEnCodeBinaire(O_Octet o);

O_Octet O_codeBinaireEnOctet(CB_CodeBinaire cb);

void O_ajouterEnTete(O_Octet* o,Bit bit);


#endif

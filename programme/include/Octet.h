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
* \brief la structure est un tableau de 8 bit
*/

typedef Bit O_Octet[8];

/**
 *\fn O_Octet O_octet()
 *\brief renvoie un octet de 8 bit
 *\return O_octet
 */

O_Octet* O_octet(CB_CodeBinaire cb);

/**
* \fn int O_obtenirbit(O_octet, int)
* \brief renvoie le bit en position pos
* \return int
*/

Bit O_obtenirbit(O_Octet* o, int pos);

/**
* \fn void O_ajouter(O_octet, int)
* \brief ajouter un bit a l'octet
* \return void
*/

void O_ajouter(O_Octet* o,Bit bit,int pos);

/**
* \fn int O_octetendecimal(O_octet)
* \brief convertis l'octet en décimal
* \return int
*/

int O_octetendecimal(O_Octet* o);

/**
* \fn int O_comparerOctet(O_octet,O_octet)
* \brief compare deux octet
* \return int
*/

int O_comparerOctet(O_Octet* o1,O_Octet* o2);


#endif





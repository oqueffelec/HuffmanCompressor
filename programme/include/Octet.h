/**
 * \Octet.h
 * \brief Implantation du TAD octet : codeBinaire est un tableau de 8 bit 
 * \author Jean-Gabriel Wacyk
 * \version 1.0
 */

#ifndef __OCTET__
#define __OCTET__

#include "bit.h"

/**
* \struct O_octet Octet.h
* \brief la structure est un tableau de 8 bit
*/

typedef Bit O_Octet[8];

/**
 *\fn O_Octet O_octet()
 *\brief renvoie 
 *\return O_octet
 */

O_Octet O_octet();

/**
* \fn int O_obtenirbit(O_octet, int)
* \brief renvoie le bit en position pos
* \return int
*/

Bit O_obtenirbit(O_Octet o, int pos);

/**
* \fn void O_ajouter(O_octet, int)
* \brief ajouter un bit a l'octet
* \return void
*/

void O_ajouter(O_Octet* o,Bit bit,int pos);

/**
* \fn int O_estcomplet(O_octet)
* \brief renvoie 0 ou 1 pour savoir si l'octet est complet
* \return int 
*/

int O_estcomplet(O_octet o);

#endif





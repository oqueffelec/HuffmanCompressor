/**
 * \file recupererOctet.h
 * \brief Implantation de la fonction recupererOctet : récupère un Octet à partir d'un fichier
 * \author Mathieu Vandecasteele
 * \version 1.0
 * \date 16/12/2016
 */
#ifndef __RECUPEREROCTET__
#define __RECUPEREROCTET__

#include "octet.h"

/**
* \fn O_Octet recupererOctet(FILE* fichier,char[] nomfichier)
* \brief renvoie un Octet à partir d'un char lu d'un FILE
* \return O_Octet
*/

O_Octet* recupererOctet(FILE* fichier,const char* nomfichier);


#endif

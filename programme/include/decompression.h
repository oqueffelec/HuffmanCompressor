/**
  * \file decompression.c
  * \brief recupere les données et appelle la procedure decodage
  * \author Octave Queffelec
  * \version 1.0
  */

#ifndef __DECOMPRESSION__
#define __DECOMPRESSION__

/**
* \fn void decompression(FB_FichierBinaire fichierSource, FB_FichierBinaire* fichierDest)
* \brief recupere les données et appelle la procedure decodage 
* \return void
*/

void decompression(FB_FichierBinaire fichierSource, FB_FichierBinaire* fichierDest);

#endif

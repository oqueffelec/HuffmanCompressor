/**
  * \file decompression.h
  * \brief récupère les données et appelle la procédure decodage
  * \author Octave Queffelec
  * \version 1.0
  */

#ifndef __DECOMPRESSION__
#define __DECOMPRESSION__

/**
* \fn void decompression(FB_FichierBinaire fichierSource, FB_FichierBinaire* fichierDest)
* \brief récupère les données et appelle la procédure decodage
* \return void
*/

void decompression(FB_FichierBinaire fichierSource, FB_FichierBinaire* fichierDest);

#endif

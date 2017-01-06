/**
 * \file compression.h
 * \brief procedure de compression du fichier source
 * \author Octave Queffelec
 * \version 1.0
 */
#ifndef __COMPRESSION__
#define __COMPRESSION__
#include "FichierBinaire.h"


/**
 *\fn void compression(FB_FichierBinaire fichierSource, FB_FichierBinaire* fichierDest)
 *\brief appelle enTete et codage
 *\return void
 */

void compression(FB_FichierBinaire fichierSource, FB_FichierBinaire* fichierDest);

#endif

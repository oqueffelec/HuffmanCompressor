/**
  * \file enTete.h
  * \brief creer l'en-tête du fichier compressé
  * \author Octave Queffelec
  * \version 1.0
  */
#ifndef __EN__TETE__
#define __EN__TETE__

/**
* \fn enTete(FB_FichierBinaire fichierSource,FB_FichierBinaire* fichierDest, STAT_Statistiques stat)
* \brief écrit l'identifiant, la longueur du fichier à coder, et les statistiques dans le fichier compressé
* \return void
*/

void enTete(FB_FichierBinaire fichierSource,FB_FichierBinaire* fichierDest, STAT_Statistiques stat);
#endif

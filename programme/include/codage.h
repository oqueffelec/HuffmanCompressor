/**
 * \file codage.h
 * \brief Implantation de codage : procédure qui code le fichier en remplacant chaque octet par son code binaire
 * \author Octave Queffelec
 * \version 1.0
 */

#ifndef __CODER__
#define __CODER__

/**
* \fn void codage(FB_FichierBinaire source, FB_FichierBinaire* dest, TDC_TableDeCodage tdc)
* \brief parcourt le fichier octet par octet et écrit leur code binaire respectif dans le fichier compressé
* \return void
*/
void codage(FB_FichierBinaire source, FB_FichierBinaire* dest, TDC_TableDeCodage tdc);
/**
* \fn void bourrage(FB_FichierBinaire* dest, O_Octet octetAecrire)
* \brief rempli de 0 le dernier octet
* \return void
*/
void bourrageZeros(FB_FichierBinaire* dest, O_Octet octetAecrire);


#endif

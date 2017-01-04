/**
 * \file fileDePriorite.h
 * \brief Implantation du TAD fileDePriorite
 * \author Octave Queffelec
 * \version 1.0
 */
#ifndef __FILE__DE__PRIORITE__
#define __FILE__DE__PRIORITE__

#include "arbreDeHuffman.h"

#define FDP_ERREUR_MEMOIRE 1

/**
* \struct FDP_FileDePriorite fileDePriorite.h
* \brief la structure est une liste chainee d'arbres de huffman
*/

typedef struct FDP_Noeud* FDP_FileDePriorite;
typedef struct FDP_Noeud {
	ArbreDeHuffman arbre;
	FDP_FileDePriorite fileSuivante;
}  FDP_Noeud;

/**
* \fn FDP_FileDePriorite FDP_fileDePriorite()
* \brief retourne une file de priorité vide
* \return FDP_FileDePriorite
*/


FDP_FileDePriorite FDP_fileDePriorite();

/**
* \fn int FDP_estVide(FDP_FileDePriorite fdp)
* \brief retourne si la file est vide ou non
* \return int
*/

int FDP_estVide(FDP_FileDePriorite fdp);

/**
* \fn void FDP_enfilerADH(FDP_FileDePriorite* fdp, ArbreDeHuffman a)
* \brief enfile un arbre dans la file en respectant l'ordre croissant des ponderations des arbres
* \return void
*/

void FDP_enfilerADH(FDP_FileDePriorite* fdp, ArbreDeHuffman a);

/**
* \fn ArbreDeHuffman FDP_obtenirADH(FDP_FileDePriorite fdp)
* \brief retourne l'arbre à la sortie de la file
* \return ArbreDeHuffman
*/

ArbreDeHuffman FDP_obtenirADH(FDP_FileDePriorite fdp);

/**
* \fn FDP_FileDePriorite FDP_obtenirFileSuivante(FDP_FileDePriorite fdp)
* \brief retourne l'arbre à la sortie de la file
* \return FDP_FileDePriorite
*/

FDP_FileDePriorite FDP_obtenirFileSuivante(FDP_FileDePriorite fdp);

/**
* \fn void FDP_fixerFileSuivante(FDP_FileDePriorite* fdp1, FDP_FileDePriorite fdp2)
* \brief retourne fixe la file fdp2 à la file fdp1
* \return void
*/

void FDP_fixerFileSuivante(FDP_FileDePriorite* fdp1, FDP_FileDePriorite fdp2);

/**
* \fn int FDP_longueur(FDP_FileDePriorite fdp)
* \brief retourne le nombre d'arbres dans la file
* \return int
*/

int FDP_longueur(FDP_FileDePriorite fdp);

/**
* \fn void FDP_defilerADH(FDP_FileDePriorite* fdp);
* \brief defile un arbre de la file
* \return void
*/

void FDP_defilerADH(FDP_FileDePriorite* fdp);
#endif

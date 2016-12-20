#ifndef __FILE__DE__PRIORITE__
#define __FILE__DE__PRIORITE__

#include "arbreDeHuffman.h"

#define FDP_ERREUR_MEMOIRE 1

/**
* \struct TDC_tableDeCodage tableDeCodage.h
* \brief la structure est une liste chainee ayant 2 elements (la clé et la valeur)
*/

typedef struct FDP_Noeud* FDP_FileDePriorite;
typedef struct FDP_Noeud {
	ArbreDeHuffman arbre;
	FDP_FileDePriorite fileSuivante;
}  FDP_Noeud;


FDP_FileDePriorite FDP_fileDePriorite();

int FDP_estVide(FDP_FileDePriorite fdp);

void FDP_enfilerADH(FDP_FileDePriorite* fdp, ArbreDeHuffman a);

ArbreDeHuffman FDP_obtenirADH(FDP_FileDePriorite fdp);

FDP_FileDePriorite FDP_obtenirFileSuivante(FDP_FileDePriorite fdp);

void FDP_fixerFileSuivante(FDP_FileDePriorite* fdp1, FDP_FileDePriorite fdp2);

int FDP_longueur(FDP_FileDePriorite fdp);

void FDP_defilerADH(FDP_FileDePriorite* fdp);

#endif

#ifndef __FILE__DE__PRIORITE__
#define __FILE__DE__PRIORITE__

#define FDP_ERREUR_MEMOIRE 1

/**
* \struct TDC_tableDeCodage tableDeCodage.h
* \brief la structure est une liste chainee ayant 2 elements (la clé et la valeur)
*/

typedef struct FDP_Noeud* FDP_FileDEPriorite;
typedef struct FDP_Noeud {
	int* octet;
 
	FDP_FileDEPriorite listeSuivante;
}  FDP_Noeud;


FDP_FileDEPriorite FDP_fileDepriorite();


int FDP_estVide(fileDePriorite* fdp);

int FDP_defiler(fileDePriorite* fdp, int*listeSuivante)

int FDP_obtenirElement(fileDePriorite* fdp, int*o)
int FDP_insérer(fileDePriorite* fdp, int*, int*o, int*cb)
#endif

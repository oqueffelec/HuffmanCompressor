#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "FileDePriorite.h"


int FDP_estVide(fileDePriorite *fdp){
    
    if(fdp->nbElements = 0) 
    return 1;
    
    else return 0;
       
}

void FDP_intialiser(fileDePriorite* fdp) {
    
    fdp->nbElements = 0;
    fdp->taille = 4;
    fdp->Elements = (int *) malloc(sizeof (ArbreDeHuffman) * 4);
    if (!fdp->Elements) {
        printf("Erreur allocation memoire...\n");
    }

}

void ranger(ArbreDeHuffman *Elements, int tete, int nbElements) {
    int gauche, droite, max;
    ArbreDeHuffman temp;
    gauche = 2 * (tete) + 1;
    droite = gauche + 1;
    max = tete;


    if (gauche <= nbElements && Elements[gauche]->ponderation > Elements[max]->ponderation) {
        max = gauche;
    }
    if (droite <= nbElements && Elements[droite]->ponderation > Elements[max]->ponderation) {
        max = droite;
    }

    if (max != tete) {
        temp = Elements[tete];
        Elements[tete] = Elements[max];
        Elements[max] = temp;
        ranger(Elements, max, nbElements);
    }

}

void FDP_insererElement(fileDePriorite *fdp, ArbreDeHuffman element) {
    int index, parent;

    // Allouer une nouvelle taille a la file
    if (fdp->nbElements == fdp->taille) {
        fdp->taille += 1;
        fdp->Elements = realloc(fdp->Elements, sizeof (ArbreDeHuffman) * fdp->taille);
        if (!fdp->Elements) {
           printf("Erreur allocation memoire...\n");
        }
    }

    index = fdp->nbElements++; // inserer a la fin de la file

    // chercher le bon emplacement dans la file
    for (; index; index = parent) {
        parent = (index - 1) / 2;
        if (fdp->Elements[parent]->ponderation >= element->ponderation) break;
        fdp->Elements[index] = fdp->Elements[parent];
    }
    fdp->Elements[index] = element;
}

ArbreDeHuffman FDP_defiler(fileDePriorite *fdp) {
    ArbreDeHuffman element;
    ArbreDeHuffman temp;

    if(FDP_estVide(*fdp)) 
    return NULL; //retourne NULL si la file est vide
    
    if ((fdp->nbElements <= (fdp->taille + 2)) && (fdp->taille > 4)) {
        fdp->taille -= 1;
        fdp->Elements = realloc(fdp->Elements, sizeof (ArbreDeHuffman) * fdp->taille);
        if (!fdp->Elements) {
           printf("Erreur allocation memoire...\n");
        }
    }
    temp = fdp->Elements[--fdp->nbElements];
    element = fdp->Elements[0];
    fdp->Elements[0] = temp;
    ranger(fdp->Elements, 0, fdp->nbElements);
    return element;
}

ArbreDeHuffman FDP_ObtenirElement(fileDePriorite *fdp){
    return fdp->Elements[0];
}

void FDP_toutDefiler(fileDePriorite *fdp) {
    
    while (fdp->nbElements != 0) {
        free(FDP_defiler(fdp));
    }
}


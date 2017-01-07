/**
 * \file ArbreDeHuffman.h
 * \brief Implantation du TAD arbreDeHuffman : type liste doublement chainée
 * \author Quentin Robcis
 * \version 1.0
 */

 #ifndef __ARBRE_DE_HUFFMAN__
 #define __ARBRE_DE_HUFFMAN__

#define ADH_ERREUR_MEMOIRE 1
#include "Octet.h"
/**
* \struct ArbreDeHuffman ArbreDeHuffman.h
* \brief la structure est une liste chainée ayant 2 éléments (la clé et la valeur)
*/

typedef struct ADH_Noeud{
  unsigned int ponderation;
  O_Octet caractere;
  struct ADH_Noeud *filsG;
  struct ADH_Noeud *filsD;
}ADH_Noeud;
typedef ADH_Noeud *ArbreDeHuffman;

/**
* \fn ArbreDeHuffman ADH_arbreDeHuffman(unsigned int ponderation, char caractere)
* \brief crée un arbre de huffman à partir d'une pondération et d'un caractere
* \return ArbreDeHuffman
*/

ArbreDeHuffman ADH_arbreDeHuffman(unsigned int ponderation, O_Octet caractere);

/**
* \fn int ADH_estUneFeuille(ArbreDeHuffman arbre)
* \brief envoie vrai si filsG et filsD pointent vers NULL et si arbre.caractere != NULL
* \return {1 0}
*/

int ADH_estUneFeuille(ArbreDeHuffman arbre);

/**
* \fn ArbreDeHuffman ADH_obtenirFilsGauche(ArbreDeHuffman arbre)
* \brief fonction qui permet d'obtenir le fils Gauche d'une racine donnée
* \return ArbreDeHuffman
*/

ArbreDeHuffman ADH_obtenirFilsGauche(ArbreDeHuffman arbre);

/**
* \fn ArbreDeHuffman ADH_obtenirFilsDroit(ArbreDeHuffman arbre)
* \brief fonction qui permet d'obtenir le fils Droit d'une racine donnée
* \return ArbreDeHuffman
*/

ArbreDeHuffman ADH_obtenirFilsDroit(ArbreDeHuffman arbre);

/**
* \fn unsigned int ADH_obtenirPonderation(ArbreDeHuffman arbre)
* \brief permet d'obtenir la pondération associée au noeud
* \return unsigned int
*/

unsigned int ADH_obtenirPonderation(ArbreDeHuffman feuille);

/**
* \fn char ADH_obtenirCaractere(ArbreDeHuffman feuille)
* \brief permet d'obtenir le caractere associé au noeud
* \return char
*/

O_Octet ADH_obtenirCaractere(ArbreDeHuffman arbre);

/**
* \fn ArbreDeHuffman ADH_ajouterRacine(ArbreDeHuffman arbre1, ArbreDeHuffman arbre2)
* \brief crée une racine a partir de deux arbres donnés dont la pondération est la somme des pondérations des deux arbres et le caractere vaut NULL
* \return ArbreDeHuffman
*/

ArbreDeHuffman ADH_ajouterRacine(ArbreDeHuffman arbre1, ArbreDeHuffman arbre2);


#endif

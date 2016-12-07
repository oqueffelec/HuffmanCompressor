/**
 * \file arbreDeHuffman.h
 * \brief Implantation du TAD arbreDeHuffman : type liste doublement chainée
 * \author Quentin Robcis
 * \version 1.0
 */

 #ifndef __ARBRE_DE_HUFFMAN__
 #define __ARBRE_DE_HUFFMAN__

#define ADH_ERREUR_MEMOIRE 1
#include "Octet.h"
/**
* \struct TDC_tableDeCodage tableDeCodage.h
* \brief la structure est une liste chainee ayant 2 elements (la clé et la valeur)
*/
typedef ADH_Noeud *ArbreDeHuffman;
typedef struct ADH_Noeud{
  unsigned int ponderation;
  O_octet caractere;
  struct ADH_Noeud filsG;
  struct ADH_Noeud filsD;
}ADH_Noeud;

/**
* \fn ArbreDeHuffman arbreDeHuffman(unsigned int ponderation, char caractere)
* \brief crée un arbre de huffman à partir d'une pondération et d'un caractere
* \return ArbreDeHuffman
*/

ArbreDeHuffman creerArbreDeHuffman(unsigned int ponderation, O_octet caractere);

/**
* \fn int estUneFeuille(ArbreDeHuffman arbre)
* \brief envoie vrai si filsG et filsD pointent vers NULL et si arbre.caractere != NULL
* \return {1 0}
*/

int estUneFeuille(ArbreDeHuffman arbre);

/**
* \fn ArbreDeHuffman obtenirFilsGauche(ArbreDeHuffman arbre)
* \brief fonction qui permet d'obtenir le fils Gauche d'une racine donnée
* \return ArbreDeHuffman
*/

ArbreDeHuffman obtenirFilsGauche(ArbreDeHuffman arbre);

/**
* \fn ArbreDeHuffman obtenirFilsDroit(ArbreDeHuffman arbre)
* \brief fonction qui permet d'obtenir le fils Droit d'une racine donnée
* \return ArbreDeHuffman
*/

ArbreDeHuffman obtenirFilsDroit(ArbreDeHuffman arbre);

/**
* \fn unsigned int obtenirPonderation(ArbreDeHuffman arbre)
* \brief permet d'obtenir la pondération associée au noeud
* \return unsigned int
*/

unsigned int obtenirPonderation(ArbreDeHuffman feuille);

/**
* \fn char obtenirCaractere(ArbreDeHuffman feuille)
* \brief permet d'obtenir le caractere associé au noeud
* \return char
*/

O_octet *obtenirCaractere(ArbreDeHuffman feuille);

/**
* \fn ArbreDeHuffman ajouterRacine(ArbreDeHuffman arbre1, ArbreDeHuffman arbre2)
* \brief crée une racine a partir de deux arbres donnés dont la pondération est la somme des pondérations des deux arbres et le caractere vaut NULL
* \return ArbreDeHuffman
*/

ArbreDeHuffman ajouterRacine(ArbreDeHuffman arbre1, ArbreDeHuffman arbre2);

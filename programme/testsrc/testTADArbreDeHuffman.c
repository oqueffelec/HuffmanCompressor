/*
 * \file testTADArbreDeHuffman.c
 * \brief Tests des fonctions utilisees dans arbreDeHuffman.c
 * \author Octave Queffelec
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "CodeBinaire.h"
#include "Octet.h"
#include "ArbreDeHuffman.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}


void test_ADH_estUneFeuille(){
  O_Octet o=O_octetZero();
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  ArbreDeHuffman a= ADH_arbreDeHuffman(5,o);
  CU_ASSERT_TRUE(ADH_estUneFeuille(a));
}

void test_ADH_obtenirCaractere(){
  O_Octet o=O_octetZero();
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  ArbreDeHuffman a= ADH_arbreDeHuffman(5,o);
  CU_ASSERT_TRUE(O_comparerOctet(ADH_obtenirCaractere(a),o));
}

void test_ADH_obtenirPonderation(){
  O_Octet o=O_octetZero();
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  ArbreDeHuffman a= ADH_arbreDeHuffman(5,o);
  CU_ASSERT_TRUE(ADH_obtenirPonderation(a)==5);
}

void test_ADH_obtenirFilsGauche(){
  O_Octet o1=O_octetZero();
  O_ajouterPoidsFaible(&o1,bitA1);
  O_ajouterPoidsFaible(&o1,bitA1);
  O_Octet o2=O_octetZero();
  O_ajouterPoidsFaible(&o1,bitA0);
  O_ajouterPoidsFaible(&o1,bitA1);
  ArbreDeHuffman a= ADH_arbreDeHuffman(5,o1);
  ArbreDeHuffman a2= ADH_arbreDeHuffman(7,o2);
  ArbreDeHuffman a3=ADH_ajouterRacine(a,a2);
  CU_ASSERT_TRUE(ADH_obtenirPonderation(ADH_obtenirFilsGauche(a3))==7 && O_comparerOctet(ADH_obtenirCaractere(ADH_obtenirFilsGauche(a3)),o2));
}

void test_ADH_obtenirFilsDroit(){
  O_Octet o1=O_octetZero();
  O_ajouterPoidsFaible(&o1,bitA1);
  O_ajouterPoidsFaible(&o1,bitA1);
  O_Octet o2=O_octetZero();
  O_ajouterPoidsFaible(&o1,bitA0);
  O_ajouterPoidsFaible(&o1,bitA1);
  ArbreDeHuffman a= ADH_arbreDeHuffman(5,o1);
  ArbreDeHuffman a2= ADH_arbreDeHuffman(7,o2);
  ArbreDeHuffman a3=ADH_ajouterRacine(a,a2);
  CU_ASSERT_TRUE(ADH_obtenirPonderation(ADH_obtenirFilsDroit(a3))==5 && O_comparerOctet(ADH_obtenirCaractere(ADH_obtenirFilsDroit(a3)),o1));
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d une suite de test */
  pSuite = CU_add_suite("Tests boite noire : TAD ArebreDeHuffman", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "ADH_estUneFeuille", test_ADH_estUneFeuille))
      || (NULL == CU_add_test(pSuite, "ADH_obtenirCaractere", test_ADH_obtenirCaractere))
      || (NULL == CU_add_test(pSuite, "ADH_obtenirPonderation", test_ADH_obtenirPonderation))
      || (NULL == CU_add_test(pSuite, "ADH_obtenirFilsGauche", test_ADH_obtenirFilsGauche))
      || (NULL == CU_add_test(pSuite, "ADH_obtenirFilsDroit", test_ADH_obtenirFilsDroit))
      )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}

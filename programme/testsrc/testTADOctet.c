/*
 * \file testTADOctet.c
 * \brief Tests des fonctions utilisees dans octet.c
 * \author Octave Queffelec
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "codeBinaire.h"
#include "Octet.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_OCTET_constructeur(){
  CB_CodeBinaire cb=CB_codeBinaire();
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_ajouter(&cb,bitA0);
  O_Octet* o=O_octet(cb);
  CU_ASSERT_TRUE(O_obtenirbit(o,0)==bitA0 && O_obtenirbit(o,1)==bitA1 && O_obtenirbit(o,2)==bitA0 && O_obtenirbit(o,3)==bitA0);
}

void test_OCTET_comparer(){
  CB_CodeBinaire cb=CB_codeBinaire();
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_ajouter(&cb,bitA0);
  O_Octet* o=O_octet(cb);
  CB_CodeBinaire cb2=CB_codeBinaire();
  CB_ajouter(&cb2,bitA0);
  CB_ajouter(&cb2,bitA0);
  CB_ajouter(&cb2,bitA1);
  CB_ajouter(&cb2,bitA0);
  CB_ajouter(&cb2,bitA0);
  CB_ajouter(&cb2,bitA0);
  CB_ajouter(&cb2,bitA1);
  CB_ajouter(&cb2,bitA0);
  O_Octet* o2=O_octet(cb2);
  CB_CodeBinaire cb3=CB_codeBinaire();
  CB_ajouter(&cb3,bitA0);
  CB_ajouter(&cb3,bitA1);
  CB_ajouter(&cb3,bitA1);
  CB_ajouter(&cb3,bitA0);
  CB_ajouter(&cb3,bitA0);
  CB_ajouter(&cb3,bitA1);
  CB_ajouter(&cb3,bitA1);
  CB_ajouter(&cb3,bitA0);
  O_Octet* o3=O_octet(cb3);
  CU_ASSERT_TRUE(O_comparerOctet(o,o2) && !O_comparerOctet(o,o3) && !O_comparerOctet(o3,o2));
}

void test_OCTET_octetendecimal(){
  CB_CodeBinaire cb=CB_codeBinaire();
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_ajouter(&cb,bitA0);
  O_Octet* o=O_octet(cb);
  CU_ASSERT_TRUE(O_octetendecimal(o)==34);
}



int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : TAD Octet", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "OCTET_constructeur", test_OCTET_constructeur))
      || (NULL == CU_add_test(pSuite, "OCTET_comparer", test_OCTET_comparer))
      || (NULL == CU_add_test(pSuite, "OCTET_octetendecimal", test_OCTET_octetendecimal))
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

/*
 * \file testTADTableDeCodage.c
 * \brief Tests des fonctions utilisees dans tableDeCodage.c
 * \author Octave Queffelec
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "codeBinaire.h"
#include "Octet.h"
#include "TableDeCodage.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_TDC_ajouter(){
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
TDC_TableDeCodage tdc= TDC_tableDeCodage();
TDC_ajouter(&tdc,o,cb2);
  CU_ASSERT_TRUE(TDC_estPresentCodeBinaire(tdc,cb2));
}

void test_TDC_obtenirCB(){
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
  TDC_TableDeCodage tdc= TDC_tableDeCodage();
  TDC_ajouter(&tdc,o,cb2);
  CU_ASSERT_TRUE(CB_compareCodeBinaire(TDC_obtenirCodeBinaire(tdc,o),cb2));
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
  if ((NULL == CU_add_test(pSuite, "TDC_ajouter", test_TDC_ajouter))
      || (NULL == CU_add_test(pSuite, "TDC_obtenirCB", test_TDC_obtenirCB))
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

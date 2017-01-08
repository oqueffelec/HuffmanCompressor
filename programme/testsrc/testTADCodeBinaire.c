/*
 * \file testTADCodeBinaire.c
 * \brief Tests des fonctions utilisees dans codeBinaire.c
 * \author Octave Queffelec
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "CodeBinaire.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_CODEBINAIRE_ajouter(){
  CB_CodeBinaire cb=CB_codeBinaire();
  CB_ajouter(&cb,bitA0);
  CU_ASSERT_TRUE(CB_obtenirBit(cb,1)==bitA0);
}

void test_CODEBINAIRE_longeur(){
  CB_CodeBinaire cb=CB_codeBinaire();
  CB_ajouter(&cb,bitA0);

  CU_ASSERT_TRUE(CB_longueur(cb)==1);
}

void test_CODEBINAIRE_compareCB(){
  CB_CodeBinaire cb=CB_codeBinaire();
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA0);
  CB_CodeBinaire cb2=CB_codeBinaire();
  CB_ajouter(&cb2,bitA0);
  CB_ajouter(&cb2,bitA0);
  CB_ajouter(&cb2,bitA1);
  CB_ajouter(&cb2,bitA0);
  CU_ASSERT_TRUE(!CB_compareCodeBinaire(cb,cb2));
}

void test_CODEBINAIRE_obtenirBit(){
  CB_CodeBinaire cb=CB_codeBinaire();
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_ajouter(&cb,bitA1);
  CB_ajouter(&cb,bitA1);
  CU_ASSERT_TRUE(CB_obtenirBit(cb,4)==bitA0);
}

void test_CODEBINAIRE_supprimerTete(){
  CB_CodeBinaire cb=CB_codeBinaire();
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_supprimerTete(&cb);
  CU_ASSERT_TRUE(CB_obtenirBit(cb,1)==bitA0);
}

void test_CODEBINAIRE_supprimerCB(){
  CB_CodeBinaire cb=CB_codeBinaire();
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_ajouter(&cb,bitA0);
  CB_ajouter(&cb,bitA1);
  CB_supprimer(&cb);
  CU_ASSERT_TRUE(cb==NULL);
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d une suite de test */
  pSuite = CU_add_suite("Tests boite noire : TAD CodeBinaire", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "CODEBINAIRE_ajouter", test_CODEBINAIRE_ajouter))
      || (NULL == CU_add_test(pSuite, "CODEBINAIRE_longeur", test_CODEBINAIRE_longeur))
      || (NULL == CU_add_test(pSuite, "CODEBINAIRE_compareCB", test_CODEBINAIRE_compareCB))
      || (NULL == CU_add_test(pSuite, "CODEBINAIRE_obtenirBit", test_CODEBINAIRE_obtenirBit))
      || (NULL == CU_add_test(pSuite, "CODEBINAIRE_supprimerTete", test_CODEBINAIRE_supprimerTete))
      || (NULL == CU_add_test(pSuite, "CODEBINAIRE_supprimerCB", test_CODEBINAIRE_supprimerCB))
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

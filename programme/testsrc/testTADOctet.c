/*
 * \file testTADOctet.c
 * \brief Tests des fonctions utilisees dans octet.c
 * \author Octave Queffelec
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "codeBinaire.h"
#include "octet.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_OCTET_zero(){
  O_Octet o = O_octetZero();
  CU_ASSERT_TRUE(O_nombreBit(o)==0 && O_getOctet(o)==0);
}


void test_OCTET_ajouter(){
  O_Octet o = O_octetZero();
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA1);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);

  CU_ASSERT_TRUE(O_obtenirBit(o,0)==bitA0 && O_obtenirBit(o,1)==bitA1 && O_obtenirBit(o,2)==bitA0 && O_obtenirBit(o,3)==bitA0);
}

void test_OCTET_estRempli(){
  O_Octet o = O_octetZero();
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA1);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);

  CU_ASSERT_TRUE(!O_estRempli(o));
}

void test_OCTET_octetEnDecimal(){
  O_Octet o = O_octetZero();
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA1);
  CU_ASSERT_TRUE(O_octetEnDecimal(o)==128);
}

void test_OCTET_comparerOctet(){
  O_Octet o = O_octetZero();
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA1);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA1);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);

  O_Octet o2 = O_octetZero();
  O_ajouter(&o2,bitA0);
  O_ajouter(&o2,bitA1);
  O_ajouter(&o2,bitA0);
  O_ajouter(&o2,bitA0);
  O_ajouter(&o2,bitA0);
  O_ajouter(&o2,bitA1);
  O_ajouter(&o2,bitA0);
  O_ajouter(&o2,bitA0);

  O_Octet o3 = O_octetZero();
  O_ajouter(&o3,bitA0);
  O_ajouter(&o3,bitA1);
  O_ajouter(&o3,bitA0);
  O_ajouter(&o3,bitA1);
  O_ajouter(&o3,bitA0);
  O_ajouter(&o3,bitA1);
  O_ajouter(&o3,bitA0);
  O_ajouter(&o3,bitA0);
  CU_ASSERT_TRUE(O_comparerOctet(o,o2) && !O_comparerOctet(o,o3) && !O_comparerOctet(o3,o2));
}

void test_OCTET_octetEnCodeBinaire(){
  O_Octet o = O_octetZero();
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA0);
  O_ajouter(&o,bitA1);


  CB_CodeBinaire cb =O_octetEnCodeBinaire(o);

  CU_ASSERT_TRUE(CB_longueur(cb)==4 && CB_obtenirBit(cb,4) == O_obtenirBit(o,0));
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
  if ((NULL == CU_add_test(pSuite, "OCTET_zero", test_OCTET_zero))
      || (NULL == CU_add_test(pSuite, "OCTET_ajouter", test_OCTET_ajouter))
      || (NULL == CU_add_test(pSuite, "OCTET_estRempli", test_OCTET_estRempli))
      || (NULL == CU_add_test(pSuite, "OCTET_octetEnDecimal", test_OCTET_octetEnDecimal))
      || (NULL == CU_add_test(pSuite, "OCTET_comparerOctet", test_OCTET_comparerOctet))
      || (NULL == CU_add_test(pSuite, "OCTET_octetEnCodeBinaire", test_OCTET_octetEnCodeBinaire))
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

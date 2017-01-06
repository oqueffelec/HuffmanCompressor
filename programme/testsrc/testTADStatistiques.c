/*
 * \file testTADStatistiques.c
 * \brief Tests des fonctions utilisees dans statistiques.c
 * \author Octave Queffelec
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "Octet.h"
#include "Statistiques.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_STAT_ajouter(){
  O_Octet o=O_octetZero();
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  STAT_Statistiques s= STAT_statistiques();
  STAT_ajouter(&s,o);
  STAT_ajouter(&s,o);
  STAT_ajouter(&s,o);
  STAT_ajouter(&s,o);
  CU_ASSERT_TRUE(STAT_obtenirPonderation(s,o)==4);
}

void test_STAT_estPresentOctet(){
  O_Octet o=O_octetZero();
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  O_ajouterPoidsFaible(&o,bitA1);
  STAT_Statistiques s= STAT_statistiques();
  STAT_ajouter(&s,o);
  STAT_ajouter(&s,o);
  STAT_ajouter(&s,o);
  STAT_ajouter(&s,o);
  CU_ASSERT_TRUE(STAT_estPresentOctet(s,o));
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : TAD Statistiques", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "STAT_ajouter", test_STAT_ajouter))
      || (NULL == CU_add_test(pSuite, "STAT_estPresentOctet", test_STAT_estPresentOctet))
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

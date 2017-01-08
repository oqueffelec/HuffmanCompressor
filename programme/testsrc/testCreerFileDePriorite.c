/*
 * \file testCreerFileDePriorite.c
 * \brief Test de la fonction creerFileDePriorite
 * \author Wacyk Jean-Gabriel
 */

 #include <stdlib.h>
 #include <CUnit/Basic.h>
 #include <CUnit/CUnit.h>
 #include "Statistiques.h"
 #include "FileDePriorite.h"
 #include "Octet.h"
 #include "TableDeCodage.h"
 #include "creerFileDePriorite.h"


 int init_suite_success() {
   return 0;
 }

 int clean_suite_success() {
   return 0;
 }


void test_creerFileDePriorite() {
  STAT_Statistiques stat = STAT_statistiques();
  O_Octet o1 = O_octetZero();
  O_Octet o2 = O_octetZero();
  O_Octet o3 = O_octetZero();
  o1.octet=5;
  o2.octet = 10;
  STAT_ajouter(&stat,o2);
  STAT_ajouter(&stat,o1);
  STAT_ajouter(&stat,o1);
  STAT_ajouter(&stat,o3);
  STAT_ajouter(&stat,o3);
  STAT_ajouter(&stat,o3);
  FDP_FileDePriorite fdp= FDP_fileDePriorite();
  fdp = creerFileDePriorite(stat);
  ArbreDeHuffman a1 = FDP_obtenirADH(fdp);
  FDP_defilerADH(&fdp);
  ArbreDeHuffman a2 = FDP_obtenirADH(fdp);
  CU_ASSERT_TRUE((ADH_obtenirCaractere(a1).octet==10) && (ADH_obtenirPonderation(a1)==1) && (ADH_obtenirCaractere(a2).octet==5) && (ADH_obtenirPonderation(a2)==2))
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d une suite de test */
  pSuite = CU_add_suite("Tests boite noire : creerFileDePriorite", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if (NULL == CU_add_test(pSuite, "test_creerFileDePriorite", test_creerFileDePriorite))
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

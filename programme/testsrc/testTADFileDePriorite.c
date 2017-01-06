/*
 * \file testTADFileDePriorite.c
 * \brief Tests des fonctions utilisees dans fileDePriorite.c
 * \author Octave Queffelec
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "CodeBinaire.h"
#include "Octet.h"
#include "ArbreDeHuffman.h"
#include "FileDePriorite.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_FDP_estVide(){
  O_Octet o1=O_octetZero();
  O_ajouterPoidsFaible(&o1,bitA1);
  O_ajouterPoidsFaible(&o1,bitA1);
  ArbreDeHuffman a1= ADH_arbreDeHuffman(6,o1);
  O_Octet o2=O_octetZero();
  O_ajouterPoidsFaible(&o2,bitA1);
  O_ajouterPoidsFaible(&o2,bitA0);
  ArbreDeHuffman a2= ADH_arbreDeHuffman(5,o2);
  FDP_FileDePriorite fdp= FDP_fileDePriorite();
  FDP_enfilerADH(&fdp,a1);
  FDP_enfilerADH(&fdp,a2);
  FDP_FileDePriorite fdp2= FDP_fileDePriorite();
  CU_ASSERT_TRUE(!FDP_estVide(fdp) && FDP_estVide(fdp2));
}

void test_FDP_enfiler(){
  O_Octet o1=O_octetZero();
  O_ajouterPoidsFaible(&o1,bitA1);
  O_ajouterPoidsFaible(&o1,bitA1);
  ArbreDeHuffman a1= ADH_arbreDeHuffman(6,o1);
  O_Octet o2=O_octetZero();
  O_ajouterPoidsFaible(&o2,bitA1);
  O_ajouterPoidsFaible(&o2,bitA0);
  ArbreDeHuffman a2= ADH_arbreDeHuffman(5,o2);
  O_Octet o3=O_octetZero();
  O_ajouterPoidsFaible(&o3,bitA1);
  O_ajouterPoidsFaible(&o3,bitA0);
  O_ajouterPoidsFaible(&o3,bitA0);
  ArbreDeHuffman a3= ADH_arbreDeHuffman(7,o3);
  FDP_FileDePriorite fdp= FDP_fileDePriorite();
  FDP_enfilerADH(&fdp,a1);
  FDP_enfilerADH(&fdp,a2);
  FDP_enfilerADH(&fdp,a3);
  ArbreDeHuffman b2=FDP_obtenirADH(fdp);
  FDP_defilerADH(&fdp);
  ArbreDeHuffman b1=FDP_obtenirADH(fdp);
  FDP_defilerADH(&fdp);
  ArbreDeHuffman b3=FDP_obtenirADH(fdp);
  CU_ASSERT_TRUE(ADH_obtenirPonderation(b2)==5 && ADH_obtenirPonderation(b1)==6 && ADH_obtenirPonderation(b3)==7);
}

void test_FDP_longueur(){
  O_Octet o1=O_octetZero();
  O_ajouterPoidsFaible(&o1,bitA1);
  O_ajouterPoidsFaible(&o1,bitA1);
  ArbreDeHuffman a1= ADH_arbreDeHuffman(6,o1);
  O_Octet o2=O_octetZero();
  O_ajouterPoidsFaible(&o2,bitA1);
  O_ajouterPoidsFaible(&o2,bitA0);
  ArbreDeHuffman a2= ADH_arbreDeHuffman(5,o2);
  O_Octet o3=O_octetZero();
  O_ajouterPoidsFaible(&o3,bitA1);
  O_ajouterPoidsFaible(&o3,bitA0);
  O_ajouterPoidsFaible(&o3,bitA0);
  ArbreDeHuffman a3= ADH_arbreDeHuffman(5,o3);
  FDP_FileDePriorite fdp= FDP_fileDePriorite();
  FDP_enfilerADH(&fdp,a1);
  FDP_enfilerADH(&fdp,a2);
  FDP_enfilerADH(&fdp,a3);
  CU_ASSERT_TRUE(FDP_longueur(fdp)==3);
}



int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : TAD FileDePriorite", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "FDP_estVide", test_FDP_estVide))
      || (NULL == CU_add_test(pSuite, "FDP_enfiler", test_FDP_enfiler))
      || (NULL == CU_add_test(pSuite, "FDP_longueur", test_FDP_longueur))
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

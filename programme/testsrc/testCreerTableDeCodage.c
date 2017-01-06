/*
 * \file testCreerTableDeCodage.c
 * \brief Test des fonctions creerTableDeCodage
 * \author Wacyk Jean-Gabriel
 */

 #include <stdlib.h>
 #include <CUnit/Basic.h>
 #include <CUnit/CUnit.h>
 #include "Statistiques.h"
 #include "FileDePriorite.h"
 #include "Octet.h"
 #include "TableDeCodage.h"
 #include "CodeBinaire.h"
 #include "creerFileDePriorite.h"
 #include "creerTableDeCodage.h"


 int init_suite_success() {
   return 0;
 }

 int clean_suite_success() {
   return 0;
 }

void test_creerArbreDeHuffman() {
  O_Octet o1=O_octetZero();
  o1.octet=10;
  ArbreDeHuffman a1= ADH_arbreDeHuffman(6,o1);
  O_Octet o2=O_octetZero();
  o2.octet=20;
  ArbreDeHuffman a2= ADH_arbreDeHuffman(5,o2);
  O_Octet o3=O_octetZero();
  o3.octet=25;
  ArbreDeHuffman a3= ADH_arbreDeHuffman(7,o3);
  O_Octet o4=O_octetZero();
  o4.octet=15;
  ArbreDeHuffman a4= ADH_arbreDeHuffman(8,o4);
  FDP_FileDePriorite fdp= FDP_fileDePriorite();
  FDP_enfilerADH(&fdp,a1);
  FDP_enfilerADH(&fdp,a2);
  FDP_enfilerADH(&fdp,a3);
  FDP_enfilerADH(&fdp,a4);
  ArbreDeHuffman a5 = creerArbreDeHuffman(fdp);
  O_Octet o5=ADH_obtenirCaractere(ADH_obtenirFilsDroit(ADH_obtenirFilsGauche(a5)));
  O_Octet o6=ADH_obtenirCaractere(ADH_obtenirFilsDroit(ADH_obtenirFilsDroit(a5)));
  O_Octet o7=ADH_obtenirCaractere(ADH_obtenirFilsGauche(ADH_obtenirFilsDroit(a5)));
  O_Octet o8=ADH_obtenirCaractere(ADH_obtenirFilsGauche(ADH_obtenirFilsGauche(a5)));
  CU_ASSERT_TRUE(O_comparerOctet(o5,o3) && O_comparerOctet(o6,o2) && O_comparerOctet(o7,o1) && O_comparerOctet(o8,o4));
}

void test_remplirTableDeCodage(){
  CB_CodeBinaire code = CB_codeBinaire();
  TDC_TableDeCodage tdc = TDC_tableDeCodage();
  O_Octet o1=O_octetZero();
  o1.octet=10;
  ArbreDeHuffman a1= ADH_arbreDeHuffman(6,o1);
  O_Octet o2=O_octetZero();
  o2.octet=20;
  ArbreDeHuffman a2= ADH_arbreDeHuffman(5,o2);
  O_Octet o3=O_octetZero();
  o3.octet=25;
  ArbreDeHuffman a3= ADH_arbreDeHuffman(7,o3);
  O_Octet o4=O_octetZero();
  o4.octet=15;
  ArbreDeHuffman a4= ADH_arbreDeHuffman(8,o4);
  FDP_FileDePriorite fdp= FDP_fileDePriorite();
  FDP_enfilerADH(&fdp,a1);
  FDP_enfilerADH(&fdp,a2);
  FDP_enfilerADH(&fdp,a3);
  FDP_enfilerADH(&fdp,a4);
  ArbreDeHuffman a5 = creerArbreDeHuffman(fdp);
  remplirTableDeCodage(&tdc,a5,&code);
  CB_CodeBinaire code2 = TDC_obtenirCodeBinaire(tdc,o4);
  CB_CodeBinaire code3 = TDC_obtenirCodeBinaire(tdc,o2);
  CB_CodeBinaire code4 = CB_codeBinaire();
  CB_ajouter(&code4,bitA1);
  CB_ajouter(&code4,bitA1);
  CB_CodeBinaire code5 = CB_codeBinaire();
  CB_ajouter(&code5,bitA0);
  CB_ajouter(&code5,bitA0);
  CB_CodeBinaire code6 = TDC_obtenirCodeBinaire(tdc,o3);
  CB_CodeBinaire code7 = TDC_obtenirCodeBinaire(tdc,o1);
  CB_CodeBinaire code8 = CB_codeBinaire();
  CB_ajouter(&code8,bitA1);
  CB_ajouter(&code8,bitA0);
  CB_CodeBinaire code9 = CB_codeBinaire();
  CB_ajouter(&code9,bitA0);
  CB_ajouter(&code9,bitA1);
  CU_ASSERT_TRUE(CB_compareCodeBinaire(code5,code2) && CB_compareCodeBinaire(code4,code3) && CB_compareCodeBinaire(code6,code8) && CB_compareCodeBinaire(code7,code9));

}



 int main(int argc, char** argv){
   CU_pSuite pSuite = NULL;

   /* initialisation du registre de tests */
   if (CUE_SUCCESS != CU_initialize_registry())
     return CU_get_error();

   /* ajout d'une suite de test */
   pSuite = CU_add_suite("Tests boite noire : TAD testCreerTableDeCodage", init_suite_success, clean_suite_success);
   if (NULL == pSuite) {
     CU_cleanup_registry();
     return CU_get_error();
   }

   /* Ajout des tests a la suite de tests boite noire */
   if ((NULL == CU_add_test(pSuite, "test_creerArbreDeHuffman", test_creerArbreDeHuffman))
   || (NULL == CU_add_test(pSuite, "test_remplirTableDeCodage", test_remplirTableDeCodage)))
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

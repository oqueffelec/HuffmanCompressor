/**
 * \file caractereEnCodeBinaire.c
 * \brief Implantation de la fonction caractereEnCodeBinaire : conversion char vers CB_CodeBinaire
 * \author Mathieu Vandecasteele
 * \version 1.0
 * \date 16/12/2016
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bit.h"
#include "puissance.h"
#include "codeBinaire.h"
#include "caractereEnCodeBinaire.h"

CB_CodeBinaire caractereEnCodeBinaire(char c){

CB_CodeBinaire code;
code = CB_codeBinaire();
int nombre = c; //conversion caractère vers décimal

for (int i = 8;i>-1;i--) { //conversion en CodeBinaire

if (puissance(2,i) > nombre){
      CB_ajouter(&code,bitA1);
        nombre = nombre-puissance(2,i);
}
else{
      CB_ajouter(&code,bitA0) ;
}
}

return code;
}

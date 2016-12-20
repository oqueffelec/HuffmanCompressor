/**
  * \file Octet.c
  * \brief Implantation de la fonction recupererOctet
  * \author Mathieu Vandecasteele
  * \version 1.0
  * \date 16/12/2016
  */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "recupererOctet.h"
#include "codeBinaire.h"
#include "caractereEnCodeBinaire.h"
#include "octet.h"

O_Octet* recupererOctet(FILE* fichier,const char* nomfichier){

char caracterelu;
CB_CodeBinaire codeissu;
O_Octet* octet;

      caracterelu = fgetc(fichier);
	codeissu = caractereEnCodeBinaire(caracterelu);
		
		octet = O_octet(codeissu);


return octet;
}

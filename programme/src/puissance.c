/* file  : puissance.c : puissance d'entiers
/*author : Mathieu Vandecasteele
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "puissance.h"

int puissance(int x, int p)
    {
        int res;
         
        if (p == 0){
           res = 1;
         }
        else{
               res = x * puissance(x,p-1);
 	}
         
        return res;
    }

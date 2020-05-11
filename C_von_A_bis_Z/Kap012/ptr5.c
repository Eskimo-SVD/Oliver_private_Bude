/* ptr5.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int *y=NULL;    /* Zeiger mit NULL initialisieren */

   if(y == NULL) {
      printf("Der Zeiger besitzt keine gültige Adresse\n");
      return EXIT_FAILURE;
   }
   else
      *y = 10;
   return EXIT_SUCCESS;
}


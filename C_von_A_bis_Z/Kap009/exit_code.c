/* exit_code.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int val, ret;

   printf("Bitte Eingabe machen : ");
   ret = scanf("%d", &val);

   if(ret != 1) {
      printf("Fehler bei scanf()-Eingabe\n");
      return EXIT_FAILURE;
   }

   if(val < 0) {
      printf("Fehler - Negative Zahl\n");
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}

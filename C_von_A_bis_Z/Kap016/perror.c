/* perror.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   FILE *fp;

   fp = fopen("keinedatei.dat", "r");
   if (NULL == fp) {
      perror("Kann nicht aus Datei lesen ");
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}


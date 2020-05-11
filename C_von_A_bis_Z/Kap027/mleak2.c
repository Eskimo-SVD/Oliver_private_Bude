/* mleak2.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char *p;

   while(p = malloc(64000)) {
      if(NULL == p) {
         fprintf(stderr, "Speicherplatzmangel!!\n");
         return EXIT_FAILURE;
      }
      /* Tu was mit dem reservierten Speicher */
   }
   return EXIT_SUCCESS;
}


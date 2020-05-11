/* mleak1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char *p;

   p = malloc(sizeof("Hallo Welt\n"));   
   if(NULL == p) {
      fprintf(stderr, "Abbruch: Speichermangel !!\n");
      return EXIT_FAILURE;
   }
   strcpy(p, "Hallo Welt\n");
   printf("%s",p);
   return EXIT_SUCCESS;
}


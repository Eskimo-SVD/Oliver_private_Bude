/* free1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int *p = malloc(sizeof(int));

   if(p != NULL) {
      *p=99;
      printf("Alloziierung erfolgreich ... \n");
      }
   else {
      printf("Kein Virtueller RAM mehr verfügbar ... \n");
      return EXIT_FAILURE;
   }
   if(p != NULL)
      free(p);
   return EXIT_SUCCESS;
}


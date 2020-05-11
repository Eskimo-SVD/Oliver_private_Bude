/* use_mem_check.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem_check.h"

int main(void) {
   char *p;

   p = malloc(sizeof("Hallo Welt\n"));
   if(NULL == p) {
      fprintf(stderr, "Speichermangel!!!\n");
      return EXIT_FAILURE;
   }
   strcpy(p, "Hallo Welt\n");
   printf("%s",p);
   malloc(1024);
   free(p);
   return EXIT_SUCCESS;
}


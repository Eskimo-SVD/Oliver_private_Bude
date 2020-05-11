/* struct1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct index {
   int seite;
   char titel[30];
};

int main(void) {
   struct index lib;

   lib.seite = 23;
   strcpy(lib.titel, "C-Programmieren");
   printf("%d, %s\n",lib.seite, lib.titel);
   return EXIT_SUCCESS;
}


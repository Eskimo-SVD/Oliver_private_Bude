/* gets.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char name[20];

   printf("Bitte geben Sie Ihren Namen ein : ");
   gets(name);  /* Gef�hrlich */
   printf("Hallo %s\n",name);
   return EXIT_SUCCESS;
}


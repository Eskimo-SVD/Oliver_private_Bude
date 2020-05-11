/* fgets1.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main(void) {
   char name[MAX];

   printf("Bitte geben Sie Ihren Namen ein : ");
   fgets(name, MAX, stdin);
   printf("Hallo %s",name);
   return EXIT_SUCCESS;
}


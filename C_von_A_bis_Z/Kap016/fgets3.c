/* fgets3.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PASSWORT "Schiller"
#define MAX 10

int main(void) {
   char pswd[MAX];

   printf("Passwort: ");
   fgets(pswd, MAX, stdin);
   if(strcmp(PASSWORT, pswd) == 0)
      printf("Willkommen\n");
   else
      printf("Passwort falsch\n");
   return EXIT_SUCCESS;
}


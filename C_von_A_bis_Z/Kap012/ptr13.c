/* ptr13.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

char *eingabe(char *str) {
   char input[MAX];

   printf("Bitte \"%s\" eingeben: ",str);
   fgets(input, MAX, stdin);
   return strtok(input, "\n");
}

int main(void) {
   char *ptr;

   ptr = eingabe("Vorname");
   printf("Hallo %s\n", ptr);
   ptr = eingabe("Nachname");
   printf("%s, interssanter Nachname\n", ptr);
   return EXIT_SUCCESS;
}


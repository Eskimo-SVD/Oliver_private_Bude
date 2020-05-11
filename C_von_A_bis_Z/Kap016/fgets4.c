/* fgets4.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PASSWORT "Schiller"
#define MAX 10

void chomp(char *str) {
   size_t p=strlen(str);
   /* '\n' mit '\0' überschreiben */
   str[p-1]='\0';
}

int main(void) {
   char pswd[MAX];

   printf("Passwort: ");
   fgets(pswd, MAX, stdin);
   /* ... letztes Zeichen vor \0 entfernen */
   chomp(pswd);

   if(strcmp(PASSWORT, pswd) == 0)
      printf("Willkommen\n");
   else
      printf("Passwort falsch\n");
   return EXIT_SUCCESS;
}


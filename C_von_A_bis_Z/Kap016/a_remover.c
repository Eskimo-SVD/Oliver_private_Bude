/* a_remover.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char pfad[100];

   printf("Welche Datei wollen Sie l�schen?\n");
   printf("Bitte wenn n�tig g�ltigen Pfad angeben.\n");
   printf("Eingabe :> ");
   scanf("%99s",pfad);
   if((remove(pfad)) < 0) {
      fprintf(stderr, "Fehler beim L�schen von %s", pfad);
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}


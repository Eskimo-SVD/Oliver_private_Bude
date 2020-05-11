/* ftell.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   FILE *quelle;
   char datei[20];

   printf("Welche Datei wollen Sie Öffnen : ");
   scanf("%s",datei);

   if( (quelle=fopen(datei, "r")) == NULL) {
      fprintf(stderr, "Konnte %s nicht oeffnen\n", datei);
      return EXIT_FAILURE;
   }
   /* Wir setzen den FILE-Zeiger ans Ende der Datei */
   fseek(quelle, 0L, SEEK_END);
   printf("Die Datei ist %ld Bytes gross!!\n", ftell(quelle));
   return EXIT_SUCCESS;
}


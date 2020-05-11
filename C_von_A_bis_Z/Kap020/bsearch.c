/* bsearch.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Anzahl der Strings */
#define MAX 5

/* Vergleichsfunktion für zwei Strings */
int cmp_str(const void *s1, const void *s2) {
   return (strcmp(*(char **)s1, *(char **)s2));
}

int main(void) {
   char *daten[MAX], puffer[80], *ptr, *key_ptr, **key_ptrptr;
   int count;

   /* Wörter eingeben */
   printf("Geben Sie %d Wörter ein\n", MAX);
   for (count = 0; count < MAX; count++) {
      printf("Wort %d: ", count+1);
      fgets(puffer, 80, stdin);
      /* Speicher für das Wort Numer count reservieren */
      daten[count] = (char *) malloc(strlen(puffer)+1);
      strcpy(daten[count], strtok(puffer,"\n") );
   }
   /* Die einzelnen Wörter sortieren */
   qsort(daten, MAX, sizeof(daten[0]), cmp_str);
   /* Sortierte Daten ausgeben */
   for (count = 0; count < MAX; count++)
      printf("\nWort %d: %s", count+1, daten[count]);

   /* Jetzt nach einem Wort suchen */
   printf("\n\nNach welchem Wort wollen Sie suchen: ");
   fgets(puffer, 80, stdin);
   /* Zur Suche übergeben Sie zuerst den puffer an key,
    * danach benötigen Sie einen weiteren Zeiger, der 
    * auf diesen Such-Schlüssel zeigt
    */
   key_ptr = strtok(puffer, "\n");
   key_ptrptr = &key_ptr;
   /* Der Zeiger ptr bekommt die Adresse des Suchergebnisses */
   ptr =(char *) bsearch(key_ptrptr, daten, MAX,
                         sizeof(daten[0]), cmp_str);

   if(NULL == ptr)
      printf("Kein Ergebnis stimmt mit %s überein\n", puffer);
   else
      printf("%s wurde gefunden\n", puffer);
   return EXIT_SUCCESS;
}


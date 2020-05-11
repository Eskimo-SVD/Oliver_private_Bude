/* count_char.c */
#include <stdio.h>
#include <stdlib.h>

int main (void) {
   int c,counter=0;

   printf("Bitte Eingabe machen:");
   /* Eingabe machen bis mit Return beendet wird */
   while((c=getchar()) != '\n') {
      /* Leerzeichen und Tabulatorzeichen nicht mitz�hlen */
      if( (c != ' ') && (c != '\t') )
         counter++;     /* counter erh�hen */
   }
   /* Gibt die Anzahl eingegeb. Zeichen von 0 bis counter-1 aus
    * mit counter-1 wird das Zeichen '\0' nicht mitgez�hlt */
   printf("Anzahl der Zeichen betr�gt %d Zeichen\n", counter-1);
   return EXIT_SUCCESS;
}


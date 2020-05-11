/* do_while1.c */
#include <stdio.h>
#include <stdlib.h>  /* für Bibliotheksfunktion rand() */

int main(void) {
   int ratezahl, count=0, erraten=0;
   int zufall = rand() % 10; /* Pseudo-Zufallszahl von 1-10 */

   do {  
      printf("Zahleingabe bitte (1-10): ");
      scanf("%d", &ratezahl);
      if(ratezahl==zufall) {  /* Zahl richtig geraten ... ? */
         erraten=1;           /* Ja, die Zahl ist richtig   */
         count++;
      }
      else {
         (ratezahl > zufall) ?
            printf("kleiner\n") : printf("grösser\n");
         count++;
      }
   } while( (erraten != 1) && (count != 3) );

   if(erraten == 0) {
      printf("Sie haben 3 Chancen vertan ;) \n");
      printf("Die Zahl wäre %d gewesen: \n", zufall);
   }
   else
      printf("Mit %d Versuchen erraten!\n",count);
   return 0;
}


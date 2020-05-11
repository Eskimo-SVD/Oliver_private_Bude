/* do_while2.c */
#include <stdio.h>

int main(void) {
   char response;

   printf("Denk Dir eine Nummer zwischen 1 und 100 aus.\n");
   printf("Das errate ich in 7 oder weniger Versuchen \n\n");
   do {
      int lo = 1, hi = 100;
      int guess;
      while (lo <= hi) {
         guess = (lo + hi) / 2;
         printf("Ist es %d ",guess);
         printf(" ((h)oeher/(n)iedriger/(j)a): ");
         fflush(stdout);
         scanf("%c%*c",&response);

         if (response == 'h')
            lo = guess + 1;
         else if (response == 'n')
            hi = guess - 1;
         else if (response != 'j')
            printf("Erraten ... :-)");
         else
            break;
      }
      /* Resultat ausgeben */
      if (lo > hi)
         printf("Du schummelst!\n");
      else
         printf("Deine Nummer lautet: %d\n",guess);
      printf("Noch ein Spiel (j)a/nein : ");
      fflush(stdout);
      scanf("%c%*c",&response);
   } while( response == 'j' );
   return 0;
}


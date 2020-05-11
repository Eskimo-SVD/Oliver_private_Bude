/* string5.c */
#include <stdio.h>
#include <stdlib.h>

char undbig[] = {
   "Hund und Katze sind nicht ohne "
   "Grund des Menschens bester Freund\n"
};

int main(void) {
  int i;

  for(i=0; undbig[i] != '\0'; i++) {
     if(undbig[i-1]==' '&& (undbig[i]=='u' ||undbig[i]=='U')) {
        if(undbig[i+1]=='n'&&undbig[i+2]=='d'&&undbig[i+3]==' '){
           undbig[i] = 'U';
           /* n zu Grossbuchstabe konvertieren (N) */
           undbig[i+1] -= 32;
           /* d zu Grossbuchstabe konvertieren  (D) */
           undbig[i+2] -= 32;
        }
      }
   }
   printf("%s", undbig);
   return EXIT_SUCCESS;
}


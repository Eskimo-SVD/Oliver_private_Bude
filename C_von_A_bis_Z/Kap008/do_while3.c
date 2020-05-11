/* do_while3.c */
#include <stdio.h>

int main(void) {
   int auswahl;

   do {
      printf("-1- Auswahl1\n");
      printf("-2- Auswahl2\n");
      printf("-3- Auswahl3\n");
      printf("-4- Programmende \n\n");
      printf("\n\n Ihre Auswahl: ");
      scanf("%d", &auswahl);
      switch(auswahl) {
         case 1  :  printf("\n Das war Auswahl 1 \n"); break;
         case 2  :  printf("\n Das war Auswahl 2 \n"); break;
         case 3  :  printf("\n Das war Auswahl 3 \n"); break;
         case 4  :  printf("\n Programmende \n");      break;
         default :  printf("\n Unbekannte Auswahl \n");
      }
   } while(auswahl!=4);
   return 0;
}


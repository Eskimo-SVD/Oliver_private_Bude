/* logic_and.c */
#include <stdio.h>

int main(void) {
   int zahl;
   printf("Geben Sie einen Wert zwischen 10 und 20 ein: ");
   scanf("%d", &zahl);

   if( (zahl >= 10) && (zahl <= 20) )
      printf("Danke für die Eingabe! \n");
   else
      printf("Falsche Eingabe! \n");
   return 0;
}


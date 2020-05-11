/* zeit.c */
#include <stdio.h>

int main(void) {
   int sekunden,minuten;

   printf("Bitte geben Sie die Zeit in Sekunden ein :");
   scanf("%d",&sekunden);
   minuten=sekunden/60;
   sekunden=sekunden%60;
   printf("genauer = %d min. %d sek.\n", minuten, sekunden);
   return 0;
}


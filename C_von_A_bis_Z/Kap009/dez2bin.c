/* dez2bin.c */
#include <stdio.h>
#include <stdlib.h>
#define ulong unsigned long

void dez2bin(ulong dez) {
   if(dez) {
      dez2bin(dez / 2);
      printf("%lu", dez % 2);
   }
}

int main(void) {
   ulong dezimal;

   printf("Dezimalzahl in Dualzahl konvertieren\n");
   printf("Welche Zahl : ");
   scanf("%lu",&dezimal);
   printf("Dezimal = %lu Dual = ",dezimal);
   dez2bin(dezimal);
   printf("\n");
   return EXIT_SUCCESS;
}

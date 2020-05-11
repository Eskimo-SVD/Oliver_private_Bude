/* while3.c */
#include <stdio.h>

int main(void) {
   int zahl1=0, zahl2=0;
   while((zahl1++ < 5) || (zahl2++ < 5) )
      printf("Wert von zahl1: %d zahl2: %d \n ", zahl1, zahl2);
   return 0;
}


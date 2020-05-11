/* bignum.c */
#include <stdio.h>

int bignum(int a, int b) {
   if(a > b)
      return a;
   else if(a < b)
      return b;
   else
      return 0; /* beide Zahlen sind gleich groß */
}

int main(void) {
   int wert1, wert2, big;
   printf("Bitte einen Wert eingeben: ");
   scanf("%d",&wert1);
   printf("Bitte noch einen Wert eingeben: ");
   scanf("%d",&wert2);

   big = bignum(wert1, wert2);
   if(big != 0)
      printf("%d ist die größere der beiden Zahlen\n",big);
   else
      printf("Beide Zahlen haben denselben Wert\n");
   return 0;
}


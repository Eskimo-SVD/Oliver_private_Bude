/* float_limit.c */
#include <stdio.h>
#include <float.h>
#include <limits.h> //f�r CHAR_BIT

int main(void) {
   printf("Limits und Eigenschaften des float-Wertes\n\n");
   printf("float ben�tigt %d Bytes (%d Bit) an Speicherplatz\n",
      sizeof(float), sizeof(float) * CHAR_BIT);
   printf("Basis f�r Exponentendarstellung: %d\n", FLT_RADIX);
   printf("Anzahl der Mantissenstellen    : %d\n", FLT_MANT_DIG);
   printf("Anzahl sign. Dezimalziffern    : %d\n", FLT_DIG);
   printf("Kleinst. neg. FLT_RADIX-Exponent: %d\n", FLT_MIN_EXP);
   printf("Kleinst. neg. Zehnerexponent : %d\n", FLT_MIN_10_EXP);
   printf("Gr��ter FLT_RADIX-Exponent     : %d\n", FLT_MAX_EXP);
   printf("Gr��ter Zehnerexponent       : %d\n", FLT_MAX_10_EXP);
   printf("Gr��ter endlicher float-Wert   : %f\n", FLT_MAX);
   printf("Kleinster endlicher float-Wert : %f\n", FLT_MIN);
   return 0;
}


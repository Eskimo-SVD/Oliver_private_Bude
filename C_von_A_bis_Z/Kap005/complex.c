/* complex.c */
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int main(void) {
   float f1 = 1.0;
   float complex fc = 2.0 + 3.0*I;
   // 4 Bytes
   printf("sizeof(float)         : %d\n", sizeof(float));
   // 8 Bytes (realer- und imaginärer Teil)
   printf("sizeof(float complex) : %d\n", sizeof(float complex));
   // Ausgabe vom Real- und Imaginärteil
   printf("%f + %f\n", creal(fc), cimag(fc));
   return EXIT_SUCCESS;
} 


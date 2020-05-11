/* mathematik1.c */
#include <stdio.h>
#include <stdlib.h>
/* Bei Linux den Compilerflag -lm mit angeben */
#include <math.h>
#if __STDC_VERSION__ >= 19901L
   #include <complex.h>
#endif

int main(void) {
   double i=5.5, pi;
#if __STDC_VERSION__ >= 19901L
   double complex c;
#endif
  
   // Berechnungen mit reelen Zahlen 
   printf("Quadradwurzel von %f = %f\n",i,sqrt(i));
   printf("Der Sinus von %f = %f\n",i,sin(i));
   printf("Der Tangens von %f = %f\n",i,tan(i));
   printf("Der Cosinus von %f = %f\n",i,cos(i));
#if __STDC_VERSION__ >= 19901L
   // Berechnung mit komplexen Zahlen
   pi = 4 * atan(1.0);
   c = cexp(I * pi);
   printf("%f + %f * i\n", creal(c), cimag(c));
#endif 

   return EXIT_SUCCESS;
}


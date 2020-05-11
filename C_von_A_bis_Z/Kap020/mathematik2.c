/* mathematik2.c */
#include <stdio.h>
#include <stdlib.h>
/* Bei Linux den Compilerflag -lm mit angeben */
#include <tgmath.h>

int main(void) {
   float f = 1.1;
   double d=2.2;
   long double ld = 3.3;
   float complex fc = 1.0 + 2.0*I, fcval;
   double complex dc = 4.0 + 2.0*I, dcval;
   long double complex ldc = 8.0 + 9.0*I, ldcval;
  
   // Berechnungen mit reelen Zahlen 
   printf("Quadradwurzel von %f = %f\n",f,sqrt(f));
   printf("Quadradwurzel von %f = %f\n",d,sqrt(d));
   printf("Quadradwurzel von %Lf = %Lf\n",ld,sqrt(ld));
   fcval = sqrt(fc);
   printf("Quadradwurzel von %f + %fi = Lf\n",creal(fcval),cimag(fcval));
   dcval = sqrt(dc);
   printf("Quadradwurzel von %f + %fi\n",creal(dcval),cimag(dcval));
   ldcval = sqrt(ldc);
   printf("Quadradwurzel von %Lf + %Lfi\n",creal(ldcval),cimag(ldcval));
   return EXIT_SUCCESS;
}


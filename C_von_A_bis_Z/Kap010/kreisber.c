/* kreisber.c */
#include <stdio.h>
#include <stdlib.h>
/*  Bei Linux muss f�r math.h der Compilerflag -lm 
 *  mit angegeben werden:
 *  gcc -o synkonst2 symkonst2.c -lm
 */
#include <math.h>
#define PI 3.1415926f

/*  Programm zur Berechnung von Kreisfl�che(A), Durchmesser(d)
 *  und Umfang(U) und Durchmesser aus Umfang */

void kreisflaeche(void) {
   float A,d;

   printf("Durchmesser des Kreises eingeben: ");
   scanf("%f", &d);
   A = d*d*PI / 4;
   printf("Die Kreisfl�che betr�gt  %f\n", A);
}

void durchmesser(void) {
   float A, d;

   printf("Kreisfl�che des Kreises eingeben: ");
   scanf("%f", &A);
   d =(float) sqrt((double)4*A/PI);
   printf("Der Duchmesser des Kreises ist %f\n", d);
}

void kreisumfang(void) {
   float U, d;

   printf("Durchmesser des Kreises eingeben: ");
   scanf("%f", &d);
   U = d * PI;
   printf("Der Umfang des Kreises betr�gt %f\n", U);
}

void d2umfang(void) {
   float U,d;

   printf("Umfang des Kreises eingeben: ");
   scanf("%f",&U);
   d = U/PI;
   printf("Der Durchmesser des Kreises betr�gt %f\n", d);
}

int main(void) {
   kreisflaeche();
   durchmesser();
   kreisumfang();
   d2umfang();
   return EXIT_SUCCESS;
}


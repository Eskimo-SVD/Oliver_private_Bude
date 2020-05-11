/* kreisber.c */
#include <stdio.h>
#include <stdlib.h>
/*  Bei Linux muss für math.h der Compilerflag -lm 
 *  mit angegeben werden:
 *  gcc -o synkonst2 symkonst2.c -lm
 */
#include <math.h>
#define PI 3.1415926f

/*  Programm zur Berechnung von Kreisfläche(A), Durchmesser(d)
 *  und Umfang(U) und Durchmesser aus Umfang */

void kreisflaeche(void) {
   float A,d;

   printf("Durchmesser des Kreises eingeben: ");
   scanf("%f", &d);
   A = d*d*PI / 4;
   printf("Die Kreisfläche beträgt  %f\n", A);
}

void durchmesser(void) {
   float A, d;

   printf("Kreisfläche des Kreises eingeben: ");
   scanf("%f", &A);
   d =(float) sqrt((double)4*A/PI);
   printf("Der Duchmesser des Kreises ist %f\n", d);
}

void kreisumfang(void) {
   float U, d;

   printf("Durchmesser des Kreises eingeben: ");
   scanf("%f", &d);
   U = d * PI;
   printf("Der Umfang des Kreises beträgt %f\n", U);
}

void d2umfang(void) {
   float U,d;

   printf("Umfang des Kreises eingeben: ");
   scanf("%f",&U);
   d = U/PI;
   printf("Der Durchmesser des Kreises beträgt %f\n", d);
}

int main(void) {
   kreisflaeche();
   durchmesser();
   kreisumfang();
   d2umfang();
   return EXIT_SUCCESS;
}


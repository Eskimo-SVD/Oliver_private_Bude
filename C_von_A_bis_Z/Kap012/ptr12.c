/* ptr12.c */
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592f

void kreisflaeche(float *wert) {
   *wert = ( (*wert) * (*wert) * PI );
}

int main(void) {
   float radius;

   printf("Berechnung einer Kreisfläche!!\n\n");
   printf("Bitte den Radius eingeben : ");
   scanf("%f", &radius);
   /*Adresse von radius als Argument an kreisflaeche() */
   kreisflaeche(&radius);
   printf("\nDie Kreisfläche beträgt : %f\n", radius);
   return EXIT_SUCCESS;
}


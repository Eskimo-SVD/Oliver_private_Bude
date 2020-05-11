/* ptr11.c */
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592f

float kreisflaeche(float wert) {
   return (wert = wert * wert * PI);
}

int main(void) {
   float radius, flaeche;

   printf("Berechnung einer Kreisfläche!!\n\n");
   printf("Bitte den Radius eingeben : ");
   scanf("%f", &radius);
   flaeche = kreisflaeche(radius);
   printf("\nDie Kreisfläche beträgt : %f\n", flaeche);
   return EXIT_SUCCESS;
}


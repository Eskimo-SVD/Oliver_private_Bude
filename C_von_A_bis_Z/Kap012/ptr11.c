/* ptr11.c */
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592f

float kreisflaeche(float wert) {
   return (wert = wert * wert * PI);
}

int main(void) {
   float radius, flaeche;

   printf("Berechnung einer Kreisfl�che!!\n\n");
   printf("Bitte den Radius eingeben : ");
   scanf("%f", &radius);
   flaeche = kreisflaeche(radius);
   printf("\nDie Kreisfl�che betr�gt : %f\n", flaeche);
   return EXIT_SUCCESS;
}


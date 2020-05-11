/* rectangle.c */
#include <stdio.h>

int main(void) {
   /* Deklaration */
   float flaeche, l, b;

   printf("Berechnung der Flaeche eines Rechtecks\n");
   /* Werte einlesen */
   printf("Laenge des Rechtecks: ");
   scanf("%f",&l);
   printf("Breite des Rechtecks: ");
   scanf("%f",&b);
   /* Fläche berechnen */
   flaeche = l * b;
   printf("Flaeche des Rechtecks betraegt : %f\n",flaeche);
   return 0;
}


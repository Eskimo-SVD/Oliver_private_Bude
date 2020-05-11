/* md_array1.c */
#include <stdio.h>
#include <stdlib.h>

#define VOL1 3   /* Anzahl Felder erste Dimension - Zeilen   */
#define VOL2 4   /* Anzahl Felder zweite Dimension - Spalten */

int main(void) {
   int i,j;
   int myarray[VOL1][VOL2];     /* [3][4] */

   /* Eingabe der Array-Elemente */
   for(i=0; i < VOL1; i++) {
      for(j=0; j < VOL2; j++) {
         printf("Wert für myarray[%d][%d]:", i, j);
         scanf("%d", &myarray[i][j]);
      }
   }
   printf("\nAusgabe von myarray[%d][%d]...\n\n", VOL1, VOL2);
   for(i=0; i < VOL1; i++) {
      for(j=0; j < VOL2; j++) {
         printf("\t%4d ",myarray[i][j]);
      }
      printf("\n\n");
   }
   return EXIT_SUCCESS;
}


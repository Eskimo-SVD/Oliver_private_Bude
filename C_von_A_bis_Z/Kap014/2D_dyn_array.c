/* 2D_dyn_array.c */
#include <stdio.h>
#include <stdlib.h>
#define BUF 255

int main(void) {
   int i, j, zeile, spalte;
   /* Matrix ist Zeiger auf int-Zeiger */
   int ** matrix;
   
   printf("Wie viele Zeilen : ");
   scanf("%d", &zeile);
   printf("Wie viele Spalten: ");
   scanf("%d", &spalte);
   
   /* Speicher reservieren für die int-Zeiger (=zeile) */
   matrix = malloc(zeile * sizeof(int *));
   if(NULL == matrix) {
      printf("Kein Virtueller RAM mehr vorhanden ... !");
      return EXIT_FAILURE;
   }
   /* Jetzt noch Speicher reservieren für die einzelnen Spalten 
    * der i-ten Zeile */
   for(i = 0; i < zeile; i++) {
      matrix[i] = malloc(spalte * sizeof(int));
         if(NULL == matrix[i]) {
            printf("Kein Speicher mehr fuer Zeile %d\n",i);
            return EXIT_FAILURE;  
         }
   }
   /* Mit beliebigen Werten initialisieren */
   for (i = 0; i < zeile; i++)
      for (j = 0; j < spalte; j++)
         matrix[i][j] = i + j;      /* matrix[zeile][spalte] */

   /* Inhalt der Matrix entsprechend ausgeben */
   for (i = 0; i < zeile; i++) {
      for (j = 0; j < spalte; j++)
         printf("%d ",matrix[i][j]);   
      printf("\n");
   }
   
   /* Speicherplatz wieder freigeben 
    * Wichtig! In umgekehrter Reihenfolge */

   /* Spalten der i-ten Zeile freigeben */ 
   for(i = 0; i < zeile; i++)
      free(matrix[i]);
   /* Jetzt können die leeren Zeilen freigegeben werden */
   free(matrix);
   return EXIT_SUCCESS;
}


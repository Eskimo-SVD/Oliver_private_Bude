/* md_array3.c */
#include <stdio.h>
#include <stdlib.h>
#define DIM1 5
#define DIM2 5

void function(int feld[][DIM2], int dim1) {
   int i, j;
   
   for(i = 0; i < dim1; i++) {
      for(j = 0; j < DIM2; j++) {
         printf("%d; ", feld[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

int main(void) {
   int val[DIM1][DIM2];
   int i, j;
   
   for(i = 0; i < DIM1; i++)
      for(j = 0; j < DIM2; j++)
         val[i][j] = i+j;
      
   function(val, DIM1);   
   return EXIT_SUCCESS;
}


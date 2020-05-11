/* arr_ptr3.c */
#include <stdio.h>
#include <stdlib.h>

void funktion(int *array, int n_array) {
   int i;

   for(i=0; i < n_array; i++)
      printf("%d ",array[i]);
   printf("\n");
}

int main(void) {
   int werte[] = { 1, 2, 3, 5, 8, 13, 21 };

   funktion(werte, sizeof(werte) / sizeof(int));
   return EXIT_SUCCESS;
}


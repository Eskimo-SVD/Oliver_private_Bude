/* shellsort.c */
#include <stdio.h>
#include <stdlib.h>

void shellsort (int *array, int elemente) {
  int i, j, temp, n;

   /* Anfangswert für die Distanz errechnen */
  for ( n = 1; n <= elemente/9; n = 3*n+1);
  for (; n > 0; n /= 3) {
     for (i = n; i <= elemente; i++) {
        temp = array[i];
        /* Größer als temp und nicht elemente
         * sowie >= und nicht >   */
        for(j = i;
            j >= n && array[j-n] > temp;
            j -= n) {
           array[j] = array[j-n];
        }
        array[j] = temp;
     }
  }
}

int main(void) {
   int i;
   /*Das Array zum Sortieren*/
   int test_array[] = { 5, 0, 2, 7, 9, 1, 4, 3, 8, 6 };
   int N = sizeof(test_array)/sizeof(int);

   shellsort(test_array, N-1);

   for(i = 0; i < N; i++)
      printf("%d ", test_array[i]);
   printf("\n");
   return EXIT_SUCCESS;
}


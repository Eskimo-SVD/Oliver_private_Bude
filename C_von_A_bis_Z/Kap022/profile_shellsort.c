/* profile_shellsort.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000000
#define MAX_TEST 10

/* Das Array zum Sortieren */
int test_array[MAX];

void init_test_array(void) {
   int i,j;
   for(i = MAX, j = 0; i >= 0; i--,j++)
      test_array[j] = i;
}

void shellsort(int *array, int elemente, int distanz) {
   int i, j, temp, n = elemente;

   for(; n > 0; n /= distanz)
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

int main(void) {
   int distanz_folge;
   float zeit;
   clock_t start, ende;

   for(distanz_folge =2; 
     distanz_folge <= MAX_TEST; distanz_folge++) {
      init_test_array();

      start = clock();
      shellsort(test_array, MAX-1, distanz_folge);
      ende = clock();

      /* Ergebnis der Laufzeitmessung in Sekunden */
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Die Laufzeitmessung der Distanzfolge "
         " %d ergab %2.2f  Sekunden\n" ,distanz_folge,zeit);
   }
   return EXIT_SUCCESS;
}


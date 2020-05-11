/* selektion.c */
#include <stdio.h>
#include <stdlib.h>

void selection(int *array, int elemente) {
   int index,index_klein,
       wert, wert_klein;

   /* Schleife durchläuft von links nach rechts */
   for(index = 0; index < elemente; index++) { 
      /* Aktuelle Position */
      wert=index;
      /* Schleife durchläuft bis kleineres Element als
       * aktuelle Pos. gefunden wurde oder bis zum Ende,
       * was bedeutet, die aktuelle Position ist schon
       * das kleinste   */
      for(index_klein = index+1; index_klein <= elemente;
        index_klein++) { /* Ein kleineres Element gefunden? */
         if(array[index_klein] < array[wert])
            /* Neues kleinstes Element */
            wert=index_klein;
      }
      /* Kleinstes Element an die aktuelle
       * Position falls nötig   */ 
      if(wert != index) {
         wert_klein=array[wert];
         array[wert]=array[index];
         array[index]=wert_klein;
      }
   }
}

int main(void) {
   int i;
   /*Das Array zum Sortieren*/
   int test_array[] = { 5, 2, 7, 9, 1, 4, 3, 8, 6 };
   int N = sizeof(test_array)/sizeof(int);

   selection(test_array, N-1);

   for(i = 0; i < N; i++)
      printf("%d ", test_array[i]);
   printf("\n");
   return EXIT_SUCCESS;
}


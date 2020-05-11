/* insertion.c */
#include <stdio.h>
#include <stdlib.h>

void insertion(int *array, int elemente) {
   int index,index_klein,wert_klein;

   /* Schleife von links-1 nach rechts */
   for(index=1; index<=elemente; index++) {
      /* aktuelle Position zwischenspeichern */
      wert_klein=array[index]; 
      /* Kleineren Wert als wert_klein suchen. Schleife
       * durchläuft von aktueller Pos. von rechts nach links */
      for( index_klein=index; 
           array[index_klein-1] > wert_klein&&index_klein > 0;
           index_klein-- )
         /* Wenn Vorgänger größer als aktuelles 
          * Element in wert_klein   */
         array[index_klein] = array[index_klein-1]; 
      /* gespeichertes Element an neue Position ->
       * Lücke auffüllen   */
      array[index_klein]=wert_klein; 
   }
}

int main(void) {
   int i;
   /*Das Array zum Sortieren*/
   int test_array[] = { 5, 2, 7, 9, 1, 4, 3, 8, 6 };
   int N = sizeof(test_array)/sizeof(int);

   insertion(test_array, N-1);

   for(i = 0; i < N; i++)
      printf("%d ", test_array[i]);
   printf("\n");
   return EXIT_SUCCESS;
}


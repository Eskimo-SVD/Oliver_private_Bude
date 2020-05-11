/* bubble.c */
#include <stdio.h>
#include <stdlib.h>

void bubble(int *array, int elemente) {
   int i,temp;

   while(elemente--)
      for(i = 1; i <= elemente; i++)
         if(array[i-1] > array[i]) {
            temp=array[i];
            array[i]=array[i-1];
            array[i-1]=temp;
         }
}

int main(void) {
   int i;
   /*Das Array zum Sortieren*/
   int test_array[] = { 5, 2, 7, 9, 1, 4, 3, 8, 6 };
   int N = sizeof(test_array)/sizeof(int);

   bubble(test_array, N);

   for(i = 0; i < N; i++)
      printf("%d ", test_array[i]);
   printf("\n");
   return EXIT_SUCCESS;
}


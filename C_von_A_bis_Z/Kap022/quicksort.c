/* quicksort.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50000

/* Das Array zum Sortieren */
int test_array[MAX];

void my_qsort(int*, int*);

void init_test_array(void) {
   int i, j;
   for(i = MAX,j=0; i >= 0; i--,j++)
      test_array[j] = i;
}

void print_test_array(void) {
   int i;
   for(i=0;i<MAX; i++)
      printf("%d ",test_array[i]);
}

/* Die Funktion erhält einen Zeiger auf das erste
 * und eine zweiten Zeiger auf das letzte Element.
 * Hier werden dazu die Namen links und rechts verwendet
 */
void my_qsort(int *links, int *rechts) {
   int *ptr1 = links;
   int *ptr2 = rechts;
   int w, x;
   /* x bekommt die Anfangsadresse der
    * Mitte von links und rechts
    * Anstatt der Bitverschiebung hätten Sie
    * auch einfach geteilt durch 2 rechnen können.
    */ 
   x = *(links + (rechts - links >> 1));
   do {
      while(*ptr1 < x) ptr1++;
      while(*ptr2 > x) ptr2--;
      if(ptr1 > ptr2)
         break;
      w = *ptr1;
      *ptr1 = *ptr2;
      *ptr2 = w;
   } while(++ptr1 <= --ptr2);
   if(links < ptr2)  my_qsort(links, ptr2);
   if(ptr1 < rechts) my_qsort(ptr1, rechts);
}

int main(void) {
   init_test_array();
   my_qsort(test_array, test_array+MAX);
   print_test_array();
   return EXIT_SUCCESS;
}


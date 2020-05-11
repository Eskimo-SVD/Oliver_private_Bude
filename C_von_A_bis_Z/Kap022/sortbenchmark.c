/* sortbenchmark.c */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100000

/* Ein Array von großen zu kleinen Werten */
int test_array[MAX];

void init_test_array(int elements) {
   int i, j;
   for(i = elements,j=0; i >= 0; i--,j++)
      test_array[j] = i;
}

/* Ein bereits sortiertes Array */
void init_test_array2(int elements) {
   int i;
   for(i = 0; i <= elements; i++)
      test_array[i] = i;
}

/* Ein Array mit (Pseudo)-Zufallszahlen */
void init_test_array3(int elements) {
   int i;
   for(i = 0; i <= elements; i++)
      test_array[i] = rand();
}

/* Vergleichsfunktion für qsort() */
int cmp_integer(const void *wert1, const void *wert2) {
   return (*(int*)wert1 - *(int*)wert2);
}

/* Die Funktion erhält einen Zeiger auf das erste
 * und einen zweiten Zeiger auf das letzte Element.
 * Hier werden die Namen links und rechts verwendet
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

void selection(int *array, int elemente) {
   int i, j, mini, temp;

   for(i = 0; i < elemente; i++) {
      mini=i;
      for(j=i+1; j <= elemente; j++) {
         if(array[j] < array[mini])
            mini=j;
      }
      temp=array[mini];
      array[mini]=array[i];
      array[i]=temp;
   }
}

void insertion(int *array, int elemente) {
   int i, j, temp;

   for(i = 1; i <= elemente; i++) {
      temp=array[i];  /* aktuelles Element zwischenspeichern */
      for(j=i; array[j-1] > temp && j > 0; j--)
         /* So lange der Vorgänger größer ist als das
          * aktuelle Element in temp ...  */
         array[j] = array[j-1]; 
      /* gespeichertes Element an neue Position */
      array[j]=temp; 
   }
}

void bubble(int *array, int elemente) {
   int i, temp;

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
   int elemente=1000;
   float zeit;
   clock_t start, ende;

   /* freopen("log.txt","a+",stdout); */

   for(i=1; i<=3; i++, elemente*=10){
      printf("\n\nSortieren von %d Elementen\n\n",elemente);
      printf("\n%d. Versuch : alle %d Elemente muessen "
             "sortiert werden\n\n",i,elemente);

   /* Selectionsort */
      init_test_array(elemente);  start = clock();
      selection(test_array, elemente-1);  ende = clock();  
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Selectionsort: %.2f Sekunden\n",zeit);

   /* Insertionsort */
      init_test_array(elemente);  start = clock(); 
      insertion(test_array, elemente-1); ende = clock();  
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Insertionsort: %.2f Sekunden\n",zeit);

   /* Bubblesort */
      init_test_array(elemente);  start = clock();
      bubble(test_array, elemente);  ende = clock();  
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Bubblesort   : %.2f Sekunden\n",zeit);

   /* Shellsort */
      init_test_array(elemente);  start = clock();
      shellsort(test_array, elemente-1);  ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Shellsort    : %.2f Sekunden\n",zeit);

   /* Quicksort */
      if(elemente < 50000){
         init_test_array(elemente);  start = clock();
         my_qsort(test_array, test_array+elemente);
         ende = clock(); 
         zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
         printf("Quicksort    : %.2f Sekunden\n",zeit);
      }

   /* qsort aus der Standard-Bibliothek <stdlib.h> */ 
      init_test_array(elemente);  start = clock();
      qsort(test_array, elemente, sizeof(int), cmp_integer);
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("qsort        : %.2f Sekunden\n",zeit);

   /* 2. Versuch, eine bereits sortierte Liste */
      printf("\n%d. Versuch : keins der %d Elemente muss "
             "sortiert werden\n\n",i,elemente);
   /* Selectionsort */
      init_test_array2(elemente);  start = clock();
      selection(test_array, elemente-1);  ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Selectionsort: %.2f Sekunden\n",zeit);

   /* Insertionsort */
      init_test_array2(elemente);  start = clock();
      insertion(test_array, elemente-1);  ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Insertionsort: %.2f Sekunden\n",zeit);

   /* Bubblesort */
      init_test_array2(elemente);  start = clock();
      bubble(test_array, elemente);  ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Bubblesort   : %.2f Sekunden\n",zeit);

   /* Shellsort */
      init_test_array2(elemente);  start = clock();
      shellsort(test_array, elemente-1);  ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Shellsort    : %.2f Sekunden\n",zeit);

   /* Quicksort */
      init_test_array2(elemente);  start = clock();
      my_qsort(test_array, test_array+elemente);  ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Quicksort    : %.2f Sekunden\n",zeit);

   /* qsort aus der Standard-Bibliothek <stdlib.h> */ 
      init_test_array2(elemente);  start = clock();
      qsort(test_array, elemente, sizeof(int), cmp_integer);
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("qsort        : %.2f Sekunden\n",zeit);

   /* 3.Versuch Zufallsdaten */
      printf("\n%d. Versuch : %d Zufallszahlen muessen"
             "sortiert werden\n\n",i,elemente);

   /* Selectionsort */
      init_test_array3(elemente);  start = clock();
      selection(test_array, elemente-1);  ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Selectionsort: %.2f Sekunden\n",zeit);

   /* Insertionsort */
      init_test_array3(elemente);  start = clock();
      insertion(test_array, elemente-1);  ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Insertionsort: %.2f Sekunden\n",zeit);

   /* Bubblesort */
      init_test_array3(elemente);  start = clock();
      bubble(test_array, elemente);  ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Bubblesort   : %.2f Sekunden\n",zeit);

   /* Shellsort */
      init_test_array3(elemente);  start = clock();
      shellsort(test_array, elemente-1);  ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Shellsort    : %.2f Sekunden\n",zeit);

   /* Quicksort */
      init_test_array3(elemente);  start = clock();
      my_qsort(test_array,test_array+elemente);   ende = clock(); 
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("Quicksort    : %.2f Sekunden\n",zeit);

   /* qsort aus der Standard-Bibliothek <stdlib.h> */  
      init_test_array3(elemente);  start = clock();
      qsort(test_array, elemente, sizeof(int), cmp_integer);
      zeit = (float)(ende-start) / (float)CLOCKS_PER_SEC;
      printf("qsort        : %.2f Sekunden\n",zeit);
   }/* Ende for */
   return EXIT_SUCCESS;
}


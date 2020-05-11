/* ptr_versus_array2.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int n=3;
   /* eindim. Array mit Platz für 5 Werte*/
   int array[5]={ 1,2,3,4,5 };
   /* int-Zeiger verweist jetzt auf array[0] */
   int *ptr = array;

   /* 4 Möglichkeiten, um auf das erste Element zuzugreifen */
   printf("%d " , *ptr);
   printf("%d ", ptr[0]);
   printf("%d ", *array);
   printf("%d\n", array[0]);
   /* 4 Möglichkeiten, um auf das n-te Element zuzugreifen */
   printf("%d " , *(ptr+n));
   printf("%d ", ptr[n]);
   printf("%d ", *(array+n));
   printf("%d\n", array[n]);   
   /* 4 Möglichkeiten, um auf die Anfangsadresse zuzugreifen */
   printf("%p " , ptr);
   printf("%p ", &ptr[0]);
   printf("%p ", array);
   printf("%p\n", &array[0]);
   /* 4 Möglichkeiten, um auf die Adresse des n-ten Elements
      zuzugreifen */
   printf("%p " , ptr+n);
   printf("%p ", &ptr[n]);
   printf("%p ", array+n);
   printf("%p\n", &array[n]);   
   return EXIT_SUCCESS;
}


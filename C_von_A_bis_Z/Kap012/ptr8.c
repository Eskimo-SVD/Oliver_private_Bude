/* ptr8.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int wert=10;
   int *ptr1;
   int *ptr2;

   ptr1 = &wert;
   ptr2 = ptr1;

   printf("ptr1 verweist auf %p\n", ptr1);
   printf("Wert in %p ist %d\n\n", ptr1, *ptr1);

   printf("ptr2 verweist auf %p\n", ptr2);
   printf("Wert in %p ist %d\n\n", ptr2, *ptr2);
   
   printf("Adresse von ptr1 : %p\n", &ptr1);
   printf("Adresse von ptr2 : %p\n", &ptr2);
   printf("Adresse von wert : %p\n\n", &wert);
   
   printf("ptr1 [%p] -> [%p] = [%d]\n", &ptr1, ptr1, *ptr1);
   printf("ptr2 [%p] -> [%p] = [%d]\n", &ptr2, ptr2, *ptr2);
   return EXIT_SUCCESS;
}


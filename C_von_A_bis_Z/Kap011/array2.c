/* array2.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int test[10];
   int i;

   for(i = 0; i <= 10; i++)  /*  !!Bereichsüberschreitung!! */
      test[i] = i;
   for(i = 0; i <= 10; i++)
      printf("%d, ", test[i]);
   printf("\n");
   return EXIT_SUCCESS;
}


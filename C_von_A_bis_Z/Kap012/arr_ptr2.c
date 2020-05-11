/* arr_ptr2.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int element[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
   int i;

   printf("*element     = %d\n", *element);
   printf("*(element+1) = %d\n", *(element+1));
   printf("*(element+3) = %d\n", *(element+3));

   printf("\nJetzt alle zusammen : \n");
   for(i=0; i<8; i++)
      printf("*(element+%d) = %d \n", i, *(element+i));
   return EXIT_SUCCESS;
}


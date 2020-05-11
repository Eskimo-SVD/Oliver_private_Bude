/* array9.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int zahlen[] = {3,6,3,5,6,3,8,9,4,2,7,8,9,1,2,4,5};

   printf("Anz. Elemente : %d\n", sizeof(zahlen) / sizeof(int));
   return EXIT_SUCCESS;
}


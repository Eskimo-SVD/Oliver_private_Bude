/* array3.c */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main(void) {
   int zahlen[SIZE] = { 0 };

   printf("Anz. Elemente : %d\n", sizeof(zahlen) / sizeof(int));
   return EXIT_SUCCESS;
}


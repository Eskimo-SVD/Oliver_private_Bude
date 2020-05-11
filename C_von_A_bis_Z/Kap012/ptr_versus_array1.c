/* ptr_versus_array1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int var[] = { 123, 456, 789};
   
   printf("*var : %d; var[0] : %d\n", *var, var[0]);
   return EXIT_SUCCESS;
}


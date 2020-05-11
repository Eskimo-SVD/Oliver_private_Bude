/* ptr10.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int *int_ptr;
   double double_wert=999.999;

   int_ptr=&double_wert;
   printf("*int_ptr=%d double=%f\n", *int_ptr, double_wert);
   return EXIT_SUCCESS;
}


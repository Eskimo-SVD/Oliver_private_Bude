/* division.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   div_t x = div(10,3);

   printf("10 div 3 = %d Rest %d\n",  x.quot, x.rem);
   return EXIT_SUCCESS;
}


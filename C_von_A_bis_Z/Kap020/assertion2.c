/* assertion2.c */
#include <stdio.h>
#include <stdlib.h>
#define NDEBUG
#include <assert.h>

int divide(int zahl1, int zahl2) {
   assert( (zahl1 >= 0 && zahl1 >= zahl2) && (zahl2 >= 0) );
   return zahl1 / zahl2;
}

int main(void) {
   printf("%d / %d = %d\n",5,2,divide(5,2));
   printf("%d / %d = %d\n",3,4,divide(3,4));
   printf("%d / %d = %d\n",4,4,divide(4,4));
   return EXIT_SUCCESS;
}


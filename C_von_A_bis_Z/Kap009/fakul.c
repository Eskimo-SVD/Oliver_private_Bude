/* fakul.c */
#include <stdio.h>
#include <stdlib.h>

long fakul(long n) {
   if(n)
      return n * fakul(n-1);
   return 1;
}

int main(void) {
   printf("Fakult�t von 5 = %ld\n",fakul(5));
   printf("Fakult�t von 9 = %ld\n",fakul(9));
   return EXIT_SUCCESS;
}


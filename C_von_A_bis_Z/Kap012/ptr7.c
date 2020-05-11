/* ptr7.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char   *v;
   int    *w;
   float  *x;
   double *y;
   void   *z;

   printf("%d\t %d\t %d\t %d\t %d \n",
      sizeof(v),sizeof(w), sizeof(x), sizeof(y), sizeof(z));
   return EXIT_SUCCESS;
}


/* enum1.c */
#include <stdio.h>
#include <stdlib.h>

enum zahl { NU_LL, EINS, ZWEI, DREI, VIER};

int main(void) {
   enum zahl x;
   x=NU_LL;
   printf("%d\n",x);

   x=EINS;
   printf("%d\n",x);

   x=ZWEI;
   printf("%d\n",x);

   x=DREI;
   printf("%d\n",x);

   x=VIER;
   printf("%d\n",x);
   return EXIT_SUCCESS;
}


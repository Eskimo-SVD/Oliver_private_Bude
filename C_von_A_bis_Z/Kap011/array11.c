/* array11.c */
#include <stdio.h>
#include <stdlib.h>

struct array{ int wert[3]; };

void output_array(struct array z) {
   int i;

   for(i = 0; i < sizeof(struct array) / sizeof(int); i++)
      printf("%d\t", z.wert[i]);
   printf("\n");
}

int main(void) {
   struct array new_array;

   new_array.wert[0] = 10;
   new_array.wert[1] = 20;
   new_array.wert[2] = 30;

   /* call-by-value */
   output_array(new_array);
   return EXIT_SUCCESS;
}


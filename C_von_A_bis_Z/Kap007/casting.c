/* casting.c */
#include <stdio.h>

int main(void) {
   int x = 5, y = 2;
   float z;

   z = x / y;
   printf("%f\n", z);          /* = 2.000000 */
   z = (float) x / (float) y;    /* = 2.500000 */
   printf("%f\n", z);
   return 0;
}


/* for9.c */
#include <stdio.h>

int main(void) {
   int x = 2, y;

   for(y=2; x<20;) {
         x = x * y;
         printf("%d\n", x++);
   }
   return 0;
}


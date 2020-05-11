/* shift_left.c */
#include <stdio.h>

int main(void) {
   char x=8;

   printf("x=%d\n",x);
   x<<=1;        // Alle Bits um 1 Stelle nach links
   printf("x=%d\n",x);
   return 0;
}


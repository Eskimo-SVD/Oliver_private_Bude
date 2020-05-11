/* and.c */
#include <stdio.h>

int main(void) {
   int x=55;
   printf("x=%d\n",x);
   x= x&7;
   printf("x=%d\n",x);  /* x=7 */
   return 0;
}


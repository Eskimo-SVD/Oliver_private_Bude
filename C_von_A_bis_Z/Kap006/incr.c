/* incr.c */
#include <stdio.h>

int main(void) {
   int i=1;

   printf("i=%d\n",i);         // i=1
   i++;
   printf("i=%d\n",i);         // i=2
   printf("i=%d\n",i++);       // i=2
   printf("i=%d\n",i);         // i=3
   printf("i=%d\n",++i);       // i=4
   return 0;
}

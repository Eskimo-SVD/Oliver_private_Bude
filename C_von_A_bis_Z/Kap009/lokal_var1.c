/* lokal_var1.c */
#include <stdio.h>

int main(void) {
   int i = 333;

   if(i == 333) {
     int i = 111;
     printf("%d\n",i);  /* 111 */
   }
   printf("%d\n",i);    /* 333 */
   return 0;
}


/* lokal_var2.c */
#include <stdio.h>

int main(void) {
   int i = 333;

   if(i == 333) {
      i = 111;
      printf("%d\n",i);  /* 111 */
   }
   printf("%d\n",i);     /* 111 */
   return 0;
}


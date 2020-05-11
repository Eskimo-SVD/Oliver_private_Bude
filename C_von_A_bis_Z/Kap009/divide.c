/* divide.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int x = 8, y = 2;
   printf("%d ", x/y);
   if(x % y)
      printf("Rest = %d\n",x%y);
   return EXIT_SUCCESS;
}


/* for8.c */
#include <stdio.h>

int main(void) {
   int x,y=50;
   for(x = 0; y <= 75; y = (++x*5) + 50)
      printf("%d\n", y);
   return 0;
}


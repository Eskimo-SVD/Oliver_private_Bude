/* for7.c */
#include <stdio.h>

int main(void) {
   double zs;
   for(zs = 100.0; zs < 150.0; zs = zs * 1.1)
      printf("%.2f\n", zs);
   return 0;
}


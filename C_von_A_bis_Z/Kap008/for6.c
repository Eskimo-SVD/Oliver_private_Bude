/* for6.c */
#include <stdio.h>

int main(void) {
   int cube;

   for(cube = 1; cube * cube * cube <= 216; cube++)
      printf("n=%d Volumen : %d \n", cube, cube*cube*cube);
   return 0;
}


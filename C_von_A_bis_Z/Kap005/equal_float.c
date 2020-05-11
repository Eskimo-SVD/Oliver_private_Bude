/* equal_float.c */
#include <stdio.h>

int main(void) {
   float i=0.0;
   for (i=0.0; i<0.9999 || i>1.0001; i += 0.1)
      printf("%f",i);
   return 0;
}


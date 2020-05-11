/* never_ending.c */
#include <stdio.h>

int main(void) {
   float i=0.0;
   for (i=0.0; i != 1.0; i += 0.1)
      printf("%f",i);
   return 0;
}


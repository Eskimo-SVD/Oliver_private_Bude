/* inliner.c */
#include <stdio.h>
#include <stdlib.h>
#include "inline.h"

inline void xchange(int *z1, int *z2) {
   int tmp;

   tmp  = *z2;
   *z2  = *z1;
   *z1  = tmp;
}

inline void print(int *z1, int *z2) {
   printf("%d :: %d\n", *z1, *z2);
}

int main(void) {
   int zahl1 = 123, zahl2 = 321;
  
   print(&zahl1, &zahl2);
   xchange(&zahl1, &zahl2);
   print(&zahl1, &zahl2);
   return EXIT_SUCCESS;
}




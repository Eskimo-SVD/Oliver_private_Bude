/* undef.c */
#include <stdio.h>
#include <stdlib.h>
#define NUM 10

int main(void) {
   printf("Wert für symb. Konstante NUM: %d\n",NUM); /* 10 */

#ifdef NUM
   #undef NUM   /* symb. Konstante aufheben */
#endif

#define NUM 100 /* symb. Konstante wieder neu definieren */

   printf("Wert für symb. Konstante NUM: %d\n",NUM); /* 100 */
   return EXIT_SUCCESS;
}


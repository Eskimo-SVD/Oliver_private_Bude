/* flexibel.c */
#include <stdio.h>
#include <stdlib.h>
#define LEN 10

typedef struct { int len; int iarray[]; } Vint_t;

int main(void) {
   Vint_t *Viptr = malloc ( sizeof( Vint_t) + LEN*sizeof( int ) );
   Viptr->len = LEN;
   for( int i = 0; i < Viptr->len; i++ )
      Viptr->iarray[i] = i*i;

   for( int i = 0; i < Viptr->len; i++ )
      printf("Viptr->iarray[%d]: %3d\n",i ,Viptr->iarray[i]);

   return EXIT_SUCCESS;
}

/* malloc3.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   double *p1,*p2;

   p1 = malloc(sizeof(p1)); // Fehler
   p2 = malloc(sizeof(p2)); // Fehler

   if(p1 != NULL && p2 != NULL) {
         *p1 = 5.15;
         printf("p1 = %f\n",*p1);
         *p2 = 10.99;
         printf("p2 = %f\n",*p2);
      }
   return EXIT_SUCCESS;
}


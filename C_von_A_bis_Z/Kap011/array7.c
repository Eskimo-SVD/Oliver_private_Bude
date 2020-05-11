/* array7.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int main(void) {
   int i;
   int array1[MAX];
   int array2[MAX];

   for(i = 0; i < MAX; i++) {
         array1[i] = i;
         array2[i] = i;
   }
   array2[5] = 100; /* Verändert array2 an Pos. 5 */

   if(memcmp(array1, array2, sizeof(array1)) == 0 )
      printf("Beide Arrays haben den gleichen Inhalt\n");
   else
      printf("Die Arrays sind unterschiedlich\n");
   return EXIT_SUCCESS;
}



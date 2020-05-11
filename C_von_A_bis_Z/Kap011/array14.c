/* array14.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main(void) {
   int i;
   int array[MAX];

   for(i = 0; i < MAX; i++) {
      printf("%d. Zahl > ", i+1);
      scanf("%d", &array[i]);
   }
   printf("Sie haben eingegeben: ");
   for(i = 0; i < MAX; i++)
      printf("%d ", array[i]);
   printf("\n");
   return EXIT_SUCCESS;
}


/* continue1.c */
#include <stdio.h>

int main(void) {
   int i;

   for(i = 1; i <= 20; i++) {
     if(i % 2)        /* Rest bedeutet ungerade Zahl */
        continue;     /* printf überspringen         */
     printf("%d ", i);
   }
   printf("\n");
   return 0;
}


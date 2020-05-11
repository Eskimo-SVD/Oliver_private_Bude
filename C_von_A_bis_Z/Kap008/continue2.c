/* continue2.c */
#include <stdio.h>

int main(void) {
   int i=2;

   while(i <= 10) {
      if(i % 2)        /* Rest bedeutet ungerade Zahl */
         continue;     /* printf überspringen         */
      printf("%d ", i);
      i++;
   }
   return 0;
}


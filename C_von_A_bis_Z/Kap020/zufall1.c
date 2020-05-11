/* zufall1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int zufallszahl, i;

   for(i = 0; i < 5; i++)
      printf("Die Zufallszahl lautet %d\n", zufallszahl=rand());
   return EXIT_SUCCESS;
}


/* zufall3.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   int zufallszahl, i;

   srand(time(NULL));
   for(i = 0; i < 5; i++)
      printf("Zufallszahl lautet %d\n", zufallszahl=rand()%10+1);
   return EXIT_SUCCESS;
}


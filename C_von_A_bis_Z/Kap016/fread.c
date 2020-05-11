/* fread.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int puffer[10];
   FILE *quelle;
   int i;

   quelle = fopen("wert.dat", "r+b");
   if(quelle != NULL)
      fread(&puffer, sizeof(int), 10, quelle);

   for(i = 0; i < 10; i++)
      printf("Wert %d = %d\n", i, puffer[i]);
 return EXIT_SUCCESS;
}


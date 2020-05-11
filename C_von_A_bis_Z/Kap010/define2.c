/* define2.c */
#include <stdio.h>
#include <stdlib.h>
#define KLEINER_100(x) ((x) < 100)

void klHundert(int zahl) {
   if(KLEINER_100(zahl))
      printf("Ja! Die Zahl ist kleiner als 100!\n");
   else
      printf("Die Zahl ist größer als 100!\n");
}

int main(void) {
   int b = 99;

   klHundert(b);
   return EXIT_SUCCESS;
}


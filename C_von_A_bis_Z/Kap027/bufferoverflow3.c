/* bufferoverflow3.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funktion(int temp,char *array) {
   char puffer[5];

   strcpy(puffer, array);
   printf("%s\n",puffer);
}

int main(void) {
   int wert;

   wert=0;
   funktion(7,"hallo");
   wert=1;
   printf("%d\n",wert);
}


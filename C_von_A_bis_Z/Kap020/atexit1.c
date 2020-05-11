/* atexit1.c */
#include <stdio.h>
#include <stdlib.h>

void funktion1(void) {
   printf("Die Funktion funktion1 wurde aufgerufen\n");
}

void funktion2(void) {
   printf("Die Funktion funktion2 wurde aufgerufen\n");
}

int main(void) {
   atexit(funktion1);
   atexit(funktion2);
   printf("Wir beenden unser Programm\n");
   exit(EXIT_FAILURE);
   printf("Dies wird nicht mehr ausgegeben\n");
   return EXIT_SUCCESS;
}


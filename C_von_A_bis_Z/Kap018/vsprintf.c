/* vsprintf.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/*  Bei Linux Bibliothek math.h extra hinzulinken (-lm)
 *  gcc -o programm programm.c -lm
 */
#include <math.h>

static void float2string(char *string, char *dezimal, ...) {
   va_list argzeiger;
   va_start(argzeiger,dezimal);
   vsprintf(string,dezimal,argzeiger);
   va_end(argzeiger);
}

int main(void) {
   char string[100];
   float zahl = 20.0;

   float2string(&string[0],"string-> %.6f <-string",sqrt(zahl));
   printf("%s\n",string);
   return EXIT_SUCCESS;
}


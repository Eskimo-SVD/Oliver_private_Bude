/* my_printf.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static void myprintf(char *string, ...) {
   va_list argzeiger;
   va_start(argzeiger,string);
   vprintf(string,argzeiger);
   va_end(argzeiger);
}

int main(void) {
   char hallo[] = "Hallo vprintf\n";
   myprintf("Hier ein Beispiel von vprintf....");
   myprintf("\n");
   myprintf("%d * %d = %d\n",10,10,10*10);
   myprintf("%s",hallo);
   return EXIT_SUCCESS;
}


/* ptr_func3.c */
#include <stdio.h>
#include <stdlib.h>
#define INPUT  0
#define OUTPUT 1

int main(void) {
   int (*ptr[])(const char *, ...) = { scanf, printf };
   int zahl;

   (*ptr[OUTPUT])("Bitte eine Zahl eingeben: ");
   (*ptr[INPUT])("%d",&zahl);

   (*ptr[OUTPUT])("Die Zahl lautet %d\n",zahl);
   return EXIT_SUCCESS;
}


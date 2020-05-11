/* ptr_func2.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int (*ptr)(const char*, ...);
   int zahl;

   ptr=printf; 
   (*ptr)("Bitte eine Zahl eingeben: ");
   ptr=scanf;
   (*ptr)("%d",&zahl);
   ptr=printf;
   (*ptr)("Die Zahl lautet %d\n",zahl);
   return EXIT_SUCCESS;
}


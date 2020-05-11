/*main.c*/
#include <stdio.h>
#include <stdlib.h>

extern void modul1(void);
extern void modul2(void);

int main(void) {
   modul1();
   modul2();
   return EXIT_SUCCESS;
}


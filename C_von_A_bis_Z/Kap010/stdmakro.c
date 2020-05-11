/* stdmakro.c */
#include <stdio.h>
#include <stdlib.h>

void eine_funktion(void) {
   printf("Name der Funktion: %s\n",__func__);
}

int main(void) {
   eine_funktion();
   return EXIT_SUCCESS;
}

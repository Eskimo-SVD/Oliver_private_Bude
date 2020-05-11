/* str_ptr1.c */
#include <stdio.h>
#include <stdlib.h>

void funktion(char *str) {
   printf("%s\n",str);
}

int main(void) {
   char *string = "Hallo Welt";

   funktion(string);
   printf("Anfangsadresse auf die *string zeigt = %p\n",*string);
   printf("Der Inhalt dieser Anfangsadresse     = %c\n",*string);
   return EXIT_SUCCESS;
}


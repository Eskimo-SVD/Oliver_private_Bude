/* echo_wchar.c */
#include <stdlib.h>
#include <wchar.h>

int main(void) {
   wint_t c;

   while( (c = getwchar()) != L'.')
      putwchar(c);
   return EXIT_SUCCESS;
}


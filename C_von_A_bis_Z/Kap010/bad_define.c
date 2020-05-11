/* bad_define1.c */
#include <stdio.h>
#include <stdlib.h>
#define VIEL_TEXT "TextTextTextTextTextTextTextTextTextText"\
                  "TextTextTextTextTextTextTextTextTextText"\
                  "TextTextTextTextTextTextTextTextTextText"\
                  "TextTextTextTextTextTextTextTextTextText\n"

int main(void) {
   printf(VIEL_TEXT);
   printf(VIEL_TEXT);
   printf(VIEL_TEXT);
   return EXIT_SUCCESS;
}


/* without_define.c */
#include <stdio.h>
#include <stdlib.h>

void viel_text(void) {
   printf("TextTextTextTextTextTextTextTextTextText"\
          "TextTextTextTextTextTextTextTextTextText"\
          "TextTextTextTextTextTextTextTextTextText"\
          "TextTextTextTextTextTextTextTextTextText\n");
}

int main(void) {
   viel_text();
   viel_text();
   viel_text();
   return EXIT_SUCCESS;
}


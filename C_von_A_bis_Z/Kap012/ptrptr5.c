/* ptrptr5.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char *text[500];
   char str1[] = "Text1";
   char str2[] = "Text2";
   char str3[] = "Text3";

   text[0] = str1;
   text[1] = str2;
   text[2] = str3;

   printf("%s %s %s\n", text[0], text[1], text[2]);
   return EXIT_SUCCESS;
}


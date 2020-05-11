/* strpbrk.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char str1[]="Das ist ein Teststring";
   char str2[]="ie";

   printf("%s\n",strpbrk(str1, str2));
   return EXIT_SUCCESS;
}


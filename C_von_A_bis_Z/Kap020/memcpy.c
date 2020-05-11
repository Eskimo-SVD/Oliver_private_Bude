/* memcpy.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char str[] = "Ein Wort was hier nicht hingehört: Mist!";
   char replace[] = "M***";
   char *ptr;

   ptr = strstr(str, "Mist");
   memcpy(ptr, replace, strlen(replace)); 
   printf("%s\n",str); 
   return EXIT_SUCCESS;
}


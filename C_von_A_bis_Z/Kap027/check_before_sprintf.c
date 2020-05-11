/* check_before_sprintf.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

void check_bevore_sprintf(char *quelle, int max) {
   if(strlen(quelle) < MAX)
      return;
   else
      abort(); /* abort zum Debugger */
}

int main(void) {
   char *ptr1 = "123456789";
   char *ptr2 = "1234567890";  
   char string[MAX]; 
   
   check_bevore_sprintf(ptr1, MAX);
   sprintf(string, "%s", ptr1);
   printf("string: %s\n", string);
   
   /* Boom!!! */
   check_bevore_sprintf(ptr2, MAX);
   sprintf(string, "%s", ptr2);
   printf("string: %s\n", string);
   
   return EXIT_SUCCESS;
}


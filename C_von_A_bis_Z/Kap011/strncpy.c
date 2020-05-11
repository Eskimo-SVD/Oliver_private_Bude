/* strncpy.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int main(void) {
   char str1[MAX];
   char str2[] = "Ein Teststring welcher laenger"
                 " als 20 Zeichen ist";

   /* MAX-Zeichen in str1 kopieren */
   strncpy(str1, str2, MAX-1);
   /* Wichtig, String am Ende terminieren !! */
   str1[MAX-1] = '\0';
   printf("%s\n",str1);
   return EXIT_SUCCESS;
}


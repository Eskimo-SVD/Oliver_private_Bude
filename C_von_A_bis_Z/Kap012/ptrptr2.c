/* ptrptr2.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char *sort[] = {
      "Zeppelin", "Auto", "Amerika", "Programmieren"
    };

   printf("%s\n", sort[1]);                 /* Auto       */
   printf("%s ", (sort[2]+2));              /* erika      */
   printf("%s %s\n", (sort[0]+6), sort[2]); /* in Amerika */
   printf("%.5s\n", (sort[3]+5-2));         /* gramm      */
   return EXIT_SUCCESS;
}


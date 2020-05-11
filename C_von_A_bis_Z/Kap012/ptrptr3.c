/* ptrptr3.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char *sort[] = {
      "Zeppelin", "Auto", "Amerika", "Programmieren"
    };
   printf("%p = %c\n", **sort, **sort);
   printf("%p = %c\n", *sort[0], *sort[0]);
   printf("%p = %c\n", *(sort[0]+0), *(sort[0]+0));

   printf("%p = %s\n", sort[0], sort[0]);
   printf("%p = %s\n", *sort, *sort);

   printf("%p = %s\n", (sort[0]+1), (sort[0]+1));
   printf("%p = %s\n", (sort[0]+2), (sort[0]+2));

   printf("*sort = %p, **sort = %p\n", *sort, **sort);
   return EXIT_SUCCESS;
}


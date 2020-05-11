/* if1.c */
#include <stdio.h>

int main(void) {
   unsigned int alter;

   printf("Wie alt sind Sie: ");
   scanf("%u", &alter);
   /* ... noch jünger als 18? */
   if(alter < 18) {
      printf("Sie sind noch nicht volljährig\n");
   }
    printf("Bye\n");
    return 0;
}


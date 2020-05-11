/* fflush.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char x,y;

   printf("Bitte einen Buchstaben eingeben : ");
   scanf("%c",&x);
   fflush(stdin);
   printf("Bitte noch einen Buchstaben eingeben : ");
   scanf("%c",&y);
   printf("Sie gaben ein %c und %c \n",x,y);
   return EXIT_SUCCESS;
}


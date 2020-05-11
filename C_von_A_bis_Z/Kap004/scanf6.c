/* scanf6.c */
#include <stdio.h>

int main(void) {
   char a;
   int b,check;

   printf("Bitte Eingabe machen (Zeichen/Zahl): ");
   check=scanf("%c %d",&a,&b);
   printf("Check = %d \n",check);
   return 0;
}


/* scanf3.c */
#include <stdio.h>

int main(void) {
   char a,b,c;
   printf("1. Buchstabe : ");
   scanf("%c",&a);
   fflush(stdin);
   printf("2. Buchstabe : ");
   scanf("%c",&b);
   fflush(stdin);
   printf("3. Buchstabe : ");
   scanf("%c",&c);
   printf("Sie gaben ein : %c %c %c ",a,b,c);
   return 0;
}


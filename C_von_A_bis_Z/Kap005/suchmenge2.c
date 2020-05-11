/* suchmenge2.c */
#include <stdio.h>

int main(void) {
   char str[20];
   printf("Eingabe machen (keine Buchstaben wie x,y und z): ");
   scanf("%19[^xyz]", str);
   printf("%s\n",str); 
   return 0;
}


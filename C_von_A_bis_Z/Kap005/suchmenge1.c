/* suchmenge1.c */
#include <stdio.h>

int main(void) {
   char str[20];
   printf("Bitte geben Sie nur Zahlen ein: ");
   scanf("%[0-9]", str);
   printf("%s\n",str); 
   return 0;
}


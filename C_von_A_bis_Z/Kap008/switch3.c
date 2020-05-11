/* switch3.c */
#include <stdio.h>

int main(void) {
   int a,b;
   char opera;
   printf("Grundrechnen \n");
   printf(" (zahl)(Operator)(zahl) ohne Leerzeichen \n");

   printf("Rechnung bitte eingeben : ");
   scanf("%d%c%d", &a, &opera, &b); /* Bsp.: 10+12 */

   switch(opera) {
      case '+': printf("%d + %d = %d \n",a ,b ,a+b);
                break;
      case '-': printf("%d - %d = %d \n", a, b, a-b);
                break;
      case '*': printf("%d * %d = %d \n", a, b, a*b);
                break;
      case '/': printf("%d / %d = %d \n", a, b, a/b);
                break; 
      default: printf("%c? kein Rechenoperator \n", opera);
      }      /* Ende switch */
 return 0;
}


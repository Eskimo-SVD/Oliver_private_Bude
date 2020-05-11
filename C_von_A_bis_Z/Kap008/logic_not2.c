/* logic_not2.c */
#include <stdio.h>

int main(void) {
   int zahl1, zahl2;

   printf("Bitte Zahl 1 eingeben: ");
   scanf("%d", &zahl1);
   printf("Bitte Zahl 2 eingeben: ");
   scanf("%d", &zahl2);

   if(!zahl1)
      printf("Error: Der Wert ist gleich 0!! \n");
   else if(!zahl2)
      printf("Error: Der Wert ist gleich 0!! \n");
   else
      printf("%d/%d = %f \n", zahl1, zahl2, (float) zahl1/zahl2);
   return 0;
}

